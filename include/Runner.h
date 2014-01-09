//
//  Runner.h
//  RSpeCpp
//
//  Created by Dave Meehan on 06/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef RSpeCpp_Runner_h
#define RSpeCpp_Runner_h

#include "Example.h"
#include "Reporter.h"

namespace RSpeCpp {
	
	class Runner {
		
	public:
		using examples_type = std::vector<Example *>;
		
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
		
		void run(Reporter &reporter) {
			
			for ( auto example : _examples ) {
				
				example->run(reporter);
				
			}
			
			reporter.summary();
		}
		
	private:
		
		Runner() {}
		
		examples_type _examples;
		
	};
	
}


#endif
