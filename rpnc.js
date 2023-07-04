/*
 * Node.js / JavaScript Reverse Polish Notation (RPN) Calculator
 *
 * Accepts an single argument in RPN, evaluates it and prints the answer to stdout.
 * 
 */

"use strict";
/*
simple stack implementation used from:
https://www.geeksforgeeks.org/implementation-stack-javascript/
*/
class Stack
{
	constructor()
	{
		this.items = [];
		this.front = this.items[0];
	}
}

push(val)
{
	this.items.push(val);
}

pop()
{
	if(this.items.length == 0)
	{
		return "Stack is empty"
	}
	return this.items.pop();
}

isEmpty()
{
	return this.items.length == 0;
}

printStack()
{
	var str = "";
	for(var i = 0; i < this.items.length; i++)
	{
		str+= this.items[i] + " ";
	}
	return str;
}

function splitArg(args)
{
	var str = args.split(' ',':');
	var s = new Stack();
	return s;
}

function RPN(args)
{
	var stack = new Stack();
	for(var i = 0; i < args.length; i++)
	{
		var a = args[i];
		//check and cast
		if(!isNAN(a))
		{
			stack.push(a - '0');
		}
	}
	console.log(arguments[1]);
}
/*
implements operators for rpn stack
args: oper, *front
function:
initializes temp
checks for +,-,*,/,^ operators
returns rpn operated values

int operate()
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

check if tok is a number

int numCheck(char *number)
{
	if(*number > '9' || *number < '0')
	{
		return 0;
	}
	return 1;
}*/