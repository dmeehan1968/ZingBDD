//
//  StringCalculator.h
//  RSpeCpp
//
//  Created by Dave Meehan on 06/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef RSpeCpp_StringCalculator_h
#define RSpeCpp_StringCalculator_h

#include "CalculatorParser.h"

namespace StringCalculator {

    class StringCalculator {
        
    public:
        int add(const std::string &string) {

            auto parsedNumbers = CalculatorParser().parse(string);
            
            return sumNumbers(parsedNumbers);
            
        }
        
        int sumNumbers(std::vector<int> parsedNumbers) {
            
            int result = 0;
            
            for (auto number : parsedNumbers) {
                
                result += number;
            }

            return result;
        }
    };

}


#endif
