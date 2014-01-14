//
//  StringParser.h
//  ZingBDD
//
//  Created by Dave Meehan on 07/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef ZingBDD_StringParser_h
#define ZingBDD_StringParser_h

#include <set>
#include <memory>

#include "Scanner.h"
#include "CharacterSet.h"

namespace StringCalculator {
    
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
            
            parseDelimiterSpecification();
            
            parseNumbersAndDelimiters();
            
            return _container;
            
        }
        
    protected:
        
        bool atEnd() {
            
            return _pScanner->atEnd();
            
        }
        
        void parseDelimiterSpecification() {
            
            string_type guard = "//";
            if (_pScanner->scan(guard.begin(), guard.end(), nullptr)) {
                
                CharacterSet terminator("\n");
                string_type delims;
                
                if (_pScanner->scanUpTo(terminator, &delims)) {
                    
                    if (_pScanner->scan(terminator, nullptr)) {
                        
                        _singleCharacterDelimiters = delims;
                        
                        return;
                        
                    } else {
                        
                        throw std::runtime_error("Expected delimiter terminator");
                        
                    }
                    
                } else {
                    
                    throw std::runtime_error("Expected delimiters");
                    
                }
                
            }
            
        }
        
        void parseNumbersAndDelimiters() {
            
            while ( ! atEnd() ) {
                
                value_type value;
                
                if (parseNumber(value)) {
                    
                    _container.push_back(value);
                    
                    if ( ! atEnd() && ! parseDelimiters() ) {
                        
                        throw std::runtime_error("Expected delimiter");
                        
                    }
                    
                } else {
                    
                    throw std::runtime_error("Expected number");
                    
                }
            }

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
            
            string_type::value_type value;
            
            return _pScanner->scan(_singleCharacterDelimiters, value);
            
        }
        
    private:
        
        container_type _container;
        std::shared_ptr<scanner_type> _pScanner;
        CharacterSet _singleCharacterDelimiters;
        
    };

}

#endif
