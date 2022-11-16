/* print PID */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char **argv){
	int pid;

	pid = getpid();
	printf("PID: %d\n", pid);
	sleep(20);
	exit(0);
}
	
