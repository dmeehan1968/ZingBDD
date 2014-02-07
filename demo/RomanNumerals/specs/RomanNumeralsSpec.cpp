//
//  RomanNumeralSpec.cpp
//  ZingBDD
//
//  Created by Dave Meehan on 14/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//
//  This software is released under the terms of the:
//
//  GNU GENERAL PUBLIC LICENSE
//  Version 3, 29 June 2007
//
//  Please read LICENSE.md for full terms and conditions.
//

#include "ZingBDD/ZingBDD.h"

#include "demo/RomanNumerals/src/RomanNumerals.h"

describe(RomanNumerals, {
    
    using RomanNumerals::RomanNumerals;
    
    std::shared_ptr<RomanNumerals> sut;
    
    struct Inputs {
        std::string context;
        int input;
        std::string result;
    };
    
    std::vector<struct Inputs> inputs = {
        {
            "1 equals I",
            1,
            "I"
        },
        {
            "2 equals II",
            2,
            "II"
        },
        {
            "3 equals III",
            3,
            "III"
        },
        {
            "4 equals IV",
            4,
            "IV"
        },
        {
            "5 equals V",
            5,
            "V"
        },
        {
            "6 equals VI",
            6,
            "VI"
        },
        {
            "7 equals VII",
            7,
            "VII"
        },
        {
            "8 equals VIII",
            8,
            "VIII"
        },
        {
            "9 equals IX",
            9,
            "IX"
        },
        {
            "10 equals X",
            10,
            "X"
        },
        {
            "50 equals L",
            50,
            "L"
        },
        {
            "100 equals C",
            100,
            "C"
        },
        {
            "500 equals D",
            500,
            "D"
        },
        {
            "1000 equals M",
            1000,
            "M"
        },
        {
            "2014 equals MMXIV",
            2014,
            "MMXIV"
        },
        {
            "1988 equals MCMLXXXVIII",
            1988,
            "MCMLXXXVIII"
        },
        {
            "1998 equals MCMXCVIII",
            1998,
            "MCMXCVIII"
        },
        {
            "449 equals CDXLIX",
            449,
            "CDXLIX"
        },
        {
            "3333 equals MMMCCCXXXIII",
            3333,
            "MMMCCCXXXIII"
        },
        {
            "3999 equals MMMCMXCIX",
            3999,
            "MMMCMXCIX"
        },
    };
    
    beforeEach({
        
        sut = std::make_shared<RomanNumerals>();
        
    });
    
    for (auto expected : inputs ) {
        
        it(expected.context, {
            
            expect( sut->roman(expected.input) ).should.equal( expected.result );
            
        });
        
    }
    
    it("throws if arabic less than 1", {
        
        expect(theBlock({
            
            sut->roman(0);
            
        })).should.raise<std::range_error>("Arabic should be in range 1 to 3999");
        
    });
    
    it("throws if arabic greater than 3999", {
        
        expect(theBlock({
            
            sut->roman(4000);
            
        })).should.raise<std::range_error>("Arabic should be in range 1 to 3999");
        
    });
    
});
