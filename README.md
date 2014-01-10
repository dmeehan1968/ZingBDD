# About

ZingBDD is a minimal BDD framework for C++ inspired by [RSpec](http://rspec.info).

## Features

* Simple code constructs to keep your specs (tests) clean and easy to read.
* Type specific matchers so you can only apply appropriate expectations on your test objects.

Please note: This is an early alpha version.  I'd encourage you to give it a try and provide feedback on problems that you encounter.  Use Github Issues to report problems, feedback and ask questions.

## Requirements

1. You'll need a C++11 compliant compiler to use ZingBDD, as it uses language constructs only available there.
2. There is an Xcode 5 project included that builds the demos.

# Getting Started

## Installation

ZingBDD is implemented as header only, so no libraries to build.  Just make the include folder available to your project and include `ZingBDD.h` in your specification modules (these are the unit tests).

## The Basic Setup

You'll need a few things to get going with *ZingBDD*.

1.	A build target for your unit tests to run in.  Typically you will create a minimal `main.cpp` that contains the *runner* used to invoke the unit tests.
2.	A *reporter* and *runner* that invokes the unit tests.
3.	Test *specifications* that describe what the system being tested should do.

## Test Runner and Reporter

In `main.cpp` (or anywhere else if you have a more complicated test setup), create a *reporter* instance and ask the test *runner* to run with it.

	#include <iostream>
	#include "ZingBDD.h"
	
	int main(int argc, const char *argv[]) {
	
		CppSpec::StreamReporter reporter(std::cout);
		CppSpec::Runner::getInstance().run(reporter);
	
		return 0;

	}

## Specifications

A *specification* is a unit of code that describes tests that the system under test should pass.

Create test specifications in `.cpp` files so that they are automatically included in the build.  Make sure these are included in the build target.

	#include "ZingBDD.h"
	
	describe( SubjectClass, {
	
	});

The `describe` block is the principle container.
You can include one or more specifications in each spec module.  Note that the supplied *SubjectClass* does not need to match the name of a class being tested, but logically it helps to do so when interpreting results.

## Example

	it("description", {
	
	});

Examples are the individual tests that you want to perform.  Each example contains one or more *expectations* that are evaluated.  It is best to try and have one expectation per example, and describe the example with what you expect the outcome to be.

A failing expectation will prevent further code within the same example from running, so that one failure doesn't lead to multiple failure reports which might be dependent.  This can help to focus on the area of failure.

## Example Group

	context("description", {
	
	});

*Example Groups* allow you to organise tests around functional areas within a specification.

## Hello World

Here is a complete specification to illustrate the structure.  First, let's create a specification to describe what the software should do.

	#include "CppSpec.h"
	#include "HelloWorld.h"
	
	describe( HelloWorld, {
	
		it("outputs message", {
		
			HelloWorld sut;
			
			expect( sut.hello() ).should.equal( "Hello World" );
			
		});
		
	});

We also need a source module for the `HelloWorld` class, called `HelloWorld.h`.

	class HelloWorld {
	
	public:
	
		std::string hello() {
		
			return "Hello World!";
			
		}
	
	};

That should be sufficient to build and run.  You should see output similar to:

	FAIL: HelloWorld > outputs message.
	      ERROR >> expected 'Hello World!', got 'Hello World'
	-----
	Failed: 1 of 1 (0 passed)

	HelloWorld > outputs message.
	      << ERROR >> expected 'Hello World!', got 'Hello World'

Oops!  I was rather hoping that would work, but look, I made a typo by missing the exclamation mark from the expected message.  I'll fix that, then re-run the test:

	  OK: HelloWorld > outputs message
	-----
	PASS: 1 tests

Cool!

# Expectations

Test *expectations* are constructed from a chain similar to:

	expect( *subject* ).*verifier*.*matcher*

So in our Hello World example, *subject* was a variable or function result, *verifier* was *should* and *matcher* was *equal()*.  You can split the statement over more than one line if it helps with readability, e.g.:

	expect( sut.hello() )
		.should
		.equal( "Hello World" );

## Verifiers

	.should
	.shouldNot

*Verifiers* determine whether the outcome should be expected or unexpected.

## Matchers

*Matchers* compare an expected value with the actual value provided by the *subject*.  *Matchers* are type specific and depend on the subject and value being appropriately compatible.  For example, any value that supports the equality operator (==) can be compared with the `equal()` matcher.

### Equivalence

	expect( subject ).should.equal( value );

*subject* should support the left shift operator (<<) to a `std::ostream` so that it's value can be printed on failure.  If the subject doesn't support ostream output, you will need to make the comparison yourself and use a Boolean test. E.g.:

	expect ( aValue == otherValue ).should.beTrue();

### Boolean

	expect( subject ).should.beTrue();
	expect( subject ).should.beFalse();
	expect( subject ).should.beNil();

*subject* must be a Boolean value, not some other type that might be convertible to Boolean. Cast if necessary.

### Comparison

	expect( subject ).should.beLessThan( value );
	expect( subject ).should.beLessThanOrEqualTo( value );
	expect( subject ).should.beGreaterThan( value );
	expect( subject ).should.beGreaterThanOrEqualTo( value );
	expect( subject ).should.beWithin( delta, value );

### Collections

	expect( subject ).should.beEmpty();
	expect( subject ).should.contain( value | values );
	expect( subject ).should.haveCountOf( n );
	expect( subject ).should.haveCountOfAtLeast( n );
	expect( subject ).should.haveCountOfAtMost( n );

### Substring Matching

	expect( subject ).should.containString( value, options );
	expect( subject ).should.beginWithString( value, options );
	expect( subject ).should.endWithString( value, options );

### Regular Expressions

	expect( subject ).should.match( regexp, options );

### Count Changes

	expect( theBlock( {subject} ) )
		.should.change( [&]{ return object.value; }, delta);

### Exceptions

	expect( theBlock({ /* code */ }) )
		.should.raise<std::runtime_error>("what");

## Setup and Tear Down

Each `describe`, `context` or `it` can contain arbitrary code to establish the state necessary for the test.  In addition, there are `beforeEach` and `afterEach` blocks that can be used to repeat setup and tear down code before each *example* is invoked.

Let's refactor our Hello World specification to take advantage of that.

	#include "ZingBDD.h"
	#include "HelloWorld.h"
	
	describe( HelloWorld, {
	
		HelloWorld *sut;
		
		beforeEach({
		
			sut = new HelloWorld;
			
		});
		
		afterEach({
		
			delete sut;
			
		});
		
		it("outputs message", {
			
			expect( sut->hello() ).should.equal( "Hello World" );
			
		});
		
	});

For this simple example it's a bit more long-winded, but hopefully you'll see how you can apply that to more complicated scenarios.

If you have nested contexts, ALL `beforeEach` blocks are invoked prior to each and every `it` block that they contain, and those further down the heirarchy, and likewise of `afterEach` blocks. E.g.

	describe("example", {
	
		beforeEach("A", {
		
			std::cout << "before A" << std::endl;
		
		});
		
		context("context A", {
		
			beforeEach("B", {
			
				std::cout << "B" << std::endl;
			
			});
			
			it("example B", {
			
				// ...
			
			});
			
			it("example C", {
			
				// ...
			
			});
		});
	});

will produce...

	A
	B
	  OK: example > context A > example B
	A
	B
	  OK: example > context A > example C
	-----
	PASS: 2 tests

If you prefer a RAIIapproach, then you can use a smart pointer in the `beforeEach` and do away with the `afterEach` knowing that the smart pointer destruction takes care of releasing the memory allocation.

## Scope

Code blocks passed to `describe`, `context`,  `beforeEach`, `afterEach` and `it` are all implemented as lambdas that capture by reference.  You can therefore access any variable defined at a higher level in the spec and they will be cleaned up as the lambada are unwound.

