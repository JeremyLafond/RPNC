#
# Awk Reverse Polish Notation (RPN) Calculator
#
# Accepts an single argument in RPN, evaluates it and prints the answer to stdout.
#
#Jeremy Lafond
#gnu.org helped on this a bit: https://www.gnu.org/software/gawk/manual/html_node/ARGC-and-ARGV.html

function push(element) {stack[++val] = element;}

function RPN(element)
{
	if(element ~ /^[0-9]*$/) push(element);
	else
	{
		m = stack[val]; val--;
		n = stack[val]; val--;
		if(element == "+") push(n + m);
		if(element == "-") push(n - m);
		if(element == "*") push(n * m);
		if(element == "/") push(n / m);
		if(element == "^") push(n ^ m);
	}
}
BEGIN {
	element = 0;
	for(i = 0; i <= split(ARGV[1], args, " "); i++) {RPN(args[i]);}
	print stack[val];
}