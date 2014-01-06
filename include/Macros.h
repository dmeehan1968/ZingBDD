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
	
#define describe(group)										\
	class CLASS(group) : public RSpeCpp::ExampleGroup {		\
	using RSpeCpp::ExampleGroup::ExampleGroup;				\
	virtual void specify(Example *example);					\
	};														\
	static CLASS(group) INSTANCE(group)(#group);			\
	void CLASS(group)::specify(Example *example)
	
#define context(x, ...)										\
	example->addExampleGroup((x), [&](Example *example) __VA_ARGS__)
	
#define it(x, ...)											\
	example->addExample((x), [&](Example *example) __VA_ARGS__)
	
}

#define beforeEach(...)										\
	beforeEach([&]() __VA_ARGS__)


#endif
