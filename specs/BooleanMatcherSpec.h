//
//  BooleanMatcherSpec.h
//  RSpeCpp
//
//  Created by Dave Meehan on 08/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef RSpeCpp_BooleanMatcherSpec_h
#define RSpeCpp_BooleanMatcherSpec_h

#include "ZingBDD.h"

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
                
            } catch (std::exception &e) {
                
                return;
                
            }
            
            throw std::runtime_error("exception not received");
            
        });
        
        it("exception on false != false", {
            
            try {
                expect( false ).shouldNot.beFalse();
                
            } catch (std::exception &e) {
                
                return;
                
            }
            
            throw std::runtime_error("exception not received");
            
        });
        
    });

});

#endif
