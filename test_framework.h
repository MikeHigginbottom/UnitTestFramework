#ifndef _test_framework_h
#define _test_framework_h

#include <stdio.h>
#include <stdlib.h>
#include "debug.h"

int num_tests_run;
int num_failures;

#define tf_init_suite() int result = 0;

#define tf_run_test(test) dbg("Running test case %s", #test); result = test(); num_tests_run++; if (result) { num_failures++; }

#define tf_assert(test, message, ...) if (!(test)) { err(message, ##__VA_ARGS__); return -1; }

#define tf_clear_errmsg() *errmsg = '\0';
#define tf_assert_no_errors() if (*errmsg != '\0') { err("Expected no error messages and got '%s'", errmsg); return -1; }
#define tf_assert_errmsg(expected) if (strcmp(errmsg, expected) != 0) { err("Expected error message '%s' and got '%s'", expected, errmsg); return -1; }

#define tf_stub() { err("Ran stubbed out test case"); return -1; }

#define tf_passed() dbg("Test case passed"); return 0;

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