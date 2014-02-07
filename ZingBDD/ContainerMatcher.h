//
//  ContainerMatcher.h
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

#ifndef ZingBDD_ContainerMatcher_h
#define ZingBDD_ContainerMatcher_h

#include <vector>

#include "Matcher.h"

namespace ZingBDD {
    
    template <typename T>
    class ContainerMatcher : public Matcher<T> {
    
    public:
        ContainerMatcher( const T& actual, bool logical ) : Matcher<T>(actual, logical) {}

        void beEmpty() {
        
            if ((this->actual().size() > 0) == this->logical()) {
                
                std::ostringstream os;
                
                os << "expected to be " << (this->logical() ? "" : "NOT ") << "empty";
                
                if (this->logical()) {
                    os << " but has " << this->actual().size() << " items";
                }
                
                throw std::runtime_error(os.str());
                
            }
            
        }
        
        void haveCountOf( const size_t count ) {
        
            if ((this->actual().size() != count) == this->logical()) {
                
                std::ostringstream os;
                os  << "expected to " << (this->logical() ? "" : "NOT ")
                    << "have count of " << count;
                
                if (this->logical()) {
                    os << ", got " << this->actual().size();
                }
                
                throw std::runtime_error(os.str());
                
            }
        }
        
        void haveCountOfAtLeast( const size_t count ) {
            
            if ((this->actual().size() < count) == this->logical()) {
                
                std::ostringstream os;
                os  << "expected to " << (this->logical() ? "" : "NOT ")
                    << "have at least " << count;
                
                if (!this->logical()) {
                    os << ", got " << this->actual().size();
                }
                
                throw std::runtime_error(os.str());
                
            }
        }
        
        void haveCountOfAtMost( const size_t count ) {
            
            if ((this->actual().size() > count) == this->logical()) {
                
                std::ostringstream os;
                os  << "expected to " << (this->logical() ? "" : "NOT ")
                    << "have at most " << count;
                
                if (this->logical()) {
                    os << ", got " << this->actual().size();
                }
                
                throw std::runtime_error(os.str());
                
            }
        }
        
        template <typename V>
        void contain( const V &value ) {
         
            if ((std::find(this->actual().begin(), this->actual().end(), value) == this->actual().end()) == this->logical()) {
                
                std::ostringstream os;
                os << "value " << value << " "
                    << (!this->logical() ? "" : "NOT ")
                    << "found";
                
                throw std::runtime_error(os.str());
            }

        }
        
        template <typename Iter>
        void contain( Iter begin, Iter end ) {
            
            std::vector<typename T::value_type> missing;
            Iter iter = begin;
            
            while (iter != end) {
                
                if ((std::find(this->actual().begin(), this->actual().end(), *iter) == this->actual().end()) == this->logical()) {
                    
                    missing.push_back(*iter);
                    
                }
                
                iter++;
                
            }
            
            if (missing.empty()) {
                return;
            }
            
            std::ostringstream os;
            
            if (begin == end) {

                os << "nothing expected";
                
            } else {
                
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
