//
//  NilMatcher.h
//  RSpeCpp
//
//  Created by Dave Meehan on 07/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef RSpeCpp_NilMatcher_h
#define RSpeCpp_NilMatcher_h

namespace RSpeCpp {

    template <typename T, bool logical>
	class NilMatcher {
		
	public:
		NilMatcher( const T& actual ) : _actual(&actual) {}
		
		void beNil() {
			
			if ((_actual != nullptr) == logical) {
				
				throw std::runtime_error(error());
			}
			
		}
		
		void beNonNil() {
			
			if ((_actual == nullptr) == logical) {
				
				throw std::runtime_error(error());
			}
			
		}
		
		std::string error() {
			if (logical) {
				return "expected Nil";
			} else {
				return "expected not to be Nil";
			}
		}
		
	private:
		const T* _actual;
	};
    

}

#endif
