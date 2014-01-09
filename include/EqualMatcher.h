//
//  EqualMatcher.h
//  RSpeCpp
//
//  Created by Dave Meehan on 07/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef RSpeCpp_EqualMatcher_h
#define RSpeCpp_EqualMatcher_h

#include <sstream>

#include "Matcher.h"

namespace RSpeCpp {
    
    template <typename T>
	class EqualMatcher : public Matcher<T> {
		
	public:
        using Matcher<T>::Matcher;
        using Matcher<T>::actual;
        using Matcher<T>::logical;
        
		void equal( const T& expected ) {
			
			if ((actual() != expected) == logical()) {
				
				throw std::runtime_error(error(expected));
				
			}
		}
		
		std::string error(const T& expected) {
			std::ostringstream ss;
			if (logical()) {
				ss << "expected '" << expected << "', got '" << actual() << "'";
			} else {
				ss << "should not be equal to '" << expected << "'";
			}
			return ss.str();
		}

	};
	
}

#endif
