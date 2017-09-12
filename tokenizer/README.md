# os-tokenizer-lab

This directory contains:
* code that implements a string tokenizer
* a test program that uses it

This demo contains the following files:
 mytoc.h: header file for mytoc.c functions
 mytoc.c: implementation of string tokenizer
 test.c: a demonstration program that acts like a shell
 

To compile:
~~~
$ make
~~~

To test it, try:
~~~
$ ./mytoc
~~~

To delete binaries:
~~~
$ make clean
~~~

# Known issues #

1. There seems to be a problem with the getTokenLength method, the variable numTokens causes an issue, a static variable had to be declared but has a fixed int of 5 at the moment.

2. There is a warning when calling the mytoc function from main.




