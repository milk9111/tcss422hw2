/*
	10/2/2017
	Authors: Connor Lundberg, Gardner Gomes
	
	In this assignment we are creating a PCB (Process Control Block), ReadyQueue, and 
	PriorityQueue. Each is made in sequence and then used to make the next one. The PCB
	is being held within the ReadyQueue, and the PriorityQueue holds 16 ReadyQueues. 
	This is going to be used for scheduling in the final OS project.
	
	In this file we are declaring the Nodes and the Ready Queue to be used for storing the 
    PCB pointers during runtime operation. The Node had a pointer to the PCB and the next node.
    The Queue has a pointer for the node at the top and a pointer to the node at the end of the 
    queue.
*/

#include "priorityqueue.h"


PriorityQueue priorityQueueConstructor() {
	PriorityQueue pQueue = (PriorityQueue) malloc (sizeof(priority_queue_s));
	for (int i = 0; i < PRIORITY_QUEUE_LENGTH; i++) {
		pQueue->priorities[i] = readyQueueConstructor();
	}
	
	return pQueue;
}


int priorityQueueInitializer(PriorityQueue thisPQueue) {
	int errorCode = 0;
	for (int i = 0; i < PRIORITY_QUEUE_LENGTH; i++) {
		thisPQueue->priorities[i] = readyQueueInitializer();
	}
	
	return errorCode;
}	


int priorityQueueDeconstructor(PriorityQueue thisPQueue) {
	int errorCode = 0;
	for (int i = 0; i < PRIORITY_QUEUE_LENGTH; i++) {
		thisPQueue->priorities[i] = readyQueueDeconstructor();
	}
	free(thisPQueue);
	
	return errorCode;
}


void addProcess(PCB thisPCB, PriorityQueue, thisPQueue) {
	ReadyQueueNode newNode = rdyQueueNodeConstructor();
	rdyQueueNodeInitializer(newNode);
	rdyQueueNodeSetPCB(newNode, thisPCB);
	
	q_enqueue(thisPQueue->priorities[thisPCB->priority], newNode);
}


PCB getNextProcess(PriorityQueue thisPQueue) {
	PCB nextProcess = NULL;
	for (int i = 0; i < PRIORITY_QUEUE_LENGTH; i++) {
		if (!q_isEmpty(thisPQueue->priorities[i])) {
			nextProcess = q_dequeue(thisPQueue->priorities[i]);
			break;
		}
	}
	
	return nextProcess;
}


void toString(PriorityQueue thisPQueue) {
	
}


void main() {
	
}