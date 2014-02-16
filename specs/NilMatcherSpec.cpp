//
//  NilMatcherSpec.cpp
//  ZingBDD
//
//  Created by Dave Meehan on 16/02/2014.
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

describe(NilMatcher, {

    int data;
    int *ptr = &data;
    int *nilptr = nullptr;
    
    context("logical", {
        
        it("nil", {
        
            expect( nilptr ).should.beNil();
            
        });
        
        it("non-nil", {
            
            expect( ptr ).should.beNonNil();

        });
        
        it("nil failure", {
            
            expect(theBlock({
                
                expect( ptr ).should.beNil();
                
            })).should.raise<std::runtime_error>("expected Nil");
            
        });
        
        it("non-nil failure", {
            
            expect(theBlock({
                
                expect( nilptr ).should.beNonNil();
                
            })).should.raise<std::runtime_error>("expected Not to be Nil");
            
        });
        
    });
    
    context("illogical", {
        
        it("nil", {
            
            expect( nilptr ).shouldNot.beNonNil();
            
        });
        
        it("non-nil", {
            
            expect( ptr ).shouldNot.beNil();
            
        });
        
        it("nil failure", {
            
            expect(theBlock({
                
                expect( ptr ).shouldNot.beNonNil();
                
            })).should.raise<std::runtime_error>("expected Nil");
            
        });
        
        it("non-nil failure", {
            
            expect(theBlock({
                
                expect( nilptr ).shouldNot.beNil();
                
            })).should.raise<std::runtime_error>("expected Not to be Nil");
            
        });
        
    });
    
});

