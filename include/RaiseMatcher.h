//
//  RaiseMatcher.h
//  ZingBDD
//
//  Created by Dave Meehan on 07/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef ZingBDD_RaiseMatcher_h
#define ZingBDD_RaiseMatcher_h

#include "Matcher.h"

namespace ZingBDD {
    
    template <typename T>
    class RaiseMatcher : public Matcher<T> {
    public:
        using Matcher<T>::Matcher;
    };
    
    template <>
    class RaiseMatcher<std::function<void(void)>> : public Matcher<std::function<void(void)>> {
        
    public:
        using T = std::function<void(void)>;
        using Matcher<T>::Matcher;
        using Matcher<T>::actual;
        using Matcher<T>::logical;

        template <class T = std::exception>
        void raise(std::string what = "") {
            
            try {
                
                auto block = actual();
                block();
                
            } catch (T &e) {
                
                std::ostringstream os;

                if (logical()) {

                    if (what.size() == 0 || e.what() == what) {
                        return;
                    }

                    os << "Expected '" << what << "', got '" << e.what() << "'";
                    throw std::runtime_error(os.str());

                } else {
                    
                    os << "Unexpected exception '" << e.what() << "'";
                    
                    throw std::runtime_error(os.str());
                    
                }
            }
            
            if (logical()) {
                
                throw std::runtime_error("exception was not received");
                
            } else {
                // expected, fall through
            }
            
        }
        
    };

}

#endif
