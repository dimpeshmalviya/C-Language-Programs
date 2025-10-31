#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	pid_t p;
	p=fork(); //Clone the calling process, creating an exact copy.Return -1 for errors, 0 to the new process,and the process ID of the new process to the old process.
    if(p==0){
        printf("child process:\n");
        printf("%d\n",p);
        printf("%d\n",getpid());
        printf("%d\n",getppid());
    }else if(p>0){
        printf("parent process:\n");
        printf("%d\n",p);
        printf("%d\n",getpid());
        printf("%d\n",getppid());
    }else{
        printf("error!");
    }
}
