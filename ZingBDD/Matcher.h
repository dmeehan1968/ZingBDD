//
//  Matcher.h
//  ZingBDD
//
//  Created by Dave Meehan on 08/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//
//  This software is released under the terms of the:
//
//  GNU GENERAL PUBLIC LICENSE
//  Version 3, 29 June 2007
//
//  Please read LICENSE.md for full terms and conditions.
//

#ifndef ZingBDD_Matcher_h
#define ZingBDD_Matcher_h

namespace ZingBDD {
    
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

    template <typename T>
    class Matcher<T *> {
        
    public:
        Matcher( const T *actual, bool logical ) : _actual(actual), _logical(logical) {}
        
        const T &actual() const {
            return *_actual;
        }
        
        const bool logical() const {
            return _logical;
        }
        
    private:
        
        const T *_actual;
        bool _logical;
        
    };

}

#endif
