//
//  HelloWorldSpec.cpp
//  RSpeCpp
//
//  Created by Dave Meehan on 09/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#include "ZingBDD.h"

#include "HelloWorld.h"

describe(HelloWorld, {

    std::shared_ptr<HelloWorld> sut;
    
    beforeEach({
       
        sut = std::make_shared<HelloWorld>();
        
    });
    
    it("exists", {
       
        expect( sut.get() ).shouldNot.beNil();
        
    });
    
    it("outputs message", {
       
        expect( sut->hello() ).should.equal( "Hello World!" );
        
    });
    
});

