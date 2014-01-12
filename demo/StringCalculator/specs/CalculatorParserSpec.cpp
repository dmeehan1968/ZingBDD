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
    
    context("parse", {
        
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
            }
            
        };
        
        CalculatorParser::container_type container;

        beforeEach({
            
            sut = std::make_shared<CalculatorParser>();
            
        });
        
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
    
    
});