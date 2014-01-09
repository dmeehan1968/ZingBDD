//
//  StringCalculatorSpec.cpp
//  RSpeCpp
//
//  Created by Dave Meehan on 06/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#include "ZingBDD.h"

#include "StringCalculator.h"

describe(StringCalculator, {
    
    using StringCalculator::StringCalculator;

    std::shared_ptr<StringCalculator> sut;
    
    beforeEach({
        
        sut = std::make_shared<StringCalculator>();
        
    });
    
    afterEach({
       
        sut = nullptr;
        
    });
    
    it("is default constructible", {
        
        expect( std::is_default_constructible<StringCalculator>::value ).should.beTrue();
        
    });

    context("constructor", {
        
        it("exists", {
            
            expect( sut.get() ).shouldNot.beNil();
            
        });
        
    });
    
    context("add", {
        
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

        context("comma delimited", {

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
        
        context("newline delimited", {
            
            it("numbers separated by newline or comma", {

                expect( sut->add("1\n2,3") ).should.equal( 6 );
                
            });
            
            it("consecutive different delimiters throws", {
                
                expect( theBlock( {
                    
                    sut->add("1,\n");
                    
                } ) ).should.raise<std::runtime_error>("Expected number");
                
            });

            it("consecutive same delimiters throws", {
                
                expect( theBlock( {
                
                    sut->add("1,,");
                    
                } ) ).should.raise<std::runtime_error>("Expected number");
                
            });

        });

        context("invalid delimiter", {
            
            it("should throw", {
           
                expect( theBlock( {
                    
                    sut->add("1$");
                    
                } ) ).should.raise<std::runtime_error>("Expected delimiter");
                
            });
        });
        
        context("alternate delimiters", {
           
            it("one delimiter", {
                
                expect( sut->add("//;\n1;2") ).should.equal( 3 );
                
            });
            
            it("two delimiters", {
                
                expect( sut->add("//;:\n1;2:3") ).should.equal( 6 );
                
            });
            
            it("no delimiters found throws", {
               
                expect( theBlock( {
                    
                    sut->add("//\n");
                    
                })).should.raise<std::runtime_error>("Expected delimiters");
                
            });
            
            it("missing terminator throws", {
               
                expect( theBlock( {
                    
                    sut->add("//;1;2;3");
                    
                })).should.raise<std::runtime_error>("Expected delimiter terminator");
                
            });
            
        });
        
        context("negative numbers", {
           
            it("throws on negative", {
                
                expect(theBlock({
                    
                    sut->add("-1");
                    
                })).should.raise<std::runtime_error>("Negatives not allowed: -1");
                
            });
            
            it("throws on multiple negatives", {
                
                expect(theBlock({
                    
                    sut->add("1,2,-3,4,-5");
                    
                })).should.raise<std::runtime_error>("Negatives not allowed: -3, -5");
                
            });
            
        });

    });

});
