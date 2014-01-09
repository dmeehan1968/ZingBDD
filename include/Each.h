//
//  Each.h
//  RSpeCpp
//
//  Created by Dave Meehan on 09/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef RSpeCpp_Each_h
#define RSpeCpp_Each_h

namespace RSpeCpp {
    
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
