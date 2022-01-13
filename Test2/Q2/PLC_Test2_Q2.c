#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 30000


//static array
int staticArray(){
	int i;
	static int stArr[ARR_SIZE];
	
	for(i=0; i<ARR_SIZE; i++){
		stArr[i] = 3;
	}
}


//stack array
int stackArray(){
	int i;
	int stacArr[ARR_SIZE];
	
	for(i=0; i<ARR_SIZE; i++){
		stacArr[i] = 3;
	}
}

//heap array
int heapArray(){
	int i;
	int *heapArray = (int *) malloc(sizeof(int) * ARR_SIZE);
	
	for(i=0; i<ARR_SIZE; i++){
		heapArray[i] = 3;
	}
}


//main; count time;
int main(){
	clock_t time;
	int i;
	time = clock();
	//count time for static array
	for(i=0; i<100000;i++){
		staticArray();
	}
	time = clock() - time;
	printf("Time for static arrary is %f sec\n",(float)time/CLOCKS_PER_SEC);
	
	
	time = clock();
	//count time for stack array
	for(i=0; i<100000;i++){
		stackArray();
	}
	time = clock() - time;
	printf("Time for stack arrary is %f sec\n",(float)time/CLOCKS_PER_SEC);
	
	
	time = clock();
	//count time for heap array
	for(i=0; i<100000;i++){
		heapArray();
	}
	time = clock() - time;
	printf("Time for heap arrary is %f sec\n",(float)time/CLOCKS_PER_SEC);
	
}
