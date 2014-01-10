//
//  StringCalculator.h
//  ZingBDD
//
//  Created by Dave Meehan on 06/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef ZingBDD_StringCalculator_h
#define ZingBDD_StringCalculator_h

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
            std::vector<int> negatives;
            
            for (auto number : parsedNumbers) {
            
                if (number < 0) {
                    negatives.push_back(number);
                } else {
                    result += number;
                }
            }
            
            if ( ! negatives.empty()) {
                
                std::ostringstream os;
                os << "Negatives not allowed: ";
                std::copy(negatives.begin(), negatives.end()-1, std::ostream_iterator<int>(os, ", "));
                os << negatives.back();
                throw std::runtime_error(os.str());
            }

            return result;
        }
    };

}


#endif
