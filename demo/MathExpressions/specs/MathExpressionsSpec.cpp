//
//  MathExpressionsSpec.cpp
//  ZingBDD
//
//  Created by Dave Meehan on 14/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//
//  This software is released under the terms of the:
//
//  GNU GENERAL PUBLIC LICENSE
//  Version 3, 29 June 2007
//
//  Please read LICENSE.md for full terms and conditions.
//

#include <memory>

#include "ZingBDD/ZingBDD.h"

#include "demo/MathExpressions/src/MathParser.h"

describe(MathExpressions, {

    using MathExpressions::MathParser;
    
    std::shared_ptr<MathParser> sut;
    
    struct ValidInputs {
        std::string context;
        std::string input;
        int result;
    };
    
    std::vector<struct ValidInputs> validInputs = {
        {
            "empty string returns 0",
            "",
            0
        },
        {
            "single digit returns same value",
            "1",
            1
        },
        {
            "multiple digit number returns same value",
            "123",
            123
        },
        {
            "1+1 = 2",
            "1+1",
            2
        },
        {
            "123+321 = 444",
            "123+321",
            444
        },
        {
            "1-1 = 0",
            "1-1",
            0
        },
        {
            "321-123 = 198",
            "321-123",
            198
        },
        {
            "1+2+3 = 6",
            "1+2+3",
            6
        },
        {
            "1+2-3 = 0",
            "1+2-3",
            0
        },
        {
            "1+2+3+4 = 10",
            "1+2+3+4",
            10
        },
        
    };
    
    for ( auto expected : validInputs ) {
        
        context("parse", {
            
            beforeEach({
                
                sut = std::make_shared<MathParser>();
                
            });
            
            it(expected.context, {
                
                expect(sut->parse(expected.input)).should.equal(expected.result);
                
            });
            
        });
        
    }
    
});

