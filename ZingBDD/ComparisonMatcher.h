//
//  ComparisonMatcher.h
//  ZingBDD
//
//  Created by Dave Meehan on 10/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//
//  This software is released under the terms of the:
//
//  GNU GENERAL PUBLIC LICENSE
//  Version 3, 29 June 2007
//
//  Please read LICENSE.md for full terms and conditions.
//

#ifndef ZingBDD_ComparisonMatcher_h
#define ZingBDD_ComparisonMatcher_h

#include "BeWithinDelta.h"

namespace ZingBDD {

    template <typename T>
    class ComparisonMatcher : public Matcher<T> {
        
    public:
        ComparisonMatcher( const T& actual, bool logical ) : Matcher<T>(actual, logical) {}
    
        void beLessThan( const T &expected ) {
            
            if ((this->actual() >= expected) == this->logical()) {
                
                std::ostringstream os;
                
                os  << "expected " << this->actual()
                    << " to " << (this->logical() ? "" : "NOT ")
                    << "be less than " << expected;
                
                throw std::runtime_error(os.str());
                
            }
        }
        
        void beGreaterThan( const T &expected ) {
            
            if ((this->actual() <= expected) == this->logical()) {
                
                std::ostringstream os;
                
                os  << "expected " << this->actual()
                    << " to " << (this->logical() ? "" : "NOT ")
                    << "be greater than " << expected;
                
                throw std::runtime_error(os.str());
                
            }
        }
        
        void beLessThanOrEqualTo( const T &expected ) {
            
            if ((this->actual() > expected) == this->logical()) {
                
                std::ostringstream os;
                
                os  << "expected " << this->actual()
                    << " to " << (this->logical() ? "" : "NOT ")
                    << "be less than or equal to " << expected;
                
                throw std::runtime_error(os.str());
                
            }
            
        }
        
        void beGreaterThanOrEqualTo( const T &expected ) {
            
            if ((this->actual() < expected) == this->logical()) {
                
                std::ostringstream os;
                
                os  << "expected " << this->actual()
                    << " to " << (this->logical() ? "" : "NOT ")
                    << "be greater than or equal to " << expected;
                
                throw std::runtime_error(os.str());
                
            }
        }
        
        BeWithinDelta<T> beWithin( const T& delta ) {
            
            return BeWithinDelta<T>( this->actual(), delta, this->logical() );
            
        }
    };
    
}


#endif
