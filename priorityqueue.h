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

//includes
#includes "readyqueue.h"


//defines
#define PRIORITY_QUEUE_LENGTH 16 


//structs
typedef struct priority_queue {
	ReadyQueue priorities[PRIORITY_QUEUE_LENGTH];
} priority_queue_s

typedef priority_queue_s * PriorityQueue;


//declarations
PriorityQueue priorityQueueConstructor();

int priorityQueueInitializer(PriorityQueue);

int priorityQueueDeconstructor(PriorityQueue);

void addProcess(PCB);

PCB getNextProcess();

void toString(PriorityQueue);

