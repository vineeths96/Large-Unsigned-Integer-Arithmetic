# define SMAX 100
# define OPMAX 6

// Linked list structrues 
struct digit
{
unsigned int num;
struct digit* next;
};


struct operators
{
char op;
struct operators* next;
};

// Functions
void str_split(char str[SMAX], struct digit* header[OPMAX], struct operators** op_header);		// Splits the string into operands and operators

void get_number(char num[SMAX], struct digit** header);							// Inputs the number into the linked list pointed by header

void get_operator(char op, struct operators** op_header);						// Inputs the operator into operator linked list

void evaluate(struct digit* header[OPMAX], struct operators** op_header);				// Evaluates the expression by taking one operator and two operands at a time

void addition(struct digit** a_header, struct digit** b_header);					// Adds the two linked lists

void multiplication(struct digit** a_header, struct digit** b_header);					// Multiplies the two linked lists

void put_number(struct digit* header);									// Displays the large integer on screen

void reverse(struct digit** header);									// Reverses the linked list

void add_front(struct digit** header, unsigned int number);						// Adds the element to a node to the front of the list

void add_last(struct digit** header, unsigned int number);						// Adds the element to a node to the back of the list

void delete_list(struct digit** header);								// Deletes the large integer list to free up memory

void delete_op_list(struct operators** header);								// Deletes the operator list to free up memory

