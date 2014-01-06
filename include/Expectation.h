//
//  Expectation.h
//  RSpeCpp
//
//  Created by Dave Meehan on 06/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef RSpeCpp_Expectation_h
#define RSpeCpp_Expectation_h

namespace RSpeCpp {
	
	template <typename T>
	class Expectation {
		
	public:
		Expectation( const T &actual ) : _actual(actual) {}
		
		class ExpectationException : public std::runtime_error {
			using std::runtime_error::runtime_error;
		};
		
		void toEqual( const T &expected ) {
			
			if (_actual != expected) {
				
				std::stringstream ss;
				
				ss << "expected " << expected << ", got " << _actual;
				
				throw ExpectationException(ss.str());
				
			}
			
		}
				
	private:
		
		const T &_actual;
	};
	
}

#endif
