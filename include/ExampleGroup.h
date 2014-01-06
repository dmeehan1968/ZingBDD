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
	
	class BeforeEach {
		
	public:
		using block_type = std::function<void(void)>;
		
		BeforeEach(block_type block) {
		
			_block = block;
			
		}
		
		virtual void run() {
		
			if (_block != nullptr) {
				
				std::cout << "beforeEach()" << std::endl;
				
				_block();
				
			}
			
		}
		
	private:
		block_type _block;
		
	};
	
	class ExampleGroup : public Example {
		
	public:
		using string_type = Example::string_type;
		using block_type = Example::block_type;
		using self_type = ExampleGroup;
		using examples_type = std::vector<Example *>;
		using beforeEaches_type = std::vector<BeforeEach *>;
		
		ExampleGroup(const string_type &description, block_type block = nullptr, self_type *parent = nullptr) : Example(description, block, parent) {
			
			if (parent == nullptr && description != "root") {
				
				getInstance().addExampleGroup(*this);
				
			}
			
		}
		
		void addExampleGroup(const string_type &description, block_type block) {
			
			_examples.push_back(new ExampleGroup(description, block, this));
			
		}
		
		void addExample(const string_type &description, block_type block) {
			
			_examples.push_back(new Example(description, block, this));
			
		}
		
		void beforeEach(BeforeEach::block_type block) {
			
			_beforeEaches.push_back(new BeforeEach(block));
			
		}
		
		virtual void build() {
			
			specify(this);
			
			std::ofstream null;
			Example::run(null);
			
			for (auto example : _examples) {
				
				example->build();
				
			}
			
		}
		
		virtual void run(std::ostream &os) {
			
			for (auto example : _examples) {
				
				doBeforeEach();
				
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
		
		virtual void specify(ExampleGroup *example) {}
		
	protected:
		
		void addExampleGroup(self_type &group) {
			
			_examples.push_back(&group);
			
		}
		
		void doBeforeEach() {
			
			Example::doBeforeEach();
			
			for (auto before : _beforeEaches) {
				
				before->run();
				
			}
		}
		
	private:
		
		examples_type _examples;
		beforeEaches_type _beforeEaches;
		
	};
	
}

#endif
