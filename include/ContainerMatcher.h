//
//  ContainerMatcher.h
//  ZingBDD
//
//  Created by Dave Meehan on 10/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef ZingBDD_ContainerMatcher_h
#define ZingBDD_ContainerMatcher_h

#include "Matcher.h"

namespace ZingBDD {
    
    template <typename T>
    class ContainerMatcher : public Matcher<T> {
    
    public:
        ContainerMatcher( const T& actual, bool logical ) : Matcher<T>(actual, logical) {}

        void beEmpty() {
        
            if (Matcher<T>::actual().size() > 0) {
                
                throw std::runtime_error("should be empty");
                
            }
            
        }
        
        template <typename S>
        void haveCountOf( const S count ) {
        
            if (Matcher<T>::actual().size() != count) {
                
                std::ostringstream os;
                os << "expected" << count << ", got " << Matcher<T>::actual().size();
                
                throw std::runtime_error(os.str());
                
            }
        }
        
        template <typename V>
        void contain( const V &value ) {
         
            if (std::find(Matcher<T>::actual().begin(), Matcher<T>::actual().end(), value) == Matcher<T>::actual().end()) {
                
                std::ostringstream os;
                os << "value " << value << " not found in container";
                throw std::runtime_error(os.str());
            }

        }
        
        template <typename Iter>
        void contain( Iter begin, Iter end ) {
            
            std::vector<typename T::value_type> missing;
            Iter iter = begin;
            
            while (iter != end) {
                
                if (std::find(Matcher<T>::actual().begin(), Matcher<T>::actual().end(), *iter) == Matcher<T>::actual().end()) {
                    
                    missing.push_back(*iter);
                    
                }
                
                iter++;
                
            }
            
            if (missing.empty()) {
                return;
            }
            
            std::ostringstream os;
            
            if (begin != end) {
                os << "expected ";
                std::copy(begin, end-1, std::ostream_iterator<typename T::value_type>(os, ", "));
                os << *(end-1);
            }
            
            os << " but was missing ";
            std::copy(missing.begin(), missing.end()-1, std::ostream_iterator<typename T::value_type>(os, ", "));
            os << *(missing.end()-1);
            
            throw std::runtime_error(os.str());
        }
        
    };
    
}

#endif
