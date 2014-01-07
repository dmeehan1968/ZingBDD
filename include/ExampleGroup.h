//
//  ExampleGroup.h
//  RSpeCpp
//
//  Created by Dave Meehan on 06/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef RSpeCpp_ExampleGroup_h
#define RSpeCpp_ExampleGroup_h

#include <fstream>

namespace RSpeCpp {
	
	class ExampleGroup : public Example {
		
	public:
		using string_type = Example::string_type;
		using block_type = std::function<void(ExampleGroup *)>;
		using self_type = ExampleGroup;
		using examples_type = std::vector<Example *>;
		using beforeEach_block_type = std::function<void(void)>;
		using beforeEaches_type = std::vector<beforeEach_block_type>;
		
		ExampleGroup(const string_type &description, block_type block = nullptr, self_type *parent = nullptr) : Example(description, nullptr, parent) {
			
			_block = block;
			
			if (parent == nullptr && description != "root") {
				
				getInstance().addExampleGroup(*this);
				
			}
			
		}
		
		void addExampleGroup(const string_type &description, block_type block) {
			
			_examples.push_back(new ExampleGroup(description, block, this));
			
		}
		
		void addExample(const string_type &description, Example::block_type block) {
			
			_examples.push_back(new Example(description, block, this));
			
		}
		
		virtual void build() override {
			
			specify(this);
			
			if (_block != nullptr) {
				
				_block(this);
				
			}
			
			for (auto example : _examples) {
				
				example->build();
				
			}
			
		}
		
		virtual void run(std::ostream &os) override {
			
			for (auto example : _examples) {
				
				example->run(os);
				
			}
			
		}
		
		static self_type &getInstance() {
			
			static self_type *_instance = nullptr;
			
			if (_instance == nullptr) {
				
				_instance = new self_type("root", nullptr, nullptr);
				
			}
			
			return *_instance;
			
		}
		
		virtual void specify(ExampleGroup *group) {}
		
		void beforeEach(beforeEach_block_type block) {
			
			_beforeEaches.push_back(block);
			
		}
		
		virtual void doBeforeEaches() override {
		
			Example::doBeforeEaches();
			
			for (auto beforeEach : _beforeEaches) {
				
				beforeEach();
				
			}
			
		}
		
	protected:
		
		void addExampleGroup(self_type &group) {

			_examples.push_back(&group);
			
		}
		
	private:
		
		examples_type _examples;
		block_type _block;
		beforeEaches_type _beforeEaches;
		
	};
	
}

#endif
