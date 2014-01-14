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
        
        std::string roman( int decimal ) {
        
            std::string result;
            
            while (decimal > 0) {
                
                if (decimal >= 1000) {
                    
                    result += "M";
                    decimal -= 1000;
                    
                } else if (decimal >= 900) {
                    
                    result += "CM";
                    decimal -= 900;
                    
                } else if (decimal >= 500) {
                    
                    result += "D";
                    decimal -= 500;
                    
                } else if (decimal >= 400) {
                    
                    result += "CD";
                    decimal -= 400;
                    
                } else if (decimal >= 100) {
                    
                    result += "C";
                    decimal -= 100;
                    
                } else if (decimal >= 90) {
                    
                    result += "XC";
                    decimal -= 90;
                    
                } else if (decimal >= 50) {
                    
                    result += "L";
                    decimal -= 50;
                    
                } else if (decimal >= 40) {
                    
                    result += "XL";
                    decimal -= 40;
                    
                } else if (decimal >= 10) {
                    
                    result += "X";
                    decimal -= 10;
                    
                } else if (decimal >= 9) {
                    
                    result += "IX";
                    decimal -= 9;
                    
                } else if (decimal >= 5) {
                    
                    result += "V";
                    decimal -= 5;

                } else if (decimal >= 4) {
                        
                    result += "IV";
                    decimal -= 4;
                        
                } else {
                    
                    result.push_back('I');
                    decimal--;
                    
                }
                
            }
            
            return result;
        }
        
    };
}

#endif
