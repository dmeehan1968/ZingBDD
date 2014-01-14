//
//  Specification.h
//  ZingBDD
//
//  Created by Dave Meehan on 07/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef ZingBDD_Specification_h
#define ZingBDD_Specification_h

#include "ExampleGroup.h"
#include "Runner.h"

namespace ZingBDD {
	
	class Specification : public ExampleGroup {
		
	public:
		
		Specification(const string_type &description) : ExampleGroup(description) {
		
			Runner::getInstance().add(*this);
			
		}
		
	};
}

#endif
