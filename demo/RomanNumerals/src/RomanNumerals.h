//
//  RomanNumerals.h
//  ZingBDD
//
//  Created by Dave Meehan on 14/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//
//  This software is released under the terms of the:
//
//  GNU GENERAL PUBLIC LICENSE
//  Version 3, 29 June 2007
//
//  Please read LICENSE.md for full terms and conditions.
//

#ifndef ZingBDD_RomanNumerals_h
#define ZingBDD_RomanNumerals_h

namespace RomanNumerals {
    
    class RomanNumerals {
        
    public:
        
        struct ConversionTable {
            int arabic;
            std::string roman;
        };
        
        std::string roman( int arabic ) {
        
            if (arabic < 1 || arabic > 3999) {
                throw std::range_error("Arabic should be in range 1 to 3999");
            }
            
            std::string result;
            char romanNumerals[] = "IVXLCDM";
            int index = 0;
            
            while (arabic > 0) {

                int mod = arabic % 10;
                
                if (mod == 9) {
                    
                    result.insert(0, 1, romanNumerals[index+2]);
                    result.insert(0, 1, romanNumerals[index]);
                    
                } else if (mod >= 5) {
                    
                    result.insert(0, mod % 5, romanNumerals[index]);
                    result.insert(0, 1, romanNumerals[index+1]);
                    
                } else if (mod == 4) {
                        
                    result.insert(0, 1, romanNumerals[index+1]);
                    result.insert(0, 1, romanNumerals[index]);
                        
                } else {
                        
                    result.insert(0, mod, romanNumerals[index]);
                    
                }

                index += 2;
                arabic /= 10;
                
            }
            
            return result;
        }
        
    };
}

#endif
