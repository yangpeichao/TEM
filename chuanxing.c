#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<math.h>
#include <pthread.h>

//串行 buf数量 buf大小 读写次数
//并行 线程数 buf数量 buf大小 读写次数



 #define BUF_num  400000
// #define	 time_  3000000
// #define BUF_size  1000
typedef struct {
	int nothing[500];
	float num;
}Data;

Data Buf_area[BUF_num] = {0};



void main(int argc , char *argv[]) {
	struct timeval tv1, tv2;
	gettimeofday(&tv1, NULL);
	int Dest;
	for (int i = 0; i < 500000; i++) {
		Dest = rand() % BUF_num;
		Buf_area[Dest].num += 0.5;
	}
	gettimeofday(&tv2, NULL);
	printf("Program end running in msec:%ld\n", 1000 * tv2.tv_sec + tv2.tv_usec / 1000);
	printf("TIME used: %ld msec\n", ((1000 * tv2.tv_sec + tv2.tv_usec / 1000) - (1000 * tv1.tv_sec + tv1.tv_usec / 1000)));
}
