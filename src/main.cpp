//
//  main.cpp
//  ZingBDD
//
//  Created by Dave Meehan on 05/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#include <iostream>

#include "ZingBDD/ZingBDD.h"

int main(int argc, const char * argv[])
{

	ZingBDD::StreamReporter reporter(std::cout);
	ZingBDD::Runner::getInstance().run(reporter);
	
    return 0;
}


