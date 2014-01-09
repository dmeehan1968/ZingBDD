//
//  main.cpp
//  RSpeCpp
//
//  Created by Dave Meehan on 05/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#include <iostream>

#include "ZingBDD.h"

int main(int argc, const char * argv[])
{

	RSpeCpp::StreamReporter reporter(std::cout);
	RSpeCpp::Runner::getInstance().run(reporter);
	
    return 0;
}


