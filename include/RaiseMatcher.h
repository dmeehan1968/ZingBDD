//
//  RaiseMatcher.h
//  RSpeCpp
//
//  Created by Dave Meehan on 07/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef RSpeCpp_RaiseMatcher_h
#define RSpeCpp_RaiseMatcher_h

namespace RSpeCpp {
    
    template <typename T, bool logical>
    class RaiseMatcher {
        
    public:
        
        RaiseMatcher( const T& actual ) : _actual(actual) {}
        
        void raise(std::string what = "") {
            
            try {
                
                _actual();
                
            } catch (std::exception &e) {
                
                if (what.size() == 0 || e.what() == what) {
                    return;
                }
                
                std::ostringstream os;
                
                os << "Expected '" << what << "', got '" << e.what() << "'";
                throw std::runtime_error(os.str());
                
            }
            
            throw std::runtime_error("exception was not received");
            
        }
        
    private:
        
        const T& _actual;
        
    };

}

#endif
