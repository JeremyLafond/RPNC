#
# Bash Reverse Polish Notation (RPN) Calculator
#
# Accepts an single argument a RPN, evaluates it and prints the answer to stdout.
#
#Jeremy Lafond
#jalafond
#Lab1
#!/bin/bash
#some counters to deal with 1 off
COUNTER=0
COUNTER2=0
declare -a rpnStack[0]
#had a terrible time with scanning for ^ and *
#stackoverflow was helpful for syntax but that's about it.
#I also used tldp.org for understanding the basics of bash.
#I probably should have watched the lecture on bash! but I felt like challenging myself.
IFS= read -r -a ARGS <<< "$@"
for arg in ${ARGS[@]}; do
    if [[ $COUNTER2 > 0 && $arg =~ ^-?[0-9]+$ ]]; then
        (( COUNTER++ ))
    fi
    if [[ $arg =~ ^-?[0-9]+$ ]]; then
        rpnStack[COUNTER]=$arg
        (( COUNTER2++ ))
    fi
    if [[ $arg =~ ^[-+/]$ ]]; then
        T=$(( $COUNTER-1 ))
        rpnStack[T]=$((${rpnStack[T]}$arg${rpnStack[COUNTER]}))
        unset rpnStack[COUNTER]
        (( COUNTER-- ))
    fi
    if [[ $arg == [\^] ]]; then
	U=$(( $COUNTER-1 ))
	rpnB=${rpnStack[U]}
	rpnC=${rpnStack[COUNTER]}
	val=$(($rpnB**$rpnC))
	rpnStack[U]=$val
	unset rpnStack[COUNTER]
	(( COUNTER-- ))
    fi
    if [[ $arg != *[-+/\^0123456789] ]] && [[ $COUNTER>0 ]]; then
	V=$(( $COUNTER-1 ))
	rpnD=${rpnStack[V]}
	rpnE=${rpnStack[COUNTER]}
	val1=$(( $rpnD * $rpnE ))
	rpnStack[V]=$val1
	unset rpnStack[COUNTER]
	(( COUNTER-- ))
    fi
done
echo ${rpnStack[0]}
