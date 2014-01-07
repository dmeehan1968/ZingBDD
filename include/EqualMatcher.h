//
//  EqualMatcher.h
//  RSpeCpp
//
//  Created by Dave Meehan on 07/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef RSpeCpp_EqualMatcher_h
#define RSpeCpp_EqualMatcher_h

namespace RSpeCpp {
    
    template <typename T, bool logical>
	class EqualMatcher {
		
	public:
		EqualMatcher( const T& actual ) : _actual(actual) { }
		
		void equal( const T& expected ) {
			
			if ((_actual != expected) == logical) {
				
				throw std::runtime_error(error(expected));
				
			}
		}
		
		std::string error(const T& expected) {
			std::ostringstream ss;
			if (logical) {
				ss << "expected " << expected << ", got " << _actual;
			} else {
				ss << "should not be equal to " << expected;
			}
			return ss.str();
		}
		
	private:
		const T& _actual;
		
	};
	
}

#endif
