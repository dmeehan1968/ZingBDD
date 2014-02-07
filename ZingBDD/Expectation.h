//
//  Expectation.h
//  ZingBDD
//
//  Created by Dave Meehan on 06/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//
//  This software is released under the terms of the:
//
//  GNU GENERAL PUBLIC LICENSE
//  Version 3, 29 June 2007
//
//  Please read LICENSE.md for full terms and conditions.
//

#ifndef ZingBDD_Expectation_h
#define ZingBDD_Expectation_h

#include "EqualMatcher.h"
#include "NilMatcher.h"
#include "RaiseMatcher.h"
#include "BooleanMatcher.h"
#include "Verifier.h"
#include "ContainerMatcher.h"
#include "ComparisonMatcher.h"
#include "StringMatcher.h"

namespace ZingBDD {
		
	template <typename T>
	class Expectation {
		
	public:
		using verifier_type = Verifier<T, EqualMatcher, BooleanMatcher, NilMatcher, RaiseMatcher, ContainerMatcher, ComparisonMatcher, StringMatcher>;
		
		Expectation( const T &actual ) : should(actual, true), shouldNot(actual, false) {}

		verifier_type should;
		verifier_type shouldNot;
		
	};
	
}

#endif
