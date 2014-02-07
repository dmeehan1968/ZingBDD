//
//  main.cpp
//  ZingBDD
//
//  Created by Dave Meehan on 05/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//
//  This software is released under the terms of the:
//
//  GNU GENERAL PUBLIC LICENSE
//  Version 3, 29 June 2007
//
//  Please read LICENSE.md for full terms and conditions.
//

#include <iostream>

#include "ZingBDD/ZingBDD.h"

int main(int argc, const char * argv[])
{

	ZingBDD::StreamReporter reporter(std::cout);
	ZingBDD::Runner::getInstance().run(reporter);
	
    return 0;
}


