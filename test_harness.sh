err=0
log_file=results.log
rm -f $log_file
echo""
for suite in *_tests
do
	if [ -f $suite ]
	then
		if valgrind -q --leak-check=full --track-origins=yes ./$suite 2>> $log_file
		then
			echo "Test suite" $suite "passed\n"
		else
			echo "Test suite" $suite "failed\n"
			err=1
		fi
	fi
done
if [ $err -eq 1 ]
then
	echo "Dump of" $log_file "follows:"
	more $log_file
	echo ""
fi
