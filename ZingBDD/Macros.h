//
//  Macros.h
//  ZingBDD
//
//  Created by Dave Meehan on 06/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef ZingBDD_Macros_h
#define ZingBDD_Macros_h

namespace ZingBDD {
	
#define CLASS(x)	x##Spec
#define INSTANCE(x)	x##Instance
	
#define describe(group, ...)												\
	class CLASS(group) : public ZingBDD::Specification {					\
    public:                                                                 \
    CLASS(group)(const std::string description) : Specification(description) {} \
	virtual void run(ZingBDD::Reporter &reporter, ZingBDD::ExampleGroup &__group__) override __VA_ARGS__		\
	};																		\
	static CLASS(group) INSTANCE(group)(#group)
	
#define context(x, ...)														\
	__group__.exampleGroup((x), reporter, [&](ZingBDD::Reporter &reporter, ZingBDD::ExampleGroup &__group__) __VA_ARGS__)
	
#define it(x, ...)															\
	__group__.example((x), reporter, [&] __VA_ARGS__)
	
}

#define beforeEach(...)														\
    __group__.beforeEach([&]() __VA_ARGS__)

#define afterEach(...)														\
    __group__.afterEach([&]() __VA_ARGS__)

#define theBlock(...) std::function<void(void)>([&]  __VA_ARGS__ )

#endif
