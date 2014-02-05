//
//  VoidMethodCall.h
//  ZingBDD
//
//  Created by Dave Meehan on 05/02/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef ZingBDD_VoidMethodCall_h
#define ZingBDD_VoidMethodCall_h

#include <deque>

#include "Arguments.h"

namespace ZingBDD {
    
    template
    <
    typename T1,
    typename... Tn
    >
    class VoidMethodCall : protected std::deque<Arguments<sizeof...(Tn)+1, T1, Tn...>> {
        
    public:
        
        using container_type = std::deque<Arguments<sizeof...(Tn)+1, T1, Tn...>>;
        
        void expects(const T1 &a1, const Tn... An) {
            
            container_type::emplace_back(a1, An...);
            
        }
        
        void receives(const T1 &a1, const Tn&... An) {
            
            if (container_type::size()) {
                
                auto argsReceived = typename container_type::value_type(a1, An...);
                auto argsExpected = container_type::front();
                
                if (argsReceived == argsExpected) {
                    
                    container_type::pop_front();
                    return;
                }
                
                std::ostringstream os;
                
                os << "Expected args: " << argsExpected << ", got " << argsReceived;
                throw std::runtime_error(os.str());
                
            } else {
                
                throw std::runtime_error("Unexpected call");
                
            }
        }
        
        size_t size() const {
            return container_type::size();
        }
    };
    
}

#endif
