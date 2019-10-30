#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main()
{
	printf("Preparing to copy content...\n");
	
	// open first file for read
	int source = open("ex1.txt", O_RDONLY);
	if(source == -1)
	{
		printf("Error opening source file for read\n");
		return 1;
	}
	printf("Opened source file\n");

	// get file size
	int filesize = lseek(source, 0, SEEK_END);
	if(filesize == -1)
	{
		close(source);
		printf("Error calling lseek on source file\n");
		return 2;
	}
	
	printf("Source file size: %d\n", filesize);
	
	char *src_map = mmap(NULL, filesize, PROT_READ, MAP_PRIVATE, source, 0);
	if(src_map == MAP_FAILED)
	{
		close(source);
		printf("Error mapping the source file\n");
		return 3;
	}
	printf("Source mapping created\n");
	
	// open destination file for writing
	int dest = open("ex1.memcpy.txt", O_RDWR | O_CREAT, (mode_t)0666);
	if(dest == -1)
	{
		close(source);
		printf("Error opening destination file for writing\n");
		return 4;
	}
	printf("Destination file opened\n");
	
	ftruncate(dest, filesize);	// truncate it to exactly this size (if it existed previously)	
	char *dest_map = mmap(NULL, filesize, PROT_READ | PROT_WRITE, MAP_SHARED, dest, 0);
	if(dest_map == MAP_FAILED)
	{
		close(source);
		close(dest);
		printf("Error mapping the destination file\n");
		return 3;
	}
	printf("Destination map created\n");
	
	// copy from string to the map
	memcpy(dest_map, src_map, filesize);
	printf("Copied between maps\n");
	
	// write to disk
	if(msync(dest_map, filesize, MS_SYNC) == -1)
	{
		close(source);
		close(dest);
		printf("Error writing to file\n");
		return 5;
	}
	printf("Synced\n");
	
	// Remove the mappings
	if(munmap(src_map, filesize) == -1 || munmap(dest_map, filesize) == -1)
	{
		close(source);
		close(dest);
		printf("Error unmapping the files\n");
		return 6;
	}
	printf("Unmapped files\n");
	
	close(source);
	close(dest);
	printf("Writing succeeded!\n");
	return 0;
}