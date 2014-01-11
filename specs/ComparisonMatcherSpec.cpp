//
//  ComparisonMatcherSpec.cpp
//  ZingBDD
//
//  Created by Dave Meehan on 10/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#include "ZingBDD.h"

describe(ComparisonMatcher, {
   
    context("beLessThan", {
        
        context("an integer subject is less than expected", {
            
            it("should passes", {
                
                expect(1).should.beLessThan(2);
                
            });
            
            it("shouldNot fails", {
                
                expect(theBlock({
                    
                    expect(1).shouldNot.beLessThan(2);
                    
                }))
                .should
                .raise("expected 1 to NOT be less than 2");
                
            });
            
        });
        
        context("an integer subject is greater than expected", {
        
            it("should fails", {
                
                expect(theBlock({
                    
                    expect(2).should.beLessThan(1);
                    
                }))
                .should
                .raise("expected 2 to be less than 1");
                
            });
            
            it("shouldNot passes", {
                
                expect(2).shouldNot.beLessThan(1);

            });
            
        });
        
        context("an integer subject is equal to expected", {
            
            it("should fails", {
                
                expect(theBlock({
                    
                    expect(1).should.beLessThan(1);
                    
                }))
                .should
                .raise("expected 1 to be less than 1");

            });
            
            it("shouldNot passes", {
                
                expect(1).shouldNot.beLessThan(1);
                
            });
            
        });

    });
    
    context("beGreaterThan", {
       
        context("an integer subject is greater than expected", {
            
            it("should passes", {
                
                expect(2).should.beGreaterThan(1);
                
            });
            
            it("shouldNot fails", {
                
                expect(theBlock({
                    
                    expect(2).shouldNot.beGreaterThan(1);
                    
                }))
                .should
                .raise("expected 2 to NOT be greater than 1");
                
            });
            
        });
        
        context("an integer subject is less then expected", {
            
            it("should fails", {
                
                expect(theBlock({
                    
                    expect(1).should.beGreaterThan(2);
                    
                }))
                .should
                .raise("expected 1 to be greater than 2");

            });
            
            it("shouldNot passes", {
                
                expect(1).shouldNot.beGreaterThan(2);
                
            });
            
        });
        
        context("an integer subject is equal to expected", {
            
            it("should fails", {
                
                expect(theBlock({
                    
                    expect(1).should.beGreaterThan(1);
                    
                }))
                .should
                .raise("expected 1 to be greater than 1");
                
            });
            
            it("shouldNot passes", {
                
                expect(1).shouldNot.beGreaterThan(1);
                
            });
            
        });
        
    });
    
    context("beLessThanOrEqualTo", {
       
        context("an integer subject less than expected", {
            
            it("should passes", {
                
                expect(1).should.beLessThanOrEqualTo(2);
                
            });
            
            it("shouldNot fails", {
                
                expect(theBlock({
                    
                    expect(1).shouldNot.beLessThanOrEqualTo(2);
                    
                }))
                .should
                .raise("expected 1 to NOT be less than or equal to 2");
                
            });
            
        });
        
        context("an integer subject greater than expected", {
            
            it("should fails", {
                
                expect(theBlock({
                    
                    expect(2).should.beLessThanOrEqualTo(1);
                    
                }))
                .should
                .raise("expected 2 to be less than or equal to 1");
                
            });
            
            it("shouldNot passes", {
                
                expect(2).shouldNot.beLessThanOrEqualTo(1);
                
            });
            
        });
        
        context("an integer subject equal to expected", {
            
            it("should passes", {
                
                expect(1).should.beLessThanOrEqualTo(1);
                
            });
            
            it("shouldNot fails", {
                
                expect(theBlock({
                    
                    expect(1).shouldNot.beLessThanOrEqualTo(1);
                    
                }))
                .should
                .raise("expected 1 to NOT be less than or equal to 1");
                
            });
            
        });
        
    });
    
    context("beGreaterThanOrEqualTo", {
       
        context("an integer subject greater than expected", {
            
            it("should passes", {
                
                expect(2).should.beGreaterThanOrEqualTo(1);
                
            });
           
            it("shouldNot fails", {
                
                expect(theBlock({
                    
                    expect(2).shouldNot.beGreaterThanOrEqualTo(1);
                    
                }))
                .should
                .raise("expected 2 to NOT be greater than or equal to 1");
                
            });
            
        });
        
        context("an integer subject less than expected", {
        
            it("should fails", {
                
                expect(theBlock({
                    
                    expect(1).should.beGreaterThanOrEqualTo(2);
                }))
                .should
                .raise("expected 1 to be greater than or equal to 2");
                
            });
            
            it("shouldNot passes", {
                
                expect(1).shouldNot.beGreaterThanOrEqualTo(2);
                
            });
            
        });
        
        context("an integer subject equal to expected", {
            
            it("should passes", {
                
                expect(1).should.beGreaterThanOrEqualTo(1);
                
            });
            
            it("shouldNot fails", {
                
                expect(theBlock({
                    
                    expect(1).shouldNot.beGreaterThanOrEqualTo(1);
                    
                }))
                .should
                .raise("expected 1 to NOT be greater than or equal to 1");
                
            });
            
        });
        
    });
    
    context("beWithin", {
       
        context("an integer subject equal to expected with no delta", {
            
            it("should passes", {
                
                expect(1).should.beWithin(0).of(1);
                
            });
            
            it("shouldNot fails", {
                
                expect(theBlock({
                    expect(1).shouldNot.beWithin(0).of(1);
                }))
                .should
                .raise<std::runtime_error>("expected 1 to NOT be within 0 of 1");
                
            });
            
        });
        
        context("an integer subject equal to expected within delta", {
            
            it("should passes", {
                
                expect(1).should.beWithin(1).of(1);
                
            });
            
            it("shouldNot fails", {
               
                expect(theBlock({
                    expect(1).shouldNot.beWithin(1).of(1);
                }))
                .should
                .raise("expected 1 to NOT be within 1 of 1");
                
            });
            
        });
        
        context("an integer subject less than expected within delta", {
            
            it("should passes", {
                
                expect(6).should.beWithin(5).of(10);
                
            });
            
            it("shouldNot fails", {
                
                expect(theBlock({
                    
                    expect(6).shouldNot.beWithin(5).of(10);
                    
                }))
                .should
                .raise("expected 6 to NOT be within 5 of 10");
                
            });
        });
        
        context("an integer subject greater than expected within delta", {
            
            it("should pass", {
                
                expect(13).should.beWithin(5).of(10);
                
            });
            
        });
        
        context("an integer subject less than expected equal to delta", {
            
            it("should passes", {
                
                expect(5).should.beWithin(5).of(10);
                
            });
            
            it("shouldNot fails", {
                
                expect(theBlock({
                    
                    expect(5).shouldNot.beWithin(5).of(10);
                    
                }))
                .should
                .raise("expected 5 to NOT be within 5 of 10");
                
            });
            
        });
        
        context("an integer subject greater than expected equal to delta", {
            
            it("should passes", {
                
                expect(15).should.beWithin(5).of(10);
                
            });
            
            it("shouldNot fails", {
                
                expect(theBlock({
                    
                    expect(15).shouldNot.beWithin(5).of(10);
                    
                }))
                .should
                .raise("expected 15 to NOT be within 5 of 10");
                
            });
            
        });
        
        context("an integer subject less than expected in excess of delta", {
            
            it("should fails", {
                
                expect(theBlock({
                    
                    expect(4).should.beWithin(5).of(10);
                    
                }))
                .should
                .raise("expected 4 to be within 5 of 10");
                
            });
            
            it("shouldNot passes", {
                
                expect(4).shouldNot.beWithin(5).of(10);

            });
            
        });
        
        context("an integer subject greater than expected in excess of delta", {
            
            it("should fails", {
                
                expect(theBlock({
                    
                    expect(16).should.beWithin(5).of(10);
                    
                }))
                .should
                .raise("expected 16 to be within 5 of 10");
                
            });
            
            it("shouldNot passes", {
                
                expect(16).shouldNot.beWithin(5).of(10);
                
            });
            
        });
    });
});
