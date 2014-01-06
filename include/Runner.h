//
//  Runner.h
//  RSpeCpp
//
//  Created by Dave Meehan on 06/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef RSpeCpp_Runner_h
#define RSpeCpp_Runner_h

namespace RSpeCpp {
	
	class Runner {
		
	public:
		void run(std::ostream &os) {
			
			ExampleGroup &root = ExampleGroup::getInstance();
			root.build();
			root.run(os);
			
		}
	};
	
}


#endif
