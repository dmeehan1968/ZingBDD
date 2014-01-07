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
		using examples_type = std::vector<Example *>;
		using ostream_type = std::ostream;
		
		static Runner &getInstance() {
			
			static Runner *_instance = nullptr;
			
			if (_instance == nullptr) {
				
				_instance = new Runner;
				
			}
			
			return *_instance;
			
		}
		
		void add(Example &example) {
			
			_examples.push_back(&example);
			
		}
		
		void run(ostream_type &os) {
			
			for ( auto example : _examples ) {
				
				example->run(os);
				
			}
		}
		
	private:
		
		Runner() {}
		
		examples_type _examples;
		
	};
	
}


#endif
