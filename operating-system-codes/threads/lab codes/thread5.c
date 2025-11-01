#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

void* threadFunc(void *arg){
	int i,res;
	res = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,NULL);
	if(res!=0){
		printf("");
		exit(EXIT_FAILURE);
	}
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED,NULL);
	printf("the thread is still running\n");
	for(int i=0;i<10;i++){
		printf("the thread function is running %d\n",i);
		sleep(1);
	}
	pthread_exit(0);
}

int main(){
	pthread_t tid;
	pthread_create(&tid,NULL,threadFunc,NULL);
	printf("thread is beginning cancellation \n");
	pthread_cancel(tid);
	printf("waiting for the thread & finish \n");
	pthread_join(tid,NULL);
	return 0;
}

