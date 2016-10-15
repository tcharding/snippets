#!/usr/bin/bash
#
# using trap

 trap 'echo Exiting: foo: $foo bar: $bar' EXIT

foo=1
bar=2

exit 0

# 
