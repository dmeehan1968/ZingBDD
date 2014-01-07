//
//  StringCalculator.h
//  RSpeCpp
//
//  Created by Dave Meehan on 06/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef RSpeCpp_StringCalculator_h
#define RSpeCpp_StringCalculator_h

class StringCalculator {
	
public:
	int add(const std::string &string) {
		
		std::string input = string;
		
		auto parsedNumbers = parseNumbers(string);
		
		return sumNumbers(parsedNumbers);
		
	}

	std::vector<int> parseNumbers(std::string input) {
		
		std::vector<int> parsedNumbers;
		
		while (input.size() > 0) {
			
			auto pos = input.find(',');
			
			if (pos == std::string::npos) {
				
				parsedNumbers.push_back(std::stoi(input));
				input.clear();
				
			} else {
				
				auto numberString = input.substr(0, pos);
				
				parsedNumbers.push_back(std::stoi(numberString));
				
				input = input.substr(pos+1);
				
			}
		}
		
		return parsedNumbers;

	}
	
	int sumNumbers(std::vector<int> parsedNumbers) {
		
		int result = 0;
		
		for (auto number : parsedNumbers) {
			
			result += number;
		}

		return result;
	}
};



#endif
