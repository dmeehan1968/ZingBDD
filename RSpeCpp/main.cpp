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


describe(StringCalculator, {
	
	context("constructor", {

		StringCalculator *sut;
		
		beforeEach({
			
			sut = new StringCalculator;
			
		});
		
		it("exists", {
			
			expect( sut ).shouldNot.beNil();
			
		});
	});
	
	context("add", {
		
		StringCalculator *sut;
		
		beforeEach({
			
			sut = new StringCalculator;
			
		});
		
		it("returns zero for empty string", {
			
			expect( sut->add("") ).should.equal( 0 );
			
		});
		
		it("returns one for string with digit one", {
			
			expect( sut->add("1") ).should.equal( 1 );
			
		});
		
	});
	
});

int main(int argc, const char * argv[])
{

	RSpeCpp::Runner().run(std::cout);
	
    return 0;
}

/*
 
 expect(actual)	.should.beNil();
				.shouldNot.beNil();
				.should.equal(0);
				.should.contain("string");
				.should.beginWith("string");
				.should.beEmpty();
				.should.beTrue();
 
expect(actual).should(beNil);
 
 
 
 */


