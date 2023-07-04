#
# Python3 Reverse Polish Notation (RPN) Calculator
#
# Accepts an single argument in RPN, evaluates it and prints the answer to stdout.
#
#!/usr/bin/env python
#Jeremy Lafond
#jalafond
#Lab1

import operator
import math
import sys

#define operators
opers = {
'+':operator.add,
'-':operator.sub,
'*':operator.mul,
'/':operator.truediv,
'^':operator.pow
}

#simple numcheck, seemed like there
#were way too many ways to do this
def numCheck(n):
	try:
		int(n)
		return True
	except ValueError:
		pass

#operator function
#loop: check for num
#if num: append
#if k in opers:
#operate
#append running total
#return running total for rpnc
def operate(toks):
	#initialize stack array
	stack = []
	#running total
	rpnc = 0
	for k in toks:
		if numCheck(k):
			stack.append(k)
		if k in opers:
			t1 = stack.pop()
			t2 = stack.pop()
			rpnc = opers[k](int(t2), int(t1))
			stack.append(rpnc)
		else:
			continue
	return rpnc
#take argv and stringify
#split string into tokens
#operate on tokens
#print rpnc running total from operate
def main():
	tokList = ' '.join(sys.argv[1:])
	toks = tokList.split(' ')
	calc = operate(toks)
	print(calc)
	pass

if __name__ == "__main__":
	main()