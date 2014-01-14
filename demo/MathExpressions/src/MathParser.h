//
//  MathParser.h
//  ZingBDD
//
//  Created by Dave Meehan on 14/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef ZingBDD_MathParser_h
#define ZingBDD_MathParser_h

#include "demo/StringCalculator/src/Scanner.h"
#include "demo/StringCalculator/src/CharacterSet.h"

namespace MathExpressions {
    
    class Node {

    public:
        using pointer_type = std::shared_ptr<Node>;
        
        virtual int getValue() { return 0; };
        virtual bool addNode(pointer_type node) {
            return false;
        }
    };
    
    class ValueNode : public Node {
        
    public:
        ValueNode(int value) : _value(value) {}
        
        virtual int getValue() override {
            return _value;
        }
        
    private:
        
        int _value;
        
    };
    
    class OperatorNode : public Node {

    public:
        
        OperatorNode(pointer_type left, pointer_type right) : _left(left), _right(right) {}
        
        pointer_type left() const {
            return _left;
        }
        
        pointer_type right() const {
            return _right;
        }
        
        bool addNode(pointer_type node) {
            
            if (_left == nullptr) {
                _left = node;
            } else if (_right == nullptr) {
                _right = node;
            } else {
                return false;
            }
            return true;
        }
        
    private:
        pointer_type _left;
        pointer_type _right;

    };

    class AddNode : public OperatorNode {
        
    public:
        AddNode(pointer_type left, pointer_type right) : OperatorNode(left, right) {}
        
        virtual int getValue() override {
            
            return left()->getValue() + right()->getValue();
            
        }
    };
    
    class MinusNode : public OperatorNode {
        
    public:
        MinusNode(pointer_type left, pointer_type right) : OperatorNode(left, right) {}
        
        virtual int getValue() override {
            
            return left()->getValue() - right()->getValue();
            
        }
    };
    class MathParser {
        
    public:
        using string_type = std::string;
        using scanner_type = StringCalculator::Scanner<string_type, string_type>;
        
        int parse(string_type string) {
            
            _scanner = std::make_shared<scanner_type>(string);

            parseExpression();
        
            return evaluateExpression();
            
        }

        void parseExpression() {
            
            while ( ! _scanner->atEnd()) {
                
                int value;
                if (parseNumber(value)) {
                    
                    if (_node == nullptr) {
                        
                        _node = std::make_shared<ValueNode>(value);
                        
                    } else {
                        
                        if ( ! _node->addNode(std::make_shared<ValueNode>(value))) {
                            
                            throw std::runtime_error("Unexpected number");
                            
                        }
                        
                    }
                    
                    if ( ! _scanner->atEnd() && ! parseOperator()) {
                        
                        throw std::runtime_error("Expected operator");
                        
                    }
        
                } else {
                    throw std::runtime_error("Expected number");
                }
            }

        }
        
        int evaluateExpression() {
            
            if (_node != nullptr) {
                return _node->getValue();
            }
            return 0;
        }
        
        bool parseNumber(int &value) {
            
            StringCalculator::CharacterSet digits("0123456789");
            string_type stringOfDigits;
            
            if (_scanner->scan(digits, &stringOfDigits)) {
                
                value = std::stoi(stringOfDigits);
                return true;
            }
            
            return false;
        }
        
        bool parseOperator() {
            
            StringCalculator::CharacterSet operators("+-");
            
            string_type op;
            
            if (_scanner->scan(operators, &op)) {
                
                std::shared_ptr<Node> opNode;
                
                switch (op[0]) {
                    case '+':
                        opNode = std::make_shared<AddNode>(_node, nullptr);
                        break;

                    case '-':
                        opNode = std::make_shared<MinusNode>(_node, nullptr);
                        break;

                    default:
                        break;
                }
                _node = opNode;
                return true;
            }
            return false;
        }
        
    private:
        
        std::shared_ptr<scanner_type> _scanner;
        std::shared_ptr<Node> _node;
        
    };
}

#endif
