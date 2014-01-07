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
    
    using StringCalculator::StringCalculator;
    
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

        context("comma separated", {

            it("single digit numbers separated", {
                
                expect( sut->add("1,2") ).should.equal( 3 );
                
            });

            it("multiple digits separated", {
                
                expect( sut->add("123,321") ).should.equal( 444 );
                
            });
            
            it("any number of numbers", {
                
                expect( sut->add("1,20,300,4000,50000") ).should.equal( 54321 );
                
            });
            
        });
        
        context("newline separated", {
            
            it("numbers separated by newline or comma", {

                expect( sut->add("1\n2,3") ).should.equal( 6 );
                
            });
            
            it("consecutive different delimiters throws", {
                
                expect( theBlock( {
                    
                    sut->add("1,\n");
                    
                } ) ).should.raise("Expected number");
                
            });

            it("consecutive same delimiters throws", {
                
                expect( theBlock( {
                
                    sut->add("1,,");
                    
                } ) ).should.raise("Expected number");
                
            });

        });

        context("invalid delimiter", {
            
            it("should throw", {
           
                expect( theBlock( {
                    
                    sut->add("1$");
                    
                } ) ).should.raise("Expected delimiter");
                
            });
        });

        context("boolean matchers", {
			
            it("true", {
                
                expect( true ).should.beTrue();
                
            });
            
            it("not true", {
                
                expect( true ).shouldNot.beFalse();
                
            });
            
            it("false", {
                
                expect( false ).should.beFalse();
                
            });
            
            it("not false", {
                
                expect( false ).shouldNot.beTrue();
                
            });
            
		});

    });
    
});

#endif
