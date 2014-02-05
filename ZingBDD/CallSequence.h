//
//  CallSequence.h
//  ZingBDD
//
//  Created by Dave Meehan on 05/02/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef ZingBDD_CallSequence_h
#define ZingBDD_CallSequence_h

#include <deque>

#include "Arguments.h"

namespace ZingBDD {
    
    class CallSequence : protected std::deque<std::string> {
        
    public:
        using container_type = std::deque<std::string>;
        
        void expects(const std::string &methodName) {
            
            container_type::push_back(methodName);
            
        }
        
        template <class S, typename... Tn>
        void receives(const S &methodName, Tn&... An) {
            
            std::ostringstream os;
            
            auto args = Arguments<sizeof...(Tn), Tn...>(An...);
            
            if (container_type::size()) {
                
                if (container_type::front() == methodName) {
                    
                    container_type::pop_front();
                    return;
                    
                } else {
                    
                    os << "Expected call to method '" << container_type::front() << "', but received '" << methodName << "' with arguments " << args;
                    
                    throw std::runtime_error(os.str());
                }
            }
            
            os << "No calls expected, but received '" << methodName << "' with arguments " << args;
            throw std::runtime_error(os.str());
            
        }
        
        void validate() {
            
            if (container_type::size() > 0) {
                
                std::ostringstream os;
                os << container_type::size() << " calls expected, not received from ";
                
                std::copy(container_type::begin(), container_type::end(), std::ostream_iterator<typename container_type::value_type>(os, ", "));
                
                throw std::runtime_error(os.str());
            }
        }
    };
    
}

#endif
