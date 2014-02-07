//
//  StringMatcher.h
//  ZingBDD
//
//  Created by Dave Meehan on 11/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//
//  This software is released under the terms of the:
//
//  GNU GENERAL PUBLIC LICENSE
//  Version 3, 29 June 2007
//
//  Please read LICENSE.md for full terms and conditions.
//

#ifndef ZingBDD_StringMatcher_h
#define ZingBDD_StringMatcher_h

namespace ZingBDD {
    
    
    template <typename T>
    class StringMatcher : public Matcher<T> {

    public:
        StringMatcher( const T& actual, bool logical ) : Matcher<T>(actual, logical) {}
    };
    
    template <>
    class StringMatcher<std::string> : public Matcher<std::string> {
        
    public:
        using T = std::string;
        
        StringMatcher( const T& actual, bool logical ) : Matcher<T>(actual, logical) {}
        
        void containString(const std::string &expected) {
            
            if ((this->actual().find(expected) == T::npos) == this->logical()) {
                
                std::ostringstream os;
                
                os  << "'" << expected << "' "
                    << (this->logical() ? "" : "NOT ")
                    << "found";
                
                throw std::runtime_error(os.str());
                
            }
        }
        
        void beginWithString(const std::string &expected) {
        
            if ((this->actual().find(expected) != 0) == this->logical()) {
                
                std::ostringstream os;
                
                os  << "'" << expected << "' "
                    << (!this->logical() ? "" : "NOT ")
                    << "found";
                
                throw std::runtime_error(os.str());
                
            }
            
        }
        
        void endWithString(const std::string &expected) {

            size_t pos = this->actual().find(expected);
            
            if ((pos != (this->actual().size() - expected.size())) == this->logical()) {
                
                std::ostringstream os;
                
                os  << "'" << expected << "' "
                << (!this->logical() ? "" : "NOT ")
                << "found";
                
                throw std::runtime_error(os.str());
                
            }
            
            
        }
    };
}



#endif
