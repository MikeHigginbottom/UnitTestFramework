#include "project_code.h"
#include "test_framework.h"

int more_test_fail()
{
	tf_assert(false(), "This more_test should fail and emit this message to the log file");
	tf_passed();
}

int more_test_pass()
{
	tf_assert(true(), "This more_test should pass silently");
	tf_passed();
}

int more_test_pass2()
{
	tf_assert(true(), "This more_test should pass silently");
	tf_passed();
}

void more_test_suite() {
	tf_init_suite();
	tf_run_test(more_test_pass);
	tf_run_test(more_test_fail);
	tf_run_test(more_test_pass2);
}

tf_run_suite(more_test_suite);