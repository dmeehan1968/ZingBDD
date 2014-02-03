//
//  NilMatcher.h
//  ZingBDD
//
//  Created by Dave Meehan on 07/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef ZingBDD_NilMatcher_h
#define ZingBDD_NilMatcher_h

#include "Matcher.h"

namespace ZingBDD {

    template <typename T>
	class NilMatcher : public Matcher<T> {
    public:
        NilMatcher( const T& actual, bool logical ) : Matcher<T>(actual, logical) {}
    };
    
    template <typename T>
    class NilMatcher<T *> : public Matcher<T *> {
		
	public:
        NilMatcher( const T* actual, bool logical ) : Matcher<T *>(actual, logical) {}
		
		void beNil() {
			
			if ((&this->actual() != nullptr) == this->logical()) {
				
				throw std::runtime_error(error());
			}
			
		}
		
		void beNonNil() {
			
			if ((&this->actual() == nullptr) == this->logical()) {
				
				throw std::runtime_error(error());
			}
			
		}
		
		std::string error() {
			if (this->logical()) {
				return "expected Nil";
			} else {
				return "expected not to be Nil";
			}
		}
		
	};
    

}

#endif
