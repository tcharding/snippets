#!/usr/bin/bash
#
# BASH parameter processing

set -o nounset

${foo:+bar}			# returns bar if foo exists and is not null

# := sets the variable and returns it
echo '---'			# declare foo to default if not already set
: ${foo:=default}		# requires colon at start
echo $foo

# :- returns the variable
echo -e "\n---"			# foo = bar or default if bar not set
foo=${bar:-default}		
echo $foo

echo -e "\n---"
unset foo
echo ${foo:-default}

echo -e "\n---"
foo=bar
echo ${foo:-default}

# ${foo#regex} removes shortest match from beginning
# ${foo##regex} removes longest match from beginning 
# ${foo%regex} removes shortest match from end
# ${foo%%regex} removes longest match from end

echo -e "\n---"
foo=/usr/bin/X11/startx
echo ${foo#*/}
echo ${foo##*/}

echo -e "\n---"
foo=/usr/local/etc/local/networks
echo ${foo%local*}
echo ${foo%%local*}

my_ls () {
    ls
}

echo -e 'print directory listing: \n'
foo='my_ls'
${foo:?out_msg}

unset foo
${foo:?'fail with error message'}



