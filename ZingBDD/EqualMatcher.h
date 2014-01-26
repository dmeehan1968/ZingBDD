//
//  EqualMatcher.h
//  ZingBDD
//
//  Created by Dave Meehan on 07/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef ZingBDD_EqualMatcher_h
#define ZingBDD_EqualMatcher_h

#include <sstream>

#include "Matcher.h"
#include "PrettyPrint.h"

namespace ZingBDD {
    
    template <typename T>
	class EqualMatcher : public Matcher<T> {
		
	public:
        EqualMatcher( const T& actual, bool logical ) : Matcher<T>(actual, logical) {}
        
		void equal( const T& expected ) {
			
			if ((this->actual() != expected) == this->logical()) {
				
				throw std::runtime_error(error(expected));
				
			}
		}
		
		std::string error(const T& expected) {
			std::ostringstream ss;
			if (this->logical()) {
				ss << "expected '" << expected << "', got '" << this->actual() << "'";
			} else {
				ss << "should not be equal to '" << expected << "'";
			}
			return ss.str();
		}

	};
	
}

#endif
