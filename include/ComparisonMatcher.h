//
//  ComparisonMatcher.h
//  ZingBDD
//
//  Created by Dave Meehan on 10/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef ZingBDD_ComparisonMatcher_h
#define ZingBDD_ComparisonMatcher_h

namespace ZingBDD {
    
    template <typename T>
    class ComparisonMatcher : public Matcher<T> {
        
    public:
        ComparisonMatcher( const T& actual, bool logical ) : Matcher<T>(actual, logical) {}
    
        void beLessThan( const T &expected ) {
            
            if ((this->actual() >= expected) == this->logical()) {
                
                std::ostringstream os;
                
                os << "expected " << this->actual() << " to be less than " << expected;
                
                throw std::runtime_error(os.str());
                
            }
        }
        
        void beGreaterThan( const T &expected ) {
            
            if ((this->actual() <= expected) == this->logical()) {
                
                std::ostringstream os;
                
                os << "expected " << this->actual() << " to be greater than " << expected;
                
                throw std::runtime_error(os.str());
                
            }
        }
        
        void beLessThanOrEqualTo( const T &expected ) {
            
            if ((this->actual() > expected) == this->logical()) {
                
                std::ostringstream os;
                
                os << "expected " << this->actual() << " to be less then or equal to " << expected;
                
                throw std::runtime_error(os.str());
                
            }
            
        }
    };
    
}


#endif
