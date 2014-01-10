//
//  ExampleGroup.h
//  ZingBDD
//
//  Created by Dave Meehan on 06/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef ZingBDD_ExampleGroup_h
#define ZingBDD_ExampleGroup_h

#include "Example.h"
#include "Reporter.h"
#include "BeforeEach.h"
#include "AfterEach.h"

namespace ZingBDD {
	
	class ExampleGroup : public Example {
		
	public:
		using block_type = std::function<void(Reporter &, ExampleGroup &)>;
		using beforeEaches_type = std::vector<BeforeEach>;
		using afterEaches_type = std::vector<AfterEach>;
		
		ExampleGroup(const string_type &description) : Example(description), _block(nullptr) {}

		virtual void run(Reporter &reporter) override {
			
			run(reporter, *this);
			
		}

		virtual void run(Reporter &reporter, ExampleGroup &group) {

			if (_block != nullptr) {
				
				_block(reporter, group);
				
			}
		}
		
		void exampleGroup(const string_type &description, Reporter &reporter, block_type block) {
			
			ExampleGroup group(description, *this, block);
			
			group.run(reporter);
			
		}
		
		void example(const string_type &description, Reporter &reporter, Example::block_type block) {
			
			Example example(description, *this, block);
			
			doBeforeEach();
			
			example.run(reporter);
			
			doAfterEach();
			
		}
        
        void beforeEach(BeforeEach::block_type block) {
			
			_beforeEach.emplace_back(BeforeEach(block));
			
		}
        
        void afterEach(AfterEach::block_type block) {
			
			_afterEach.emplace_back(AfterEach(block));
			
		}
        
	protected:
		
		ExampleGroup(const string_type &description, ExampleGroup &parent, block_type block) : Example(description, parent), _block(block) {}
		
		void doBeforeEach() {

            if (parent() != nullptr) {
                
                ExampleGroup *parentGroup = dynamic_cast<ExampleGroup *>(parent());
                
                if (parentGroup != nullptr) {
                    parentGroup->doBeforeEach();
                }
            }
            
			for ( auto before : _beforeEach ) {
				
				before();
				
			}
		}
		
		void doAfterEach() {
			
			for ( auto after : _afterEach ) {
				
				after();
				
			}
            if (parent() != nullptr) {
                
                ExampleGroup *parentGroup = dynamic_cast<ExampleGroup *>(parent());
                
                if (parentGroup != nullptr) {
                    parentGroup->doAfterEach();
                }
            }

		}
		
	private:
		
		block_type _block;
		beforeEaches_type _beforeEach;
		afterEaches_type _afterEach;
		

	};
	
}

#endif
