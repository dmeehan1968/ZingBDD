//
//  CharacterSet.h
//  ZingBDD
//
//  Created by Dave Meehan on 10/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//
//  This software is released under the terms of the:
//
//  GNU GENERAL PUBLIC LICENSE
//  Version 3, 29 June 2007
//
//  Please read LICENSE.md for full terms and conditions.
//

#ifndef ZingBDD_CharacterSet_h
#define ZingBDD_CharacterSet_h

namespace StringCalculator {

    class CharacterSet : public std::set<char> {
        
    public:
        
        CharacterSet(const std::string initial) : std::set<char>(initial.begin(), initial.end()) {}
        
        static CharacterSet decimalDigitCharacterSet() {
            
            return CharacterSet("-+0123456789");
            
        }
    };

}

#endif
