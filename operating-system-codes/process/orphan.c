#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
//Orphan Process:
// An orphan process is a child process whose parent has terminated before it. When this happens, the init (or systemd) process adopts it to ensure proper cleanup. The orphan continues running normally under its new parent.
int main(){
	pid_t p;
	p = fork();
	if(p==0){
		printf("im a child process %d\n" ,getpid());
		printf("the child process is executing\n");
		sleep(30);
		printf("the parent %d\n",getppid());
	}else{
		printf("hi i am the parent\n");
		exit(0);
		printf("parent Done!\n");
	}
}
