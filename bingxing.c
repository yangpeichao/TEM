#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<math.h>
#include <pthread.h>


#define BUF_num  400000
typedef struct {
	int nothing[1000];
	float num;
}Data;

Data Buf_area[BUF_num] = {0};

void *calculate(void* thread_arg)
{	
	int thread_argn;
	thread_argn=(int)(*((int*)thread_arg));
	//float buf[1000] = {0};
	struct timeval tv1, tv2;
	gettimeofday(&tv1, NULL);
	//printf("thread %d begin running in msec:%ld\n", thread_argn,1000 * tv1.tv_sec + tv1.tv_usec / 1000);
	int Dest;
	for (int i = 0; i < 1000000; i++) {
		Dest = rand() % BUF_num;
		Buf_area[Dest].num += 0.5;
	}
	gettimeofday(&tv2, NULL);
	printf("thread %d end running in msec:%ld\n", thread_argn,1000 * tv2.tv_sec + tv2.tv_usec / 1000);
	printf("thread %d TIME used: %ld msec\n", thread_argn,((1000 * tv2.tv_sec + tv2.tv_usec / 1000) - (1000 * tv1.tv_sec + tv1.tv_usec / 1000)));
}
void main()
{
	
	
	pthread_t tid1, tid2,tid3;
	int thread0_arg = 0;
	int thread1_arg = 1;
	int thread2_arg = 2;
	pthread_create(&tid1, NULL, calculate, &thread0_arg);
	pthread_create(&tid2, NULL, calculate, &thread1_arg);
	pthread_create(&tid3, NULL, calculate, &thread2_arg);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);
}

