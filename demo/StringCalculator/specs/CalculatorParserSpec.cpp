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
       
        CalculatorParser::container_type container;

        beforeEach({
            
            sut = std::make_shared<CalculatorParser>();
            
        });
        
        context("empty string", {
            
            beforeEach({
                
                container = sut->parse("");
                
            });
            
            it("is empty", {
            
                expect(container).should.beEmpty();
                
            });
            
        });
        
        context("comma delimiter", {
            
            context("single digit", {
                
                beforeEach({
                    
                    container = sut->parse("1");
                    
                });
                
                it("returns one element", {
                    
                    expect( container ).should.haveCountOf( 1 );
                    
                });
                
                it("element value is one", {
                    
                    expect( container ).should.contain( 1 );
                    
                });
                
            });
            
            context("two numbers", {
                
                beforeEach({
                    
                    container = sut->parse("1,2");
                    
                });
                
                it("returns two elements", {
                    
                    expect(container).should.haveCountOf(2);
                    
                });
                
                it("contains expected elements", {
                    
                    auto expected = { 1, 2 };
                    
                    expect(container).should.contain(expected.begin(), expected.end());
                    
                });
                
            });
            
            context("multiple numbers", {
                
                CalculatorParser::container_type expected;
                
                beforeEach({
                    
                    expected = { 1, 20, 300, 4000, 50000 };
                    
                    std::ostringstream os;
                    
                    std::copy(expected.begin(), expected.end()-1, std::ostream_iterator<int>(os, ","));
                    os << *(expected.end()-1);
                    
                    container = sut->parse(os.str());
                    
                });
                
                it("has expected element count", {
                    
                    expect(container).should.haveCountOf(expected.size());
                    
                });
                
                it("has expected elements", {
                    
                    expect(container).should.contain(expected.begin(), expected.end());
                    
                });
                
            });
   
        });
        
        context("newline delimiter", {
            
            context("two numbers", {
                
                beforeEach({
                    
                    container = sut->parse("123\n456");
                    
                });
            
                it("has two elements", {
                   
                    expect(container).should.haveCountOf(2);
                    
                });
                   
                it("has expected elements", {
                
                    auto expected = { 123, 456 };
                    
                    expect(container).should.contain(expected.begin(), expected.end());
                    
                });
                
            });
            
        });
        
        context("alternate delimiters", {
           
            context("single", {
                
                beforeEach({
                    
                    container = sut->parse("//;\n123;456");
                    
                });
                
                it("has two elements", {
                    
                    expect(container).should.haveCountOf(2);
                    
                });
                
                it("has expected elements", {
                    
                    auto expected = { 123, 456 };
                    
                    expect(container).should.contain(expected.begin(), expected.end());
                    
                });
                
            });
            
        });
    });
    
    
});