//
//  RomanNumerals.h
//  ZingBDD
//
//  Created by Dave Meehan on 14/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef ZingBDD_RomanNumerals_h
#define ZingBDD_RomanNumerals_h

namespace RomanNumerals {
    
    class RomanNumerals {
        
    public:
        
        struct ConversionTable {
            int decimal;
            std::string roman;
        };
        
        std::string roman( int decimal ) {
        
            std::vector<struct ConversionTable> conversionTable = {
                {   1000,       "M"         },
                {   900,        "CM"        },
                {   500,        "D"         },
                {   400,        "CD"        },
                {   100,        "C"         },
                {   90,         "XC"        },
                {   50,         "L"         },
                {   40,         "XL"        },
                {   10,         "X"         },
                {   9,          "IX"        },
                {   5,          "V"         },
                {   4,          "IV"        },
                {   1,          "I"         },
                
            };
            std::string result;
            
            while (decimal > 0) {
                
                for ( auto conversion : conversionTable ) {
                    
                    if (decimal >= conversion.decimal) {
                        
                        result += conversion.roman;
                        decimal -= conversion.decimal;
                        break;
                        
                    }
                    
                }
                
            }
            
            return result;
        }
        
    };
}

#endif
