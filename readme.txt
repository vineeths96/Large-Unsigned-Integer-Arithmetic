================================================================
ASSIGNMENT 2 (QUESTION 1)- README.TXT
================================================================


FILES INCLUDES WITH THIS PROJECT:
================================================================

	client.c	header.h	implement.c
	readme.txt	testcase.txt	makefile


PROGRAM
================================================================

INTRODUCTION
-------------

	This program performs the arithematic operations (addition and multiplication) on large integers
represented by singly linked lists.The entire program is written in three files. Comments have been added 
frequently to help in understanding the logic behind implementation. The maximum number of operands and the size 
of the input string expression has been limited to 5 and 100 respectively. They can be modified by varying OPMAX 
and SMAX values in header file, if required. This program repeats indefinitely till exited manually.


OPERATING SYSTEM AND SOFTWARE REQUIRMENTS
------------------------------------------

	The entire program was developed in Ubuntu operating system using C language. It is highly recommeneded 
to use the Ubuntu system to execute the program. The program requires gcc compiler to compile, build and 
execute the program. The OS and compiler version used for developing the code are :
		Operating system 	: Ubuntu 18.04.1 
		gcc compiler verison	: gcc version 7.4.0

FUNCTIONS IN THE PROGRAM
------------------------

str_split()	- Takes the inputted string and splits to operands and operators, and pushes it to linked lists.
		  Evaluates the expression when '=' is encountered in string.

get_number()	- Takes the 4 digit number and pushes into the list specified in the argument.

get_operator()	- Takes the operator(+ or *) and pushes into the list specified in the argument.

evaluate()	- Evalautes the expression by taking an operator (from operator list) and two operands
		  (from operands list) and updates the second operand with the result. This procedure is looped
		  till the operator list is fully traversed. After looping the final result is printed on screen.

addition()	- Adds the two large integers specified in the argument list.

multiplication()- Multiplies the two large integers specified in the argument list.

put_number()	- Prints the large integer linked list, passed as an argument, in the specified format.

reverse()	- Reverses the large integer linked list which specified as an argument.

add_front()	- Adds a new (digit) element to the front of the large integer linked list.

add_last()	- Adds a new (digit) element to the back of the large integer linked list.

delete_list()	- Deletes the large integer linked list to free up memory.

delete_op_list()- Deletes the operator linked list to free up memory.


PROGRAM EXECUTION
-----------------
	The function when executed expects the user to input a string of expression containing large integers and
arithmetic operators. The large integers should be comma seperated with a base of 10000 and should be terminated with
a '$' sign. The arithmatic operators allowed are adiition(+) and multiplication(*). The operands and operators are 
seperated and inserted into coreesponding linked lists with str_split(), get_number() and get_operator() functions. The 
operands and stored in an array of linked lists. The evalaute() function is called when an '=' is encountered and it 
performs the operations by reading one operator and two operands from the linked lists. The addition is performed by
addition() and multiplication by multiplication() functions. The final result after execution is printed on screen 
and then the lists are deleted to free up used space. 


TEST CASES
----------

	The "testcode.txt" contains the 5 test cases. Comments have been added to guide through the test case 
file to identify where to input data. 


INSTRUCTIONS TO RUN
--------------------

	Open the terminal, make the program and run it. Enter the values from the file (or custom values) 
as requested during exectuion of the program.


CONTACT
========
Developed by
Name	 : Vineeth S
SR No	 : 16543
Email id : vineeths@iisc.ac.in
