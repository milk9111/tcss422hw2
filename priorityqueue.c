/*
	10/2/2017
	Authors: Connor Lundberg, Gardner Gomes
	
	In this assignment we are creating a PCB (Process Control Block), ReadyQueue, and 
	PriorityQueue. Each is made in sequence and then used to make the next one. The PCB
	is being held within the ReadyQueue, and the PriorityQueue holds 16 ReadyQueues. 
	This is going to be used for scheduling in the final OS project.
	
	In this file we are defining the functions for our PriorityQueue. We have a constructor
	that simple calls the ReadyQueue constructor for each priority level. The initializer and
	deconstructor essentially do the same thing. This also defines the addProcess and 
	getNextProcess functions which add a new process to its priority level, as well as get the
	next process to run, respectively.
*/

#include "priorityqueue.h"


/*
	Calls the ReadyQueue constructor to make each priority level. Returns the PriorityQueue
	struct pointer after it's finished.
*/
PriorityQueue priorityQueueConstructor() {
	PriorityQueue pQueue = (PriorityQueue) malloc (sizeof(priority_queue_s));
	for (int i = 0; i < PRIORITY_QUEUE_LENGTH; i++) {
		pQueue->priorities[i] = readyQueueConstructor();
	}
	
	priorityQueueInitializer(pQueue);
	
	return pQueue;
}


/*
	Calls the ReadyQueue initializer to start each priority level. Returns an error code.
*/
int priorityQueueInitializer(PriorityQueue thisPQueue) {
	int errorCode = 0;
	for (int i = 0; i < PRIORITY_QUEUE_LENGTH; i++) {
		readyQueueInitializer(thisPQueue->priorities[i]);
	}
	
	return errorCode;
}	


/*
	Calls the ReadyQueue deconstructor to free each priority level, then frees the PriorityQueue.
	Returns an error code.
*/
int priorityQueueDeconstructor(PriorityQueue thisPQueue) {
	int errorCode = 0;
	for (int i = 0; i < PRIORITY_QUEUE_LENGTH; i++) {
		readyQueueDeconstructor(thisPQueue->priorities[i]);
	}
	free(thisPQueue);
	
	return errorCode;
}


/*
	Creates a new ReadyQueueNode and sets its PCB value to the one provided, then enqueues
	the new node into the ReadyQueue at the PCBs priority level.
*/
void addProcess(PCB thisPCB, PriorityQueue thisPQueue) {
	ReadyQueueNode newNode = rdyQueueNodeConstructor();
	rdyQueueNodeInitializer(newNode);
	rdyQueueNodeSetPCB(newNode, thisPCB);
	
	q_enqueue(thisPQueue->priorities[thisPCB->priority], newNode);
}


/*
	Dequeues the next available PCB from the PriorityQueue. Will return NULL if no values
	are available.
*/
PCB getNextProcess(PriorityQueue thisPQueue) {
	PCB nextProcess = NULL;
	for (int i = 0; i < PRIORITY_QUEUE_LENGTH; i++) {
		if (!q_isEmpty(thisPQueue->priorities[i])) {
			ReadyQueueNode node = q_dequeue(thisPQueue->priorities[i]);
			nextProcess = node->myPCB;
			free(node);
			break;
		}
	}
	
	return nextProcess;
}


void toStringPriorityQueue(PriorityQueue thisPQueue) {
	printf("\r\n");
	for (int i = 0; i < PRIORITY_QUEUE_LENGTH; i++) {
		printf("%2d: Count=%d: ", i, getSize(thisPQueue->priorities[i]));
		toStringReadyQueue(thisPQueue->priorities[i]);
	}
	printf("\r\n");
}