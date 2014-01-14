//
//  MathExpressionsSpec.cpp
//  ZingBDD
//
//  Created by Dave Meehan on 14/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#include <memory>

#include "ZingBDD/ZingBDD.h"

#include "demo/MathExpressions/src/MathParser.h"

describe(MathExpressions, {

    using MathExpressions::MathParser;
    
    std::shared_ptr<MathParser> sut;
    
    context("parse", {
    
        beforeEach({
            
            sut = std::make_shared<MathParser>();
            
        });
        
        it("empty string returns 0", {
            
            expect(sut->parse("")).should.equal(0);
            
        });
        
        it("single digit returns same value", {
            
            expect(sut->parse("1")).should.equal(1);
            
        });
        
        it("multiple digit number returns same value", {
            
            expect(sut->parse("123")).should.equal(123);
            
        });
        
        it("1 + 1 = 2", {
            
            expect(sut->parse("1+1")).should.equal(2);
            
        });
        
    });
    
});

