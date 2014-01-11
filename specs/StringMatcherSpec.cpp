//
//  StringMatcherSpec.cpp
//  ZingBDD
//
//  Created by Dave Meehan on 11/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#include "ZingBDD.h"

describe(StringMatcher, {

    std::string string;
    
    beforeEach({
        
        string = "This is a Test";
        
    });
    
    context("with matching fragment of string", {
        
        std::string expected;
        
        beforeEach({
            
            expected = std::string(string, 5, 4);
            
        });

        it("should contain string", {
           
            expect(string).should.containString(expected);
            
        });
        
        it("should not contain with matching string, fails", {
            
            std::string what(std::string("'") + expected + std::string("' NOT found"));
            
            expect(theBlock({
                
                expect(string).shouldNot.containString(expected);
                
            })).should.raise(what);
            
        });
        
    });
    
    context("with matching start fragment of string", {
        
        std::string expected;
        
        beforeEach({
            
            expected = std::string(string, 0, 4);
            
        });
        
        it("should contain string", {
            
            expect(string).should.containString(expected);
            
        });
        
        it("should start with string", {
            
            expect(string).should.beginWithString(expected);
            
        });
        
        it("should not start with string, fails", {
            
            std::string what(std::string("'") + expected + std::string("' found"));
            
            expect(theBlock({
                
                expect(string).shouldNot.beginWithString(expected);
                
            })).should.raise(what);
            
        });
        
    });
    
    context("with matching end fragment of string", {
        
        std::string expected;
        
        beforeEach({
            
            expected = std::string(string, 10, 4);

        });
        
        it("should contain string", {
            
            expect(string).should.containString(expected);
            
        });
        
        it("should end with string", {
            
            expect(string).should.endWithString(expected);
            
        });
        
        it("should not end with string, fails", {
            
            std::string what(std::string("'") + expected + std::string("' found"));
            
            expect(theBlock({
                
                expect(string).shouldNot.endWithString(expected);
                
            })).should.raise(what);
            
        });
        
    });
    
});
