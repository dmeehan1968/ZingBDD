//
//  Scanner.h
//  RSpeCpp
//
//  Created by Dave Meehan on 07/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef RSpeCpp_Scanner_h
#define RSpeCpp_Scanner_h

#include <set>

namespace StringCalculator {
    
    template
    <
        class input_type,
        class output_type
    >
    class Scanner {
     
    public:
        using iterator_type = typename input_type::iterator;
        using value_type = typename input_type::value_type;
        using valueset_type = std::set<value_type>;
        
        Scanner(const input_type &input) : _input(input), _iterator(_input.begin()) {}
        
        bool scan(valueset_type const &valueset, value_type &value) {

            if (valueset.find(*_iterator) != valueset.end()) {
                
                value = *_iterator;
                
                _iterator++;
                
                return true;
                
            }
            
            return false;
            
        }
        
        bool scan(valueset_type const &valueset, output_type * const output) {
            
            iterator_type const start = _iterator;
            
            while ( ! atEnd() ) {
            
                value_type value;
                
                if (scan(valueset, value)) {
                    
                    if (output != nullptr) {
                        
                        output->push_back(value);
                        
                    }
                    
                } else {
                    
                    break;
                    
                }
            }
            
            return _iterator != start;
            
        }
        
        bool atEnd() const {
        
            return _iterator == _input.end();
            
        }
        
    private:
        
        input_type _input;
        iterator_type _iterator;
        
    };
}


#endif
