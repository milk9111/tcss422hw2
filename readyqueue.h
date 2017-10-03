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
//Includes 
#include "pcb.h"
#include <stdlib.h>

//Node for ReadyQueue
typedef struct rdyQueueNode {   
	PCB_p myPCB;                //Has PCB Pointer
	struct rdyQueueNode *next;  //Has Pointer to next Node
} rdyQueueNode_s;

//Defining a pointer for ReadyQueueNode
typedef rdyQueueNode_s * rdyQueueNode_p; 

//ReadyQueue
typedef struct readyQueue {    
    rdyQueueNode_p top;        //Pointer to first Node in queue
} readyQueue_s;

//Defining a pointer to the ReadyQueue
typedef readyQueue_s * readyQueue_p;

//Function declarations

int q_is_empty(readyQueue_s theQueue);

int q_enqueue(readyQueue_p theQueue,rdyQueueNode_s theNode);

int q_dequeue(readyQueue_s theQueue);

void readyQueueInitializer(readyQueue_p theQueue);
void rdyQueueNodeInitializer(rdyQueueNode_p theNode);
void rdyQueueNodeSetPCB(rdyQueueNode_p theNode, PCB_p thePCB);
