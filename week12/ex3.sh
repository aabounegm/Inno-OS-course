#!/bin/bash

buffer_sizes=(256 1024 4096)
echo "Compiling copy.c with buffer sizes ${buffer_sizes[@]} bytes"
for size in ${buffer_sizes[@]}
do
	gcc copy.c -DBUF_SIZE=$size -o "copy$size"					# without O_SYNC
	gcc copy.c -DBUF_SIZE=$size -DSYNC -o "copy${size}_sync"	# with O_SYNC
done

echo "Creating sample data for testing"
dd bs=1024 count=1024 if=/dev/urandom of=1MB.txt
dd bs=1024 count=10240 if=/dev/urandom of=10MB.txt
dd bs=1024 count=102400 if=/dev/urandom of=100MB.txt
echo "Created files of sizes 1MB, 10MB, and 100GB"

echo "Timing..."
echo "Results:" > ex3.txt
for size in ${buffer_sizes[@]}
do
	echo "Buffer size: $size bytes" >> ex3.txt
	for file in 1MB.txt 10MB.txt 100MB.txt
	do
		echo -e -n "\tFile size: $file" >> ex3.txt
		{ time ./copy$size $file temp.txt; } 2>&1 1>/dev/null | sed 's/^/\t\t/' &>> ex3.txt
		echo -e -n "\tFile size: $file (O_SYNC)" >> ex3.txt
		{ time ./copy${size}_sync $file temp.txt; } 2>&1 1>/dev/null | sed 's/^/\t\t/' &>> ex3.txt
	done
done

echo "Done timing"

for size in ${buffer_sizes[@]}
do
	rm "copy$size" "copy${size}_sync"
done

rm 1MB.txt 10MB.txt 100MB.txt temp.txt
echo "Cleaned up all temporary files"
