#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "Queue_Link.h"


void main() {
	Queue* pQueue = CreateQueue();
	//Test CreateQueue
	//printf("pQueue->count : %d\n", pQueue->count);
	char name[20];
	char* data;
	char* nPtr = NULL;
	int i;
	for (i = 0; i < 4; i++) {
		printf("Name : ");
		scanf("%[^\n]s", name);
		nPtr = (char*)malloc((strlen(name)+2) * sizeof(char));
		if (nPtr == NULL) {
			exit(1);
		}
		else {
			strcpy(nPtr, name);
			printf("%s\n", nPtr);
			Enqueue(pQueue, nPtr);
			free(nPtr);
			scanf("%*c");
			data = TopQueue(pQueue);
			printf("Top data : %s\n", data);
			PrintAllDataInTheQueue(pQueue);
		}
	}

	

	while (pQueue->rear != NULL) {
		data = Dequeue(pQueue);
		printf("%s\n", data);
	}
	

	DestoryQueue(pQueue);
}
