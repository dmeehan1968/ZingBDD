//
//  BooleanMatcher.h
//  RSpeCpp
//
//  Created by Dave Meehan on 07/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef RSpeCpp_BooleanMatcher_h
#define RSpeCpp_BooleanMatcher_h

#include "Matcher.h"

namespace RSpeCpp {

    template <typename T> class BooleanMatcher : public Matcher<T> {
    public:
        using Matcher<T>::Matcher;
    };
    
    template <>
    class BooleanMatcher<bool> : public Matcher<bool> {
        
    public:
        using Matcher<bool>::Matcher;
        using Matcher<bool>::actual;
        using Matcher<bool>::logical;
        
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
