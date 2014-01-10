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
        using Matcher<T>::Matcher;
    };
    
    template <typename T>
    class NilMatcher<T *> : public Matcher<T *> {
		
	public:
        using Matcher<T *>::Matcher;
        using Matcher<T *>::actual;
        using Matcher<T *>::logical;
		
		void beNil() {
			
			if ((actual() != nullptr) == logical()) {
				
				throw std::runtime_error(error());
			}
			
		}
		
		void beNonNil() {
			
			if ((actual() == nullptr) == logical()) {
				
				throw std::runtime_error(error());
			}
			
		}
		
		std::string error() {
			if (logical()) {
				return "expected Nil";
			} else {
				return "expected not to be Nil";
			}
		}
		
	};
    

}

#endif
