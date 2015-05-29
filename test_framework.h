#ifndef _test_framework_h
#define _test_framework_h

#include <stdio.h>
#include <stdlib.h>
#include "debug.h"

int num_tests_run;
int num_failures;

#define tf_init_suite() int result = 0;

#define tf_run_test(test) dbg("Running test case %s", #test); result = test(); num_tests_run++; if (result) { num_failures++; }

#define tf_assert(test, message) if (!(test)) { err(message); return -1; } else { return 0; }

#define tf_run_suite(name) \
int main(int argc, char *argv[]) {\
	assrt(argc == 1, "Pass zero arguments"); \
	dbg("Running test suite %s", argv[0]);\
	printf("Running test suite %s\n", argv[0]);\
	name();\
	printf("Ran %d tests\n", num_tests_run);\
	if (num_failures) {\
		printf("%d tests failed\n", num_failures);\
	}\
	else {\
		printf("All tests passed\n");\
	}\
	return num_failures;\
error:\
	return 1;\
}

#endif //_test_framework_h