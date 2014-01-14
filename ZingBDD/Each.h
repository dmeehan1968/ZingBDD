//
//  Each.h
//  ZingBDD
//
//  Created by Dave Meehan on 09/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef ZingBDD_Each_h
#define ZingBDD_Each_h

#include <utility>

namespace ZingBDD {
    
	class Each {
		
	public:
		using block_type = std::function<void(void)>;
		
		Each(block_type block) : _block(block) {}
		
		void operator() () {
			_block();
		}
		
	private:
		block_type _block;
	};
	
}

#endif
