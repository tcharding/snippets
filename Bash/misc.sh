#!/bin/bash
#
# Miscellanious BASH snippets

# strip string suffix
$foo=${foo%$suffix}
# strip prefix
$foo=${foo#$prefix}

# examle: remove .new from all files in current directory
for file in *.new; do
    rem=${file%.new}
    mv $file $rem
done
