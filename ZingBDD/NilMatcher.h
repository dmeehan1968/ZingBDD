//
//  NilMatcher.h
//  ZingBDD
//
//  Created by Dave Meehan on 07/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//
//  This software is released under the terms of the:
//
//  GNU GENERAL PUBLIC LICENSE
//  Version 3, 29 June 2007
//
//  Please read LICENSE.md for full terms and conditions.
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
				
				throw std::runtime_error(error(true));
			}
			
		}
		
		void beNonNil() {
			
			if ((&this->actual() == nullptr) == this->logical()) {
				
				throw std::runtime_error(error(false));
			}
			
		}
		
		std::string error(bool inverse) {
			if (this->logical() == inverse) {
				return "expected Nil";
			} else {
				return "expected Not to be Nil";
			}
		}
		
	};
    

}

#endif
