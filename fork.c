/* print PID (Parent and Child) */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv){
	int pid, ppid;

	pid = fork();
	if (pid < 0) /* error */
		printf("fork failed.\n");
	else if (pid == 0){
		ppid = getppid();
		pid  = getpid();
		printf("Child : PPID: %d,  PID: %d\n", ppid, pid);
		sleep(20);
	}
	else{	
		ppid  = getpid();
		printf("Parent:  PID: %d, CPID: %d\n", ppid, pid);
		sleep(20);
	}
	exit(0);
}
