#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

typedef struct{
	int num1;
	int num2;
	int result;
}threadData;

void *addNumber(void *d){
	threadData* data = (threadData*)d;
	data->result= data->num1+data->num2;
	printf("%d\n",data->result);
}

int main(){
	threadData Data = {10,20,0};
	pthread_t tid;
	pthread_create(&tid,NULL,addNumber,&Data);
	pthread_join(tid,NULL);
	return 0;
}

