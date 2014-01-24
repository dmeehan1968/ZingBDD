//
//  BeWithinDelta.h
//  ZingBDD
//
//  Created by Dave Meehan on 11/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef ZingBDD_BeWithinDelta_h
#define ZingBDD_BeWithinDelta_h

#include <cmath>

namespace ZingBDD {
    
    template <typename T>
    class BeWithinDelta {
        
    public:
        BeWithinDelta( const T& actual, const T& delta, bool logical ) : _actual(actual), _delta(fabs(delta)), _logical(logical) {}
        
        void of( const T& expected ) {
            
            if ((fabs(_actual - expected) > _delta) == _logical) {
                
                std::ostringstream os;
                
                os  << "expected " << _actual
                << " to " << (_logical ? "" : "NOT ")
                << "be within " << _delta
                << " of " << expected;
                
                throw std::runtime_error(os.str());
                
            }
            
        }
        
    private:
        
        const T& _actual;
        const T _delta;
        const bool _logical;
        
    };
    
}

#endif
