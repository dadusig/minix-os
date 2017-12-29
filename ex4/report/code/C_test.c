#include <stdio.h>
#include <stdlib.h>
#include <lib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int flag=0;
	message m;

	printf("Current number of running processes: %d\n", 
	                    _syscall(PM_PROC_NR, GETPROCCOUNT, &m));

	printf("Lets do some forking...\n");
	
	for(int i=0; i<atoi(argv[1]); i++)
		if (flag==0)
		{
			pid_t id = fork();
			if (id == 0) 
			{
				flag = 1;
				sleep(1);
				exit(0);
			}
		}
	
	printf("Now you have %d running processes\n", 
	                    _syscall(PM_PROC_NR, GETPROCCOUNT, &m));

	while (wait(NULL) > 0); //wait for all children to finish

	printf("You're back at %d processes!\n", 
	                    _syscall(PM_PROC_NR, GETPROCCOUNT, &m));

	return 0;
}
