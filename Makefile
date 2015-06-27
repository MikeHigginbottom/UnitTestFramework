suites = demo_tests.o more_tests.o debug.o

all: $(suites)
	cc -o demo_tests demo_tests.o debug.o
	cc -o more_tests more_tests.o debug.o
	sh ./test_harness.sh

$(suites): project_code.h test_framework.h debug.h

.PHONY: clean
clean:
	-rm demo_tests more_tests $(suites)