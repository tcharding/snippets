#!/usr/bin/bash
#
# sample user interactive script (see here.sh)

echo -n "Enter your name please: "
read x
name=${x:-'John Citizen'}

echo -n "Are you happy [Y/n]: "
read x
happy=${x:-yes}

echo "Great, $name. Say $happy to happiness"

exit 0
