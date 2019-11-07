gcc ex2.c -o _ex2
cat /proc/cpuinfo | ./_ex2 ex2.txt
rm _ex2
