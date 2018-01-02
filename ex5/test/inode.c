#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	int fd, inode;
	fd = open("inode.c", O_RDONLY);

	if (fd < 0) {
	    // some error occurred while opening the file
	    // use [perror("Error opening the file");] to get error description
	}

	struct stat file_stat;
	int ret;
	ret = fstat (fd, &file_stat);
	if (ret < 0) {
	   // error getting file stat
	}

	inode = file_stat.st_ino;  // inode now contains inode number of the file with descriptor fd
	printf("%d\n", inode);
	return 0;
}
