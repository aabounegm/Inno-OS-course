#!/bin/bash

N=5

if [ $# -eq 1 ]; then
    N=$1;
elif [ $# -gt 1 ]; then
    echo "Usage: ${0} [execution count]"
    exit
fi

echo 1 > ex2.2.txt

for (( i = 1; i <= $N; i++ ))
do
	./increment_lock.sh ex2.2.txt&
	./increment_lock.sh ex2.2.txt
done
