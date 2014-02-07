//
//  Runner.h
//  ZingBDD
//
//  Created by Dave Meehan on 06/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//
//  This software is released under the terms of the:
//
//  GNU GENERAL PUBLIC LICENSE
//  Version 3, 29 June 2007
//
//  Please read LICENSE.md for full terms and conditions.
//

#ifndef ZingBDD_Runner_h
#define ZingBDD_Runner_h

#include "Example.h"
#include "Reporter.h"

namespace ZingBDD {
	
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
