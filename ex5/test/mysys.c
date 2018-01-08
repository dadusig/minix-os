#include <lib.h> // provides _syscall and message
#include <stdio.h>
#include <stdlib.h> // provides atoi
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc >=2 )
	{
		char filename[PATH_MAX];
		strcpy(filename, argv[1]);
		// printf("%s\n", filename);
		message m;
		m.m1_i1 = strlen(filename)+1;
  	 	m.m1_p1 = (char*) filename;

		int value = _syscall(VFS_PROC_NR, 108, &m);

		printf("%d\n", value);

	}


	 // char* p1 = "inode.c";
    // message m;
    // m.m1_i1 = strlen(p1)+1;
	 // m.m1_p1 = (char*) p1;
	 // int value = _syscall(VFS_PROC_NR, 108, &m);
	 // printf("ret value= %d\n", value);
	 return 0;
}
