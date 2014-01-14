//
//  Reporter.h
//  ZingBDD
//
//  Created by Dave Meehan on 07/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef ZingBDD_Reporter_h
#define ZingBDD_Reporter_h

#include <iostream>
#include <vector>

namespace ZingBDD {
	
	class Failure {
		
	public:
		using string_type = std::string;
		
		Failure(const string_type &description, const string_type &what) : _description(description), _what(what) {}
		
		const string_type &description() const {
			return _description;
		}
		
		const string_type &what() const {
			return _what;
		}
		
	private:
		
		string_type _description;
		string_type _what;
		
	};
	
	class Reporter {
		
	public:
		using string_type = std::string;
		
		Reporter() {
			
			_total = _pass = _fail = 0;
			
		}
		
		virtual void pass(const string_type &locus) {
			
			_pass++;
			_total++;
		}
		
		virtual void fail(const string_type &locus, const string_type &what) {
			
			_failures.push_back(Failure(locus, what));
			
			_fail++;
			_total++;
			
		}
		
		unsigned int total() const { return _total; }
		unsigned int passed() const { return _pass; }
		unsigned int failed() const { return _fail; }
		
		const std::vector<Failure> &failures() const {
			
			return _failures;
			
		}
		virtual void summary() = 0;
		
		virtual ~Reporter() {}
		
	private:
		
		std::vector<Failure> _failures;
		
		unsigned int _total;
		unsigned int _pass;
		unsigned int _fail;
		
	};
}


#endif
