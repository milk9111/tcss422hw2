/*
*/

#include "priorityqueue.h"

#define PCB_BATCH 10
#define MIN_DCOUNT 4
#define MAX_DCOUNT 6


void main() {
	time_t j;
	srand((unsigned) time(&j));
	PriorityQueue pQueue = priorityQueueConstructor();

	for (int j = 0; j < PCB_BATCH; j++) {
		printf("Adding 10 more PCBs\r\n");
		for (int i = 0; i < PCB_BATCH; i++) {
			PCB pcb = pcbConstructor();
			addProcess(pcb, pQueue);
		}
		int dCount = rand() % MAX_DCOUNT;
		if (dCount < MIN_DCOUNT) {
			dCount = dCount + (MIN_DCOUNT - dCount);
		}
		printf("Before dequeue:\r\n");
		toStringPriorityQueue(pQueue);
		
		for (int k = 0; k < dCount; k++) {
			PCB nextProcess = getNextProcess(pQueue);
			printf("Dequeued ");
			toStringPCB(nextProcess, 0);
			printf("\r\n");
		}
		printf("\r\nAfter dequeue:\r\n");
		toStringPriorityQueue(pQueue);
		
	}
	priorityQueueDeconstructor(pQueue);
	printf("PriorityQueue Deconstructed\r\n");
	
	/*PCB nextProcess = getNextProcess(pQueue);
	printf("Next Process ID: %d\n", nextProcess->pid);
	toStringPriorityQueue(pQueue);
	
	nextProcess = getNextProcess(pQueue);
	printf("Next Process ID: %d\n", nextProcess->pid);
	toStringPriorityQueue(pQueue);
	
	nextProcess = getNextProcess(pQueue);
	printf("Next Process ID: %d\n", nextProcess->pid);
	toStringPriorityQueue(pQueue);
	
	addProcess(nextProcess, pQueue);
	printf("Added Process ID: %d\n", nextProcess->pid);
	toStringPriorityQueue(pQueue);*/
}