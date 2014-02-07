//
//  HelloWorldSpec.cpp
//  ZingBDD
//
//  Created by Dave Meehan on 09/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//
//  This software is released under the terms of the:
//
//  GNU GENERAL PUBLIC LICENSE
//  Version 3, 29 June 2007
//
//  Please read LICENSE.md for full terms and conditions.
//

#include <memory>

#include "ZingBDD/ZingBDD.h"

#include "../src/HelloWorld.h"

describe(HelloWorld, {

    std::shared_ptr<HelloWorld> sut;
    
    beforeEach({
       
        sut = std::make_shared<HelloWorld>();
        
    });
    
    it("exists", {
       
        expect( (bool)sut ).should.beTrue();
        
    });
    
    it("outputs message", {
       
        expect( sut->hello() ).should.equal( "Hello World!" );
        
    });
    
});

