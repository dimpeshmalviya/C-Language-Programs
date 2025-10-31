#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

//Zombie Process:
// A zombie process is a terminated process that still has an entry in the process table because its parent hasn’t yet read its exit status using wait(). It doesn’t consume CPU or memory but occupies a process ID until it’s reaped.
int main(){
	pid_t p;
	p = fork();

	if(p==0){
		printf("This is the child process!\n");
		printf("im a child and im  existing--- %d\n",getpid());
		exit(0);
	}else{
		printf("im the parent process!\n");
		sleep(30);
	}
}
