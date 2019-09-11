#!/bin/bash

N=10

if [ $# -eq 1 ]; then
    N=$1;
elif [ $# -gt 1 ]; then
    echo "Usage: ${0} [execution count]"
    exit
fi

gcc ex1.c -o ex1.out

for (( i = 1; i <= $N; i++ ))
do
    ./ex1.out
done
