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
		
		StringCalculator *sut = nullptr;
		
		beforeEach({
			
			sut = new StringCalculator;
			
		});
		
		it("exists", {
			
			expect( sut ).shouldNot.beNil();
			
		});
	});
	
	context("add", {
		
		std::shared_ptr<StringCalculator> sut;
		
		beforeEach({
			
			sut = std::shared_ptr<StringCalculator>(new StringCalculator);
			
		});
		
		it("an empty string", {
			
			expect( sut->add("") ).should.equal( 0 );
			
		});

		context("single numbers", {
		
			it("with digit one", {
				
				expect( sut->add("1") ).should.equal( 1 );
				
			});
			
			it("three consequtive digits", {
				
				expect( sut->add("123") ).should.equal( 123 );
				
			});
			
		});
		
		it("numbers separated by comma", {
			
			expect( sut->add("1,2") ).should.equal( 3 );
			
		});


		
	});
	
});


#endif
