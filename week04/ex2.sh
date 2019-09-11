#!/bin/bash

N=3

if [ $# -eq 1 ]; then
    N=$1;
elif [ $# -gt 1 ]; then
    echo "Usage: ${0} [fork count]"
    exit
fi

gcc ex2.c -o ex2.out

./ex2.out $N &

watch -d pstree
