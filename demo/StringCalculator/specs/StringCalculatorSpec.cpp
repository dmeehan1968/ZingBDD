//
//  StringCalculatorSpec.cpp
//  ZingBDD
//
//  Created by Dave Meehan on 06/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//
//  This software is released under the terms of the:
//
//  GNU GENERAL PUBLIC LICENSE
//  Version 3, 29 June 2007
//
//  Please read LICENSE.md for full terms and conditions.
//

#include "ZingBDD/ZingBDD.h"

#include "../src/StringCalculator.h"

describe(StringCalculator, {
    
    using StringCalculator::StringCalculator;

    std::shared_ptr<StringCalculator> sut;
    
    beforeEach({
        
        sut = std::make_shared<StringCalculator>();
        
    });
    
    afterEach({
       
        sut = nullptr;
        
    });
    
    context("constructor", {
        
        it("exists", {
            
            expect( (bool)sut ).should.beTrue();
            
        });
        
    });
    
    context("add", {
        
        struct ValidInputs {
            std::string expectation;
            std::string input;
            int result;
        };
        
        std::vector<struct ValidInputs> validInputs = {
            {
                "an empty string returns 0",
                "",
                0
            },
            {
                "the single digit 1 returns 1",
                "1",
                1
            },
            {
                "the three digit number 123 returns 123",
                "123",
                123
            },
            {
                "two numbers, comma delimited",
                "1,2",
                3
            },
            {
                "multiple digit numbers separated by comma",
                "123,321",
                444
            },
            {
                "multiple numbers, comma separated",
                "1,20,300,4000,50000",
                54321
            },
            {
                "single digit numbers, newline and comma delimited",
                "1\n2,3",
                6
            },
            {
                "alternate single delimiter",
                "//;\n1;2",
                3
            },
            {
                "alternative delimiters, two of",
                "//;:\n1;2:3",
                6
            },
        };
        
        for ( auto validInput : validInputs ) {
            
            it(validInput.expectation, {
                
                expect(sut->add(validInput.input)).should.equal(validInput.result);
                
            });
            
        }

        context("newline delimited", {
            
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
