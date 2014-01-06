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
	
#define describe(group, ...)											\
	class CLASS(group) : public RSpeCpp::ExampleGroup {					\
	using RSpeCpp::ExampleGroup::ExampleGroup;							\
	virtual void specify(ExampleGroup *exampleGroup) override __VA_ARGS__			\
	};																	\
	static CLASS(group) INSTANCE(group)(#group);						\
	
#define context(x, ...)													\
	exampleGroup->addExampleGroup((x), [&](ExampleGroup *exampleGroup) __VA_ARGS__)
	
#define it(x, ...)														\
	exampleGroup->addExample((x), [&]() __VA_ARGS__)
	
}

#define beforeEach(...)													\
	exampleGroup->beforeEach([&]() __VA_ARGS__)


#endif
