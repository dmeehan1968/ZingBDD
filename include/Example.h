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
		using block_type = std::function<void(void)>;
		
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
		
		virtual void build() {
			
		}
		
		virtual void run(std::ostream &os) {
			
			try {
				
				doBeforeEaches();
				
				if (_block != nullptr) {
					
					_block();
					
				}
				
				os << "OK  : " << getDescription();
				
				
			} catch (std::exception &e) {
				
				os << "FAIL: " << getDescription() << ": " << e.what();
				
			}
			
			os << std::endl;
			
		}
		
		virtual void doBeforeEaches() {

			if (_parent != nullptr) {
				
				_parent->doBeforeEaches();
				
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
