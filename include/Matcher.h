//
//  Matcher.h
//  RSpeCpp
//
//  Created by Dave Meehan on 08/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef RSpeCpp_Matcher_h
#define RSpeCpp_Matcher_h

namespace RSpeCpp {
    
    template <typename T>
    class Matcher {
        
    public:
        Matcher( const T& actual, bool logical ) : _actual(actual), _logical(logical) {}
        
        const T &actual() const {
            return _actual;
        }
        
        const bool logical() const {
            return _logical;
        }
        
    private:
        
        const T& _actual;
        bool _logical;
        
    };
    
}

#endif
