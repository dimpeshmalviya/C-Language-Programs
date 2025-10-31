#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>


void* func(void* a){
	int* x=(int*)a;
	for(int i=0;i<*x;i++){
		printf("Child thread is printing.\n");
		sleep(3);
	}
}
int main(){
	pthread_t tid[5];
	int n=5;
	for(int i=0;i<5;i++)
	pthread_create(&tid[i],NULL,func,&n);
	for(int i=0;i<n;i++){
		printf("Main thread is printing%d\n\n",i);
		sleep(3);
	}
	for(int i=0;i<5;i++)
       pthread_join(tid[i],NULL);	
}

