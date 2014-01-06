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
		
	
	template <typename T, bool logic>
	class BeNilMatcher {
		
	public:
		BeNilMatcher( const T& actual ) : _actual(actual) {}
		
		void operator() () {
		
			if ((_actual != nullptr) == logic) {
				
				throw std::runtime_error("should be nil");
				
			}
		}
		
	private:
		const T& _actual;
	};
	
	template <typename T, bool logic>
	class EqualMatcher {
		
	public:
		EqualMatcher(const T& actual) : _actual(actual) {}
		
		void operator() ( const T &expected ) {
			
			if ((_actual != expected) == logic) {
				
				std::ostringstream ss;
				ss << "expected " << expected << ", got " << _actual;
				
				throw std::runtime_error(ss.str());
			}
		}
		
	private:
		const T& _actual;
		
	};
	
	template <typename T, bool logic>
	class Verifier {
	
	public:
		Verifier( const T &actual ) : beNil(actual), equal(actual) {}
		
		BeNilMatcher<T, logic> beNil;
		EqualMatcher<T, logic> equal;
		
	};
	
	template <typename T>
	class Expectation {
		
	public:
		Expectation( const T &actual ) : should(actual), shouldNot(actual) {}
		
		class ExpectationException : public std::runtime_error {
			using std::runtime_error::runtime_error;
		};
		
		Verifier<T, true> should;
		Verifier<T, false> shouldNot;
		
	};
	
}

#endif
