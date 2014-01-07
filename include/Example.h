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
		using string_type = std::string;
		using ostream_type = std::ostream;
		using block_type = std::function<void(void)>;
		
		Example(const string_type &description, Example &parent) : _description(description), _parent(&parent), _block(nullptr) {}
	
		Example(const string_type &description, Example &parent, block_type block) : _description(description), _parent(&parent), _block(block) {}
		
		virtual void run(ostream_type &os) {
			
			try {
				
				if (_block != nullptr) {
					
					_block();
					
				}
				
				os << "  OK: " << description() << std::endl;
				
			} catch (std::exception &e) {
				
				os << "FAIL: " << description() << ", " << e.what() << std::endl;
				
			}
			
		}
		
		string_type description() {
			
			if (_parent != nullptr) {
				
				string_type desc = _parent->description();
				
				if (_description.size() > 0) {
					
					if (desc.size()) {
						
						desc += " : ";
						
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
