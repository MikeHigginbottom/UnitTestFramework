log_file=results.log
rm $log_file
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
		fi
	fi
done
echo "Dump of" $log_file "follows:"
cat $log_file
echo ""
