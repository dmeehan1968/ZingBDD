//
//  MethodCall.h
//  ZingBDD
//
//  Created by Dave Meehan on 05/02/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//
//  This software is released under the terms of the:
//
//  GNU GENERAL PUBLIC LICENSE
//  Version 3, 29 June 2007
//
//  Please read LICENSE.md for full terms and conditions.
//

#ifndef ZingBDD_MethodCall_h
#define ZingBDD_MethodCall_h

#include "VoidMethodCall.h"

namespace ZingBDD {
    
    template
    <
    typename R,
    typename T1,
    typename... Tn
    >
    class MethodCall : protected VoidMethodCall<T1, Tn...> {
        
    public:
        
        void expects(const R &retval, const T1 &a1, const Tn&... An) {
            
            VoidMethodCall<T1, Tn...>::expects(a1, An...);
            _retval.push_back(retval);
            
        }
        
        R receives(const T1 &a1, const Tn&... An) {
            
            VoidMethodCall<T1, Tn...>::receives(a1, An...);
            
            R retval = _retval.front();
            _retval.pop_front();
            
            return retval;
        }
        
    private:
        
        std::deque<R> _retval;
        
    };

}

#endif
