#!/bin/bash

writefile=$1
writestr=$2

if [ $# -eq 2 ]; then

    mkdir -p "$(dirname "${writefile}")" && touch "$writefile"
    echo "${writestr}" > "${writefile}"

	
    if [ ! -e "$writefile"  ]; then
        echo "error creating file" 
        exit 1
    fi
else
	echo "Number of argument is incorrect"
    exit 1
fi