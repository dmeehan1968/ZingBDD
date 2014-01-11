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
            
            it("should pass", {
                
                expect(1).should.beLessThan(2);
                
            });
            
        });
        
        context("an integer subject is not less than expected", {
            
            it("should throw", {
                
                try {
                    expect(1).shouldNot.beLessThan(2);
                } catch (...) {
                    return;
                }
                
                throw std::runtime_error("execption not received");
                
            });
            
            
        });
        
        context("an integer subject is greater than expected", {
            
            it("should throw", {
                
                try {
                    expect(2).should.beLessThan(1);
                } catch (...) {
                    return;
                }
                
                throw std::runtime_error("expection not received");
                
            });
        });
        
        context("an integer subject is not greater than expected", {
            
            it("should pass", {
                
                expect(2).shouldNot.beLessThan(1);
                
            });
            
        });
        
        context("an integer subject is equal to expected", {
            
            it("should throw", {
                
                try {
                    expect(1).should.beLessThan(1);
                } catch (...) {
                    return;
                }
                
                throw std::runtime_error("exception not received");
                
            });
            
        });
        
        context("an integer subject is not equal to expected", {
            
            it("should pass", {
                
                expect(1).shouldNot.beLessThan(1);
                
            });
            
        });
    });
    
    context("beGreaterThan", {
       
        context("an integer subject is greater than expected", {
            
            it("should pass", {
                
                expect(2).should.beGreaterThan(1);
                
            });
            
        });
        
        context("an integer subject is not greater than expected", {
            
            it("should throw", {
                
                try {
                    expect(2).shouldNot.beGreaterThan(1);
                } catch (...) {
                    return;
                }
                
                throw std::runtime_error("exception not received");
                
            });
            
        });
        
        context("an integer subject is less then expected", {
            
            it("should throw", {
                
                try {
                    expect(1).should.beGreaterThan(2);
                } catch (...) {
                    return;
                }
                
                throw std::runtime_error("expection not received");
            });
            
        });
        
        context("an integer subject is not less than expected", {
            
            it("should pass", {
                
                expect(1).shouldNot.beGreaterThan(2);
                
            });
            
        });
        
        context("an integer subject is equal to expected", {
            
            it("should throw", {
                
                try {
                    expect(1).should.beGreaterThan(1);
                } catch (...) {
                    return;
                }
                
                throw std::runtime_error("exception not received");
                
            });
        });
        
        context("an integer subject is not equal to expected", {
            
            it("should pass", {
                
                expect(1).shouldNot.beGreaterThan(1);
                
            });
        });
        
    });
    
    context("beLessThanOrEqualTo", {
       
        context("an integer subject less than expected", {
            
            it("should pass", {
                
                expect(1).should.beLessThanOrEqualTo(2);
                
            });
            
        });
        
        context("an interger subject not less than expected", {
            
            it("should throw", {
                
                try {
                    expect(1).shouldNot.beLessThanOrEqualTo(2);
                } catch (...) {
                    return;
                }
                
                throw std::runtime_error("exception not received");
                
            });
            
        });
        
        context("an integer subject greater than expected", {
            
            it("should throw", {
                
                try {
                    expect(2).should.beLessThanOrEqualTo(1);
                } catch (...) {
                    return;
                }
                
                throw std::runtime_error("exception not received");
                
            });
        });
        
        context("an integer subject not greater than expected", {
            
            it("should pass", {
                
                expect(2).shouldNot.beLessThanOrEqualTo(1);
                
            });
            
        });
        
        context("an integer subject equal to expected", {
            
            it("should pass", {
                
                expect(1).should.beLessThanOrEqualTo(1);
                
            });
            
        });
        
        context("an integer subject not equal to expected", {
            
            it("should throw", {
                
                try {
                    expect(1).shouldNot.beLessThanOrEqualTo(1);
                } catch (...) {
                    return;
                }
                
                throw std::runtime_error("exception not received");
                
            });
        });
    });
});
