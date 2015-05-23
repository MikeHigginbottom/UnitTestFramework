## Introduction

This is a lightweight unit test framework for linux, written in C and designed to automatically run a suite of validation tests against your project whenever you run <code>make</code> on it.

## Motivation

Testing our code is like eating our greens. We know we should do it more than we do but it's not our favourite thing in the world. This test framework is designed to be as painless as possible - painless to install, painless to get a new project up and running, painless to write tests. No more excuses.

## Installation and Example Code

Clone the project into an empty folder. The framework itself is in the following files:

1. <code>debug.h</code> - Supporting macros using to log debugging info.
2. <code>test_framework.h</code> - The framework itself.
3. <code>test_harness.sh</code> - A bash script that calls the individual test suites (groups of tests).
4. <code>makefile</code> - The makefile called when you build your project. This calls the test harness bash script once the build is complete to trigger the testing process.

A minimal project and associated test files are provided as follows:

1. <code>project_code.h</code> - A dummy project which just has two functions in it; one of which returns a non-zero value representing boolean truth and one of which returns zero representing boolean false. This file serves to represent your real project code.
2. <code>demo_tests.c</code> - The first test suite containing a simple set of tests to exercise the project code. You would replace the tests in here with ones that exercise your own project code.
3. <code>more_tests.c</code> - A second test suite essentially duplicating the first and intended to show how you can group related tests together into suites. The harness will then run all the suites in sequence.

