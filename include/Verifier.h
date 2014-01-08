//
//  Verifier.h
//  RSpeCpp
//
//  Created by Dave Meehan on 07/01/2014.
//  Copyright (c) 2014 Replicated Solutions Limited. All rights reserved.
//

#ifndef RSpeCpp_Verifier_h
#define RSpeCpp_Verifier_h

namespace RSpeCpp {
    
    template <typename T, template <typename> class... Matchers>
	class Verifier : public Matchers<T>... {
		
	public:
		Verifier( const T& actual, bool logical ) : Matchers<T>(actual, logical)... {}
		
	};
    
}


#endif
