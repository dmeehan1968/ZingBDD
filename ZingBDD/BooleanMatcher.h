//
//  BooleanMatcher.h
//  ZingBDD
//
//  Created by Dave Meehan on 07/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef ZingBDD_BooleanMatcher_h
#define ZingBDD_BooleanMatcher_h

#include "Matcher.h"

namespace ZingBDD {

    template <typename T> class BooleanMatcher : public Matcher<T> {
    public:
        BooleanMatcher( const T& actual, bool logical ) : Matcher<T>(actual, logical) {}
    };
    
    template <>
    class BooleanMatcher<bool> : public Matcher<bool> {
        
    public:

        BooleanMatcher( const bool& actual, bool logical ) : Matcher<bool>(actual, logical) {}

        void beTrue() {
            
            if ((actual() != true) == logical()) {
                
                throw std::runtime_error(error());
                
            }
            
        }
        
        void beFalse() {
            
            if ((actual() != false) == logical()) {
                
                throw std::runtime_error("expected false");
                
            }
            
        }
        
        std::string error() {
            if (logical()) {
                return "expected true";
            } else {
                return "expected false";
            }
        }
        
    };

}

#endif
