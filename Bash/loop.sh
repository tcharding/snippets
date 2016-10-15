#!/usr/bin/bash
#
# Various looping and test constructs

# functon arguments and returning true/false
fn () {
    eco "Is your name $* ?"
    while true
    do
	echo -n "Enter yes or no: "
	read x
	case "$x" in
	    y | yes ) return 0;;
	    n | no ) return 1;;
	    * ) echo "Answer yes or no"
	esac
    done
}

#
# various empty string comparisons
if [ -z "$1" ] ; then
    echo "-z arg 1 empty"
fi

if [ x"$1" = x ] ; then
    echo "No arguments supplied"
else
    while [ x"$1" != x ] ; do
	echo "Argument: $1"
	shift
    done
fi

# null command ':'
if [ -f file ] ; then
    :
else
    echo 'look we han an empty then clause'
fi

 : ${var:=value}		# declares an default var with default value



exit 0
