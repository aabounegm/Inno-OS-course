touch _ex3.txt				# create the file
ls -l _ex3.txt

chmod a-x _ex3.txt			# remove from everyone execute permissions
ls -l _ex3.txt

chmod u+rwx,o+rwx _ex3.txt	# give user (owner) and other all permissions
ls -l _ex3.txt

chmod g=u _ex3.txt			# give group same permissions as user
ls -l _ex3.txt

rm _ex3.txt
