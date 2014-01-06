//
//  StringCalculatorSpec.h
//  RSpeCpp
//
//  Created by Dave Meehan on 06/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef RSpeCpp_StringCalculatorSpec_h
#define RSpeCpp_StringCalculatorSpec_h

#include "RSpeCpp.h"

#include "StringCalculator.h"

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
		
		it("an empty string", {
			
			expect( sut->add("") ).should.equal( 0 );
			
		});
		
		it("a string with the digit one", {
			
			expect( sut->add("1") ).should.equal( 1 );
			
		});
		
	});
	
});


#endif
