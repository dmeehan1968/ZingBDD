//
//  BooleanMatcherSpec.cpp
//  ZingBDD
//
//  Created by Dave Meehan on 08/01/2014.
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

describe(BooleanMatcher, {
    
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
        
        it("exception on true != true", {
            
            try {
                expect( true ).shouldNot.beTrue();
                
            } catch (std::exception &) {
                
                return;
                
            }
            
            throw std::runtime_error("exception not received");
            
        });
        
        it("exception on false != false", {
            
            try {
                expect( false ).shouldNot.beFalse();
                
            } catch (std::exception &) {
                
                return;
                
            }
            
            throw std::runtime_error("exception not received");
            
        });
        
    });

});

