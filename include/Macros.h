//
//  Macros.h
//  RSpeCpp
//
//  Created by Dave Meehan on 06/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef RSpeCpp_Macros_h
#define RSpeCpp_Macros_h

namespace RSpeCpp {
	
#define CLASS(x)	x##Spec
#define INSTANCE(x)	x##Instance
	
#define describe(group, ...)												\
	class CLASS(group) : public RSpeCpp::Specification {					\
	using RSpeCpp::Specification::Specification;							\
	virtual void run(RSpeCpp::Reporter &reporter, RSpeCpp::ExampleGroup &__group__) override __VA_ARGS__		\
	};																		\
	static CLASS(group) INSTANCE(group)(#group);							\
	
#define context(x, ...)														\
	__group__.exampleGroup((x), reporter, [&](RSpeCpp::Reporter &reporter, RSpeCpp::ExampleGroup &__group__) __VA_ARGS__)
	
#define it(x, ...)															\
	__group__.example((x), reporter, [&] __VA_ARGS__)
	
}

#define beforeEach(...)														\
	__group__.beforeEach([&]() mutable __VA_ARGS__)

#define theBlock(...) std::function<void(void)>([&]  __VA_ARGS__ )

#endif
