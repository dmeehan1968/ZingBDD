//
//  AfterEach.h
//  ZingBDD
//
//  Created by Dave Meehan on 09/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//
//  This software is released under the terms of the:
//
//  GNU GENERAL PUBLIC LICENSE
//  Version 3, 29 June 2007
//
//  Please read LICENSE.md for full terms and conditions.
//

#ifndef ZingBDD_AfterEach_h
#define ZingBDD_AfterEach_h

#include "Each.h"

namespace ZingBDD {
	
	class AfterEach : public Each {
		
	public:
        
        AfterEach(block_type block) : Each(block) {}
        
    };
	
}

#endif
