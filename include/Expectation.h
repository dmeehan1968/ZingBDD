//
//  Expectation.h
//  RSpeCpp
//
//  Created by Dave Meehan on 06/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef RSpeCpp_Expectation_h
#define RSpeCpp_Expectation_h

#include "EqualMatcher.h"
#include "NilMatcher.h"
#include "RaiseMatcher.h"
#include "BooleanMatcher.h"
#include "Verifier.h"

namespace RSpeCpp {
		
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
		using verifier_type = Verifier<T, logical, EqualMatcher, NilMatcher>;
		
		Expectation( const T *actual ) : should(*actual), shouldNot(*actual) {}
		
		verifier_type<true> should;
		verifier_type<false> shouldNot;
		
	};
    
    template <>
    class Expectation<bool> {
      
    public:
        using T = bool;
        
		template <bool logical>
		using verifier_type = Verifier<T, logical, BooleanMatcher>;
		
		Expectation( const T &actual ) : should(actual), shouldNot(actual) {}
		
		verifier_type<true> should;
		verifier_type<false> shouldNot;
        
    };
    
    template <>
    class Expectation<std::function<void(void)>> {
      
    public:
        using T = std::function<void(void)>;
        
		template <bool logical>
		using verifier_type = Verifier<T, logical, RaiseMatcher>;
		
		Expectation( const T &actual ) : should(actual), shouldNot(actual) {}
		
		verifier_type<true> should;
		verifier_type<false> shouldNot;
        
    };
}

#endif
