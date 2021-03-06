//
//  Example.h
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

#ifndef ZingBDD_Example_h
#define ZingBDD_Example_h

#include "Reporter.h"
#include "Expectation.h"

namespace ZingBDD {

	class Example {
		
	public:
		using string_type = std::string;
		using block_type = std::function<void(void)>;
		
		Example(const string_type &description, Example &parent) : _description(description), _parent(&parent), _block(nullptr) {}
	
		Example(const string_type &description, Example &parent, block_type block) : _description(description), _parent(&parent), _block(block) {}
		
		virtual void run(Reporter &reporter) {
			
			try {
				
				if (_block != nullptr) {
					
					_block();
					
				}
				
				reporter.pass(description());
				
			} catch (std::exception &e) {

				reporter.fail(description(), e.what());

			}
			
		}
		
		string_type description() {
			
			if (_parent != nullptr) {
				
				string_type desc = _parent->description();
				
				if (_description.size() > 0) {
					
					if (desc.size()) {
						
						desc += " > ";
						
					}
					
					desc += _description;
					
				}
				
				return desc;
				
			}

			return _description;
			
		}
		
		template <typename T>
		Expectation<T> expect( const T &actual ) {
			
			return Expectation<T>(actual);
			
		}
        
        Example *parent() {
            
            return _parent;
            
        }
        
	protected:
		
		Example(const string_type &description) : _description(description), _parent(nullptr), _block(nullptr) {}
		
		Example() : _parent(nullptr), _block(nullptr) {}
		
	private:
		
		string_type _description;
		Example *_parent;
		block_type _block;
		
	};
	
}

#endif
