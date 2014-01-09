//
//  Specification.h
//  RSpeCpp
//
//  Created by Dave Meehan on 07/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef RSpeCpp_Specification_h
#define RSpeCpp_Specification_h

#include "ExampleGroup.h"
#include "Runner.h"

namespace RSpeCpp {
	
	class Specification : public ExampleGroup {
		
	public:
		
		Specification(const string_type &description) : ExampleGroup(description) {
		
			Runner::getInstance().add(*this);
			
		}
		
	};
}

#endif
