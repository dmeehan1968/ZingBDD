//
//  Expectation.h
//  ZingBDD
//
//  Created by Dave Meehan on 06/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef ZingBDD_Expectation_h
#define ZingBDD_Expectation_h

#include "EqualMatcher.h"
#include "NilMatcher.h"
#include "RaiseMatcher.h"
#include "BooleanMatcher.h"
#include "Verifier.h"

namespace ZingBDD {
		
	template <typename T>
	class Expectation {
		
	public:
		using verifier_type = Verifier<T, EqualMatcher, BooleanMatcher, NilMatcher, RaiseMatcher>;
		
		Expectation( const T &actual ) : should(actual, true), shouldNot(actual, false) {}

		verifier_type should;
		verifier_type shouldNot;
		
	};
	
}

#endif
