#include <stdio.h>
#include <stdlib.h>
#include <lib.h>

int main(int argc, char *argv[])
{
	message m;
	m.m1_i1 = atoi(argv[1]);
	int ppid = _syscall(PM_PROC_NR, PRINTPPID, &m);
	printf("%d\n", ppid);
	return 0;
}
