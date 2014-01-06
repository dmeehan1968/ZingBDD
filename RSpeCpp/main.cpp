//
//  main.cpp
//  RSpeCpp
//
//  Created by Dave Meehan on 05/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>

#include "RSpeCpp.h"

////////////////////////////////////////////////////////////////////////////////////////
/// StringCalculator
////////////////////////////////////////////////////////////////////////////////////////

class StringCalculator {
	
public:
	int add(const std::string &string) {
		return 0;
	}
	
};

////////////////////////////////////////////////////////////////////////////////////////
/// StringCalculatorSpec
////////////////////////////////////////////////////////////////////////////////////////


describe(StringCalculator) {
	
	context("add", {
		
		StringCalculator *sut;
		
		beforeEach({
		
			sut = new StringCalculator;
			
		});
		
		it("returns zero for empty string", {
			
			expect( sut->add("") ).toEqual( 0 );
			
		});
		
		it("returns one for string with digit one", {
			
			expect( sut->add("1") ).toEqual( 1 );
			
		});
		
	});
}

int main(int argc, const char * argv[])
{

	RSpeCpp::Runner().run(std::cout);
	
    return 0;
}




