//
//  CalculatorParserSpec.cpp
//  ZingBDD
//
//  Created by Dave Meehan on 10/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#include "ZingBDD.h"

#include "CalculatorParser.h"

describe(CalculatorParser, {

    using StringCalculator::CalculatorParser;
    
    std::shared_ptr<CalculatorParser> sut;
    
    beforeEach({
        
        sut = std::make_shared<CalculatorParser>();
        
    });
    
    context("parse valid", {
        
        struct ParserExample {
            std::string context;
            std::string input;
            CalculatorParser::container_type expected;
        };
        
        std::vector<struct ParserExample> examples = {
            {
                "empty string",
                "",
                { }
            },
            {
                "single number",
                "123",
                { 123 }
            },
            {
                "two numbers, comma delimited",
                "123,456",
                { 123, 456 }
            },
            {
                "multiple numbers, comma delimited",
                "1,20,300,4000,50000",
                { 1, 20, 300, 4000, 50000 }
            },
            {
                "two numbers, newline delimited",
                "123\n456",
                { 123, 456 }
            },
            {
                "three numbers, mixed delimiters",
                "123,456\n789",
                { 123, 456, 789 }
            },
            {
                "alternate delimiters",
                "//;\n123;456",
                { 123, 456 }
            },
            {
                "negative numbers",
                "1,-2,3,-4,5",
                { 1, -2, 3, -4, 5 }
            }
            
        };
        
        CalculatorParser::container_type container;

        for ( auto example : examples ) {
            
            context(example.context, {
               
                beforeEach({
                   
                    container = sut->parse(example.input);
                    
                });
                
                it("has expected count", {
                    
                    expect(container).should.haveCountOf(example.expected.size());
                    
                });
                
                it("has expected elements", {
                    
                    expect(container).should.contain(example.expected.begin(), example.expected.end());
                    
                });
                
            });
            
        }   // for(examples...)
        
    });
   
    context("parse invalid", {
        
        context("invalid delimiter", {
            
            it("throws", {
                
                expect(theBlock({
                    
                    sut->parse("1;2");
                    
                })).should.raise("Expected delimiter");
                
            });
        });
        
        context("not a number", {
            
            it("throws", {
                
                expect(theBlock({
                    
                    sut->parse("abc");
                    
                })).should.raise("Expected number");
                
            });
        });
    
        context("delimiter specification without terminator", {
            
            it("throws", {
                
                expect(theBlock({
                    
                    sut->parse("//;1;2");
                    
                })).should.raise("Expected delimiter terminator");
                
            });
        });
        
        context("delimiter guard without any following", {
            
            it("throws", {
                
                expect(theBlock({
                    
                    sut->parse("//");
                    
                })).should.raise("Expected delimiters");
                
            });
        });
    });
    
    
    
});