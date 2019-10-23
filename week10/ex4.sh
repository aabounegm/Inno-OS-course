mkdir tmp
cd tmp
touch file1 file2
link file1 link1
cd ..
gcc ex4.c -o ex4.out
./ex4.out
rm ex4.out
cd tmp
rm file1 link1 file2
cd ..
rmdir tmp