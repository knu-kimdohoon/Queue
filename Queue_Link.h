#pragma once
#include <stdio.h>
#include <malloc.h>

typedef struct QueueNode {
	char* data;
	struct QueueNode* link;
}QueueNode;

typedef struct Queue {
	QueueNode* front;
	QueueNode*	rear;
	int count;
}Queue;

Queue* CreateQueue() {
	Queue* pQueue = (Queue*)malloc(sizeof(Queue));
	if (pQueue == NULL) {
		return NULL;
	}

	pQueue->count = 0;
	pQueue->front = NULL;
	pQueue->rear = NULL;
	printf("The Queue is created\n");
	return pQueue;
}

void Enqueue(Queue* pQueue, char* data) {
	QueueNode* Node = (QueueNode*)malloc(sizeof(QueueNode));
	if (Node == NULL) {
		return;
	}
	Node->data = data;
	Node->link = NULL;

	if (pQueue->count == 0) {
		pQueue->front = pQueue->rear = Node;
	}
	else {
		pQueue->rear->link = Node;
		pQueue->rear = Node;
	}
	pQueue->count++;
	//printf("data : %s[Enqueue]\n", pQueue->front->data);
	//printf("count : %d[Enqueue]\n", pQueue->count);
}

char* Dequeue(Queue* pQueue) {
	QueueNode* dltNode = NULL;
	char* data = NULL;

	if (pQueue->count <= 0) {
		return NULL;
	}
	dltNode = pQueue->front;
	data = dltNode->data;

	if (pQueue->count == 1) {
		pQueue->front = pQueue->rear = NULL;
	}
	else {
		pQueue->front = dltNode->link;
	}

	free(dltNode);
	pQueue->count--;

	return data;
}

void DestoryQueue(Queue* pQueue) {
	QueueNode* pCur = NULL, * pNext = NULL;

	for (pCur = pQueue->front; pCur != NULL; pCur = pNext) {
		pNext = pCur->link;
		free(pCur);
	}

	pQueue->count = 0;
	pQueue->front = pQueue->rear = NULL;

	free(pQueue);

	return;
}

char* TopQueue(Queue* pQueue) {
	if (pQueue->count == 0) {
		return NULL;
	}
	else {
		char* data = pQueue->front->data;
		return data;
	}
}


