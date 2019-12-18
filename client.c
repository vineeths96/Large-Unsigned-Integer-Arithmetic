#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
	char str[SMAX];

	while(1)
	{
		// Declarations
		struct digit* header[OPMAX];
		struct operators* op_header = NULL;

		// Setting the array of linked list headers to NULL
		for(int i = 0; i < OPMAX; i++)
			header[i] = NULL;
		
		printf("\nEnter the expresssion (Maxiumum operands limited to 5 and maximum charecters limited to 100). Entering '=' sign evaluates the expression\n");
		fgets(str, SMAX, stdin);

		str_split(str, header, &op_header);
		
		// Deletion of linked lists to free up memory
		for(int i = 0; i < OPMAX; i++)
			delete_list(&header[i]);

		delete_op_list(&op_header);
	}	

	
}
