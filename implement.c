#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void str_split(char str[SMAX], struct digit* header[OPMAX], struct operators** op_header)
{
	char num[5];
	for(int i = 0, j = 0, k = 0; ((str[i] != '\0') && (k < OPMAX)); i++)
	{
		// Switches the characters and adds it either to large integer list (when , encountered) or to operator list (when * + encountered)
		// Expression is evalauted when '=' is encountered. 
		switch(str[i])
		{
			case ',' : {
					get_number(num, &header[k]);
					j = 0;
					break;
				   }

			case '$' : {
					get_number(num, &header[k]);
					k++;
					j = 0;
					
					for(int m = 0; m<4; m++)
					{
						num[m] = ' ';
					}
					
						
					break;
				   }

			case '+' : {	
					get_operator('+', op_header);
					j = 0;
					break;
				   }

			case '*' : {
					get_operator('*', op_header);
					j = 0;
					break;
				   }

			case '=' : {
					evaluate(header, op_header);
					break;						
				   }
			case ' ' : {
					break;						
				   }

			default :  {
					num[j] = str[i];
					j++;	
				   }
		}
	}
}



void get_number(char num[5], struct digit** header)
{
	struct digit* ptr = (struct digit*) malloc(sizeof(struct digit));
	sscanf(num, "%d", &ptr->num);
	ptr->next = *header;
	*header = ptr;
}


void get_operator(char ch, struct operators** op_header)
{
	struct operators* ptr = (struct operators*) malloc(sizeof(struct operators));
	ptr->op = ch;
	ptr->next = NULL;
	if(*op_header == NULL)
		*op_header = ptr;
	else
	{
		struct operators* last = (struct operators*) malloc(sizeof(struct operators));	
		for(last = *op_header; last->next != NULL; last = last->next);
		last->next = ptr;
	}
}


void put_number(struct digit* header)
{
	struct digit* ptr = (struct digit*) malloc(sizeof(struct digit));
	reverse(&header);
	for(ptr = header; ptr != NULL; ptr = ptr->next)
	{
		printf("%04d", ptr->num);
		if((ptr->next) != NULL)	printf(",");
	}
	printf("$\n");
}

void evaluate(struct digit* header[OPMAX], struct operators **op_header)
{
	struct operators* ptr = (struct operators*) malloc(sizeof(struct operators));
	int i = 0;

	for(ptr = *op_header; ptr != NULL; ptr = ptr->next, i++)
	{	
		
		if(ptr->op == '+')	addition(&header[i], &header[i+1]);
		if(ptr->op == '*')	multiplication(&header[i], &header[i+1]);
	}
	
	// Display the final result
	put_number(header[i]);			
	
}


void addition(struct digit** a_header, struct digit** b_header)
{	
	// If one of the numbers is NULL 
	if(*a_header == NULL || *b_header == NULL)
	{
		printf("Cannot add NULL numbers\n");
		exit(0);
	}

	// Declarations
	struct digit* a_ptr = (struct digit*) malloc(sizeof(struct digit));
	struct digit* b_ptr = (struct digit*) malloc(sizeof(struct digit));
	struct digit* b_ptr_prev = (struct digit*) malloc(sizeof(struct digit));
	unsigned int carry = 0, sum = 0;
	
	// Adding the 'digit' nodes of the lists A and B till one or both vanishes
	for(a_ptr = *a_header, b_ptr = *b_header, b_ptr_prev = *b_header; ((a_ptr != NULL) && (b_ptr != NULL)); a_ptr = a_ptr->next, b_ptr = b_ptr->next)
	{
		sum = (a_ptr->num + b_ptr->num + carry);
		carry = (sum)/10000;
		b_ptr->num = (sum)%10000;
		if(b_ptr != *b_header)	b_ptr_prev = b_ptr_prev->next;
	}

	// If second list (B) vanishes
	for(; (a_ptr != NULL)  && (b_ptr == NULL); a_ptr = a_ptr->next)
	{
		sum = (a_ptr->num + carry);
		carry = (sum)/10000;
		sum = (sum)%10000;
		add_last(b_header, sum);		
	}

	// If first list (A) vanishes
	for(; (a_ptr == NULL) && (b_ptr != NULL); b_ptr = b_ptr->next)
	{
		sum = (b_ptr->num + carry);
		carry = (sum)/10000;
		b_ptr->num = (sum)%10000;
	}
	
	// Adding an extra 'digit' node if carry != 0
	if(carry != 0)
	{
			add_last(b_header, carry); 
			carry = 0;
	}
}

void multiplication(struct digit** a_header, struct digit** b_header)
{
	// Declarations
	unsigned int prod = 0, carry = 0, count = 0;

	struct digit* a_ptr = (struct digit*) malloc(sizeof(struct digit));
	struct digit* b_ptr = (struct digit*) malloc(sizeof(struct digit));

	struct digit* result = (struct digit*) malloc(sizeof(struct digit));
	result->num = 0;
	result->next = NULL;

	// Multiplying
	for(b_ptr = *b_header; b_ptr != NULL; b_ptr = b_ptr->next, count++)
	{	
		struct digit* product = NULL;

		for(a_ptr = *a_header; a_ptr != NULL; a_ptr = a_ptr->next)
		{
			prod = (a_ptr->num) * (b_ptr->num) + carry;
			carry = (prod)/10000;
			prod = prod%10000;
			add_front(&product, prod);
		}

		// Adding an extra 'digit' node if carry != 0
		if(carry != 0)
		{	
				add_front(&product, carry); 
				carry = 0;
		}

		// Adding zeros at the end for shifted addition
		for(int i = 0; i < count; i++)
		{
			add_last(&product, 0000);			
		}

		// Shifted Addition
		reverse(&product);
		addition(&product, &result);
		delete_list(&product);	
	}
	
	*b_header = result;
	
}

void add_last(struct digit** header, unsigned int num)
{
	struct digit* new_node = (struct digit*) malloc(sizeof(struct digit));
	new_node->num = num;
	new_node->next = NULL;
	
	if(*header == NULL)	
		*header = new_node;
	else
	{
		struct digit* last = (struct digit*) malloc(sizeof(struct digit));	
		for(last = *header; last->next != NULL; last = last->next);
		last->next = new_node;
	}
}

void add_front(struct digit** header, unsigned int number)
{	
	struct digit* ptr = (struct digit*) malloc(sizeof(struct digit));
	ptr->num = number;
	ptr->next  = *header;
	*header = ptr;	
}

void reverse(struct digit** header) 
{ 
	struct digit* prev = NULL; 
	struct digit* current = *header; 
	struct digit* next = NULL; 
	while (current != NULL)
	{ 
		next = current->next; 
		current->next = prev; 
		prev = current; 
		current = next; 
	} 
	*header = prev; 
} 

void delete_list(struct digit** header)
{
	struct digit* prev = *header;

	while (*header != NULL)
	{
		*header = (*header)->next;
		free(prev);
		prev = *header;
	}
}

void delete_op_list(struct operators** header)
{
	struct operators* prev = *header;

	while (*header != NULL)
	{
		*header = (*header)->next;
		free(prev);
		prev = *header;
	}
}
















