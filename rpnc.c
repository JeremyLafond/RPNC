/*
 * Reverse Polish Notation (RPN) Calculator
 *
 * Accepts a single arguement in RPN, evaluates it and prints the answer to stdout.
 *
 * Returns -1 on error, 0 otherwise.
Jeremy Lafond
jalafond
Lab1
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
initialize stack type struct for rpn
data: data value
*next: stack pointer
*/
typedef struct rpn
{
	int data;
	struct rpn *next;
} rpn;

/*
implement push for rpn stack
args: *front, val
function:
allocates rpn stack no;;;des
assigns data
moves front
*/
void push(rpn **front, int val)
{
	//allocate memory for node
	rpn *node = malloc(sizeof(rpn));
	//check for stack overflow
	if(node == NULL)
	{
		fprintf(stderr, "Stack Error: Stack Overflow. Out of memory\n");
		exit(-1);
	}
	node->data = val;
	node->next = *front;
	*front = node;
}

/*
implements pop for rpn stack
args: *front
function:
checks for bottom of stack
else
moves top
sets val
moves front
frees pointer
returns val
*/
int pop(rpn **front)
{
	if(*front == NULL)
	{
		fprintf(stderr,"Stack Error: You can't pop off the bottom of the stack\n");
		exit(-1);
	}
	else
	{
		rpn *top = *front;
		int val = top->data;
		*front = top->next;
		free(top);
		return val;
	}
}

/*
implements operators for rpn stack
args: oper, *front
function:
initializes temp
checks for +,-,*,/,^ operators
returns rpn operated values
*/
int operate(char oper, rpn **front)
{
	int t;
	int powa;
	if(oper == '+')
	{
		return pop(front) + pop(front);
	}
	if(oper == '-')
	{
		t = pop(front);
		return pop(front) - t;
	}
	if(oper == '*')
	{
		return pop(front) * pop(front);
	}
	if(oper == '/')
	{
		t = pop(front);
		return pop(front) / t;
	}
	if(oper == '^')
	{
		t = pop(front);
		powa = pop(front);
		return pow(powa, t);
	}
	return -1;
}

/*
check if tok is a number
*/
int numCheck(char *number)
{
	if(*number > '9' || *number < '0')
	{
		return 0;
	}
	return 1;
}

/*implementation
scans argv for numbers and operators
adds numbers to stack
operates on numbers if tok is an operator
prints final result
*/
int main(int argc, char *argv[])
{
	int j = 1;
	int t = 0;
	char oper;
	const char s[2] = " ";
	rpn *front = NULL;
	char *tok;
	tok = strtok(argv[j], s);
	while(tok != NULL)
	{
		//check if tok is a number
		if(numCheck(tok))
		{
			t = atoi(tok);
			push(&front, t);
		}
		else
		//assume tok is an operator
		{
			oper = tok[0];
			push(&front, operate(oper, &front));
		}
		tok = strtok(NULL, s);
	}
	printf("%d", front->data);
	return 0;
}