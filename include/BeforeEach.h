//
//  BeforeEach.h
//  RSpeCpp
//
//  Created by Dave Meehan on 07/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef RSpeCpp_BeforeEach_h
#define RSpeCpp_BeforeEach_h

namespace RSpeCpp {
	
	class BeforeEach {
		
	public:
		using block_type = std::function<void(void)>;
		
		BeforeEach(block_type block) : _block(block) {}
		
		void operator() () {
            std::cout << "beforeEach" << std::endl;
			_block();
		}
		
	private:
		block_type _block;
	};
	
}

#endif
