#include "project_code.h"
#include "test_framework.h"

int demo_test_fail()
{
	tf_assert(false(), "This demo_test should fail and emit this message to the log file");
	tf_passed();
}

int demo_test_pass()
{
	tf_assert(true(), "This demo_test should pass silently");
	tf_passed();
}

int demo_test_pass2()
{
	tf_assert(true(), "This demo_test should pass silently");
	tf_passed();
}

void demo_test_suite() {
	tf_init_suite();
	tf_run_test(demo_test_pass);
	tf_run_test(demo_test_fail);
	tf_run_test(demo_test_pass2);
}

tf_run_suite(demo_test_suite);