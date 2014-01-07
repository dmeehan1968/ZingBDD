//
//  StringParser.h
//  RSpeCpp
//
//  Created by Dave Meehan on 07/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef RSpeCpp_StringParser_h
#define RSpeCpp_StringParser_h

#include <set>

#include "Scanner.h"

namespace StringCalculator {
    
    class CharacterSet : public std::set<char> {
      
    public:
        
        CharacterSet(const std::string initial) : std::set<char>(initial.begin(), initial.end()) {}
        
        static CharacterSet decimalDigitCharacterSet() {
            
            return CharacterSet("0123456789");
            
        }
    };
    
    class CalculatorParser {
        
    public:
        using string_type = std::string;
        using container_type = std::vector<int>;
        using value_type = container_type::value_type;
        using scanner_type = Scanner<string_type, string_type>;
        
        CalculatorParser() : _singleCharacterDelimiters(",\n") {}
        
        container_type parse(const string_type &stringToParse) {
        
            _pScanner = std::make_shared<scanner_type>(stringToParse);

            _container.clear();
            
            while ( ! atEnd() ) {

                value_type value;
                
                if (parseNumber(value)) {

                    _container.push_back(value);

                    if ( ! atEnd() && ! parseDelimiters() ) {
                        
                        throw std::runtime_error("Invalid input");
                        
                    }
                    
                }
            }
            
            return _container;
            
        }
        
    protected:
        
        bool atEnd() {
            
            return _pScanner->atEnd();
            
        }
        
        bool parseNumber(value_type &value) {
            
            string_type stringOfDigits;
            
            if (_pScanner->scan(CharacterSet::decimalDigitCharacterSet(), &stringOfDigits)) {
                
                value = (value_type) std::stol(stringOfDigits);
                
                return true;
            }

            return false;
            
        }
        
        bool parseDelimiters() {
            
            if (_pScanner->scan(_singleCharacterDelimiters, nullptr)) {
                
                return true;
                
            }
            
            return false;
            
        }
        
    private:
        
        container_type _container;
        std::shared_ptr<scanner_type> _pScanner;
        CharacterSet _singleCharacterDelimiters;
        
    };

}

#endif
