#thsi is sample
testCal:queue1.c testqueue.c
	gcc queue1.c testqueue.c -o testqueue
clean:
	rm testCal