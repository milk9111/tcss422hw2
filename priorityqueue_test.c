/*
	10/6/2017
	Authors: Connor Lundberg
	
	In this file we create 10 PCB objects with randomly assigned priorities and enqueue
	them into the priority queue, then print out the representation of the priority queue
	to show the result. We then remove 4-6 PCBs (in order of priority) and print out the
	priority queue again. We do this 10 times until we have added 100 PCBs into the 
	priority queue.
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