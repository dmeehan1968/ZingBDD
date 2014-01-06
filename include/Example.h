//
//  Example.h
//  RSpeCpp
//
//  Created by Dave Meehan on 06/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef RSpeCpp_Example_h
#define RSpeCpp_Example_h

namespace RSpeCpp {

	class Example {
		
	public:
		using self_type = Example;
		using string_type = std::string;
		using block_type = std::function<void(Example *)>;
		
		Example(const string_type &description, block_type block, self_type *parent) {
			
			_description = description;
			_block = block;
			_parent = parent;
			
		}
		
		string_type getDescription() {
			
			if (_parent != nullptr) {
				
				return _parent->getDescription() + " : " + _description;
				
			}
			return _description;
			
		}
		
		virtual void specify(Example *example) {
			
		}
		
		virtual void build() {
			
			specify(this);
			
		}
		
		virtual void run(std::ostream &os) {
			
			try {
				
				if (_block != nullptr) {
					
					_block(this);
					
				}
				
				os << "OK: " << getDescription() << ": ";
				
				
			} catch (std::exception &e) {
				
				os << "ERROR: " << getDescription() << ", " << e.what();
				
			}
			
			os << std::endl;
			
		}
		
		virtual void addExample(const string_type &description, block_type block) {}
		
		virtual void addExampleGroup(const string_type &description, block_type block = nullptr, Example *parent = nullptr) {}
		
		virtual void doBeforeEach() {

			if (_parent != nullptr) {
				
				_parent->doBeforeEach();
				
			}
			
		}
		
		template <typename T>
		Expectation<T> expect( T actual ) {
			
			return Expectation<T>( actual );
			
		}
		
	private:
		
		string_type _description;
		block_type _block;
		self_type *_parent;
		
	};

}

#endif
