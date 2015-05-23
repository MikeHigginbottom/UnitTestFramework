suites = demo_tests.o more_tests.o

all: $(suites)
	cc -o demo_tests demo_tests.o
	cc -o more_tests more_tests.o
	sh ./test_harness.sh

demo_tests.o: demo_tests.c test_framework.h debug.h
	cc -c demo_tests.c

more_tests.o: more_tests.c test_framework.h debug.h
	cc -c more_tests.c

clean:
	rm demo_tests more_tests $(suites)