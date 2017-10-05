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
	PCB myPCB;                //Has PCB Pointer
	struct rdyQueueNode *next;  //Has Pointer to next Node
} rdyQueueNode_s;

//Defining a pointer for ReadyQueueNode
typedef rdyQueueNode_s * ReadyQueueNode; 

//ReadyQueue
typedef struct readyQueue {    
    ReadyQueueNode top;        //Pointer to first Node in queue
	ReadyQueueNode bottom;
} readyQueue_s;

//Defining a pointer to the ReadyQueue
typedef readyQueue_s * ReadyQueue;


//Function declarations
ReadyQueueNode rdyQueueNodeConstructor();

void rdyQueueNodeDeconstructor(ReadyQueueNode theNode);

void rdyQueueNodeSetNext(ReadyQueueNode theNode, ReadyQueueNode nextNode);

ReadyQueue readyQueueConstructor();

void readyQueueDeconstructor(ReadyQueue theQueue);

int q_isEmpty(ReadyQueue theQueue);

int q_enqueue(ReadyQueue theQueue, ReadyQueueNode theNode);

ReadyQueueNode q_dequeue(ReadyQueue theQueue);

void readyQueueInitializer(ReadyQueue theQueue);

void rdyQueueNodeInitializer(ReadyQueueNode theNode);

void rdyQueueNodeSetPCB(ReadyQueueNode theNode, PCB thePCB);

/*void toString(ReadyQueue theQueue);

void toString(ReadyQueueNode theNode);*/
