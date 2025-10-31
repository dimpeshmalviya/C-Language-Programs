#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>

int counter=0; // shared resourse
sem_t sem; //semaphore


void *increment(){
	for(int i=0;i<5;i++){
		sem_wait(&sem); //enter the cs
		counter++;
		printf("Thread %ld incremented counter to %d \n",(long)pthread_self(),counter);
		sem_post(&sem);
		sleep(1);
	}
	pthread_exit(NULL);
}


int main(){
	pthread_t tid1,tid2;
	sem_init(&sem, 0, 1);

	pthread_create(&tid1,NULL,increment,NULL);
	pthread_create(&tid2,NULL,increment,NULL);

	pthread_join(tid1,NULL);
	pthread_join(tid1,NULL);

	sem_destroy(&sem);

	printf("The final count is:%d",counter);

	return 0;
}
