#!/bin/bash

if [ $# -eq 1 ]; then
    FileName="$1";
else
    echo "Usage: ${0} <file name>"
    exit
fi

# Lock file exists, another process/thread is running
while ! ln "$FileName" "$FileName.lock" 2>/dev/null
do
	sleep 0.1
done

# Hard link created, meaning file is locked to current process

last=$( tail -n 1 "$FileName" )

((last++))

echo $last >> $FileName

# free the lockfile
rm "$FileName.lock"
