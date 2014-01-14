//
//  ContainerMatcherSpec.cpp
//  ZingBDD
//
//  Created by Dave Meehan on 11/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#include "ZingBDD/ZingBDD.h"

describe(ContainerMatcher, {
   
    std::vector<int> container;
    
    beforeEach({
        
        container.clear();
        
    });

    context("an empty container", {
        
        it("should be empty", {
            
            expect(container).should.beEmpty();
            
        });
        
        it("should not be empty fails", {
            
            expect(theBlock({
                
                expect(container).shouldNot.beEmpty();
                
            })).should.raise("expected to be NOT empty");
            
        });
        
        it("has a count of zero", {
            
            expect(container).should.haveCountOf(0);
            
        });
        
        it("should not have count of zero fails", {
            
            expect(theBlock({

                expect(container).shouldNot.haveCountOf(0);
                
            })).should.raise("expected to NOT have count of 0");
            
        });
        
        it("should have count of at least zero", {
            
            expect(container).should.haveCountOfAtLeast(0);
            
        });
        
        it("should not have count of at least zero, fails", {
            
            expect(theBlock({
                
                expect(container).shouldNot.haveCountOfAtLeast(0);
                
            })).should.raise("expected to NOT have at least 0, got 0");
            
        });
        
        it("should have count of at most zero", {
            
            expect(container).should.haveCountOfAtMost(0);
            
        });
        
        it("should not have count of at most zero", {
            
            expect(theBlock({
                
                expect(container).shouldNot.haveCountOfAtMost(0);

            })).should.raise("expected to NOT have at most 0");
            
        });
        
        it("should not contain an item", {
            
            expect(container).shouldNot.contain(1);
            
        });
        
        it("should contain an item, fails", {
            
            expect(theBlock({
                
                expect(container).should.contain(1);
                
            })).should.raise("value 1 NOT found");
            
        });
        
        it("should contain the item one in a range, fails", {
            
            expect(theBlock({
                
                auto expected = { 1 };
                expect(container).should.contain(expected.begin(), expected.end());

            })).should.raise("expected 1 but was missing 1");
            
        });
        
    });
    
    context("a container with one item", {
        
        beforeEach({
            
            container.push_back(1);
            
        });
       
        it("should not be empty", {
            
            expect(container).shouldNot.beEmpty();
            
        });
        
        it("should be empty, fails", {
            
            expect(theBlock({
                
                expect(container).should.beEmpty();
                
            })).should.raise("expected to be empty but has 1 items");
            
        });
        
        it("should have count of one", {
            
            expect(container).should.haveCountOf(1);
            
        });
        
        it("should not have count of one, fails", {
            
            expect(theBlock({
                
                expect(container).shouldNot.haveCountOf(1);
                
            })).should.raise("expected to NOT have count of 1");
        });
        
        it("should have count of at least 1", {
            
            expect(container).should.haveCountOfAtLeast(1);
            
        });
        
        it("should have count of at least zero", {
            
            expect(container).should.haveCountOfAtLeast(0);
            
        });
           
        it("should not have count of at least 1, fails", {
            
            expect(theBlock({
                
                expect(container).shouldNot.haveCountOfAtLeast(1);
                
            })).should.raise("expected to NOT have at least 1, got 1");
            
        });
        
        it("should have count of at most 1", {
            
            expect(container).should.haveCountOfAtMost(1);
            
        });
        
        it("Should have count of at most 2", {
            
            expect(container).should.haveCountOfAtMost(2);
            
        });
        
        it("should have count of at most zero, fails", {
            
            expect(theBlock({
                
                expect(container).should.haveCountOfAtMost(0);
                
            })).should.raise("expected to have at most 0, got 1");
            
        });
        
        it("should not have count at most of 0, fails", {
            
            expect(theBlock({
                
                expect(container).shouldNot.haveCountOfAtMost(1);
                
            })).should.raise("expected to NOT have at most 1");
            
        });
        
        it("should contain the value 1", {
            
            expect(container).should.contain(1);
            
        });
        
        it("should not contain the value 1, fails", {
            
            expect(theBlock({
                
                expect(container).shouldNot.contain(1);
                
            })).should.raise("value 1 found");
        });
        
        it("should contain the value 1 in range", {
           
            auto expected = { 1 };
            
            expect(container).should.contain(expected.begin(), expected.end());
            
        });
        
        it("should contain the values 1 and 2 in range, fails", {
            
            expect(theBlock({
             
                auto expected = { 1, 2 };
                
                expect(container).should.contain(expected.begin(), expected.end());
                
            })).should.raise("expected 1, 2 but was missing 2");
            
        });
    });
    
    
});
