#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "Queue_Link.h"

void main() {
	Queue* pQueue = CreateQueue();
	//Test CreateQueue
	//printf("pQueue->count : %d\n", pQueue->count);
	char name[20];
	char* data;
	int i;
	for (i = 0; i < 2; i++) {
		printf("Name : ");
		scanf("%[^\n]s", name);
		Enqueue(pQueue, name);
		scanf("%*c");
		data = TopQueue(pQueue);
		printf("Top data : %s\n", data);
		PrintAllDataInTheQueue(pQueue);
	}

	

	while (pQueue->rear != NULL) {
		data = Dequeue(pQueue);
		printf("%s\n", data);
	}
	

	DestoryQueue(pQueue);
}
