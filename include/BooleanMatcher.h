//
//  BooleanMatcher.h
//  RSpeCpp
//
//  Created by Dave Meehan on 07/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef RSpeCpp_BooleanMatcher_h
#define RSpeCpp_BooleanMatcher_h

namespace RSpeCpp {
    
    template <typename T, bool logical>
    class BooleanMatcher {
        
    public:
        
        BooleanMatcher( const T& actual ) : _actual(actual) {}
        
        void beTrue() {
            
            if ((_actual != true) == logical) {
                
                throw std::runtime_error(error());
                
            }
            
        }
        
        void beFalse() {
            
            if ((_actual != false) == logical) {
                
                throw std::runtime_error("expected false");
                
            }
            
        }
        
        std::string error() {
            if (logical) {
                return "expected true";
            } else {
                return "expected false";
            }
        }
        
    private:
        
        const T& _actual;
        
    };

}

#endif
