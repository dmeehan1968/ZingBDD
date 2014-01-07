//
//  StreamReporter.h
//  RSpeCpp
//
//  Created by Dave Meehan on 07/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef RSpeCpp_StreamReporter_h
#define RSpeCpp_StreamReporter_h


namespace RSpeCpp {
	
	class StreamReporter : public Reporter {
		
	public:
		
		StreamReporter(std::ostream &os) : _os(os) {}
		
		virtual void pass(const string_type &description) override {
			
			Reporter::pass(description);
			
			_os << "  OK: " << description << "." << std::endl;
			
		}
		
		virtual void fail(const string_type &description, const string_type &what) override {
			
			Reporter::fail(description, what);
			
			_os << "FAIL: " << description << ".\n      ERROR >> " << what << std::endl;
			
		}
		
		virtual void summary() override {
			
            _os << "-----" << std::endl;
            
			if (failed() > 0) {
				
				_os << "Failed: " << failed() << " of " << total() << " (" << passed() << " passed)" << std::endl << std::endl;

				for (auto failure : failures()) {
					
					_os << failure.description() << ".\n      << ERROR >> " << failure.what() << std::endl << std::endl;
					
				}
				
			} else {
				
				_os << "PASS: " << total() << " tests" << std::endl << std::endl;
				
			}
			
			_os << std::endl;
			
		}
	private:
		
		std::ostream &_os;
		
	};
}


#endif
