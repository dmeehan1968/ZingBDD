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
	
	template <typename T, bool logical>
	class BeNilMatcher {
		
	public:
		BeNilMatcher( const T& actual ) : _actual(&actual) {}
		
		void beNil() {
			
			if ((_actual != nullptr) == logical) {
				
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
	
	template <typename T, bool logical, template <typename, bool> class... Matchers>
	class Verifier : public Matchers<T, logical>... {
		
	public:
		Verifier( const T& actual ) : Matchers<T, logical>(actual)... {}
		
	};
	
	template <typename T>
	class Expectation {
		
	public:
		template <bool logical>
		using verifier_type = Verifier<T, logical, EqualMatcher>;
		
		Expectation( const T &actual ) : should(actual), shouldNot(actual) {}

		verifier_type<true> should;
		verifier_type<false> shouldNot;
		
	};
	
	template <typename T>
	class Expectation<T *> {
	
	public:
		template <bool logical>
		using verifier_type = Verifier<T, logical, EqualMatcher, BeNilMatcher>;
		
		Expectation( const T *actual ) : should(*actual), shouldNot(*actual) {}
		
		verifier_type<true> should;
		verifier_type<false> shouldNot;
		
	};
}

#endif
