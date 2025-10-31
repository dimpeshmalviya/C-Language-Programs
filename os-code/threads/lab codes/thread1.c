#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int n=5;

void* func(void* a){
	for(int i=0;i<n;i++){
		printf("Child thread is printing.\n");
		sleep(3);
	}
}
int main(){
	pthread_t tid;
	pthread_create(&tid,NULL,func,NULL);
	for(int i=0;i<n;i++){
		printf("Main thread is printing%d\n\n",i);
		sleep(3);
	}
       pthread_join(tid,NULL);	
}

