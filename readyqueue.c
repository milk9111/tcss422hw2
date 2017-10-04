/*
	10/1/2017
	Authors: Connor Lundberg, Gardner Gomes
	
	In this assignment we are creating a PCB (Process Control Block), ReadyQueue, and 
	PriorityQueue. Each is made in sequence and then used to make the next one. The PCB
	is being held within the ReadyQueue, and the PriorityQueue holds 16 ReadyQueues. 
	This is going to be used for scheduling in the final OS project.
	
	In this file we are defining the functions declared in readyqueue.h. This will consist of
	a constructor, initializer, Enqueue, Dequeue, isEmpty, along
	with whatever other miscellaneous functions we may need. It also includes a main
	function to test the ReadyQueue and its functions.
*/

//includes
#include "readyqueue.h"

/*
    Constructor for the readyQueueNode
*/
rdyQueueNode_p rdyQueueNodeConstructor() {
    rdyQueueNode_p myNode = (rdyQueueNode_p) malloc(sizeof(rdyQueueNode_s));
    rdyQueueNodeInitializer(myNode);
    return myNode;
}
void rdyQueueNodeInitializer(rdyQueueNode_p theNode) {
    theNode->next = 0;
    theNode->myPCB = 0;
}
void rdyQueueNodeSetPCB(rdyQueueNode_p theNode, PCB_p thePCB) {
    theNode->myPCB = thePCB;
}
/* 
    Sets the Value for the next Node
*/
void rdyQueueNodeSetNext(rdyQueueNode_p theNode, rdyQueueNode_p nextNode) {
    theNode->next = nextNode;
}
/*
    Constructor for the Ready Queue
*/
readyQueue_p readyQueueConstructor() {
	readyQueue_p myReadyQueue = (readyQueue_p) malloc(sizeof(readyQueue_s));
    readyQueueInitializer(myReadyQueue);
	return myReadyQueue;
}
/*
    The Initializer for the values of the ReadyQueue
*/
void readyQueueInitializer(readyQueue_p theQueue) {
    theQueue->top = 0;

}
/*
    q_isEmpty Return 1 if the queue is empty 
*/
int q_isEmpty(readyQueue_s theQueue) {
    int isEmpty = 0;
    if(!theQueue.top) {
        isEmpty = 1;
    }
    return isEmpty;
}
/*
    sets the last nodes next value to the address of the node sent in as a paramater
*/
int q_enqueue(readyQueue_p theQueue, rdyQueueNode_s theNode) {
    int errorCode = 0;
    if(q_isEmpty(*theQueue) == 1) {
        theQueue->top = &theNode;
    } else {
        rdyQueueNode_p temp = theQueue->top;
        while (temp->next != 0) {
            temp = temp->next;
        }
        temp->next = &theNode;
    }
    return errorCode;
}

void main() {
    readyQueue_p myQueue= readyQueueConstructor();
    printf("HELLO WORLD!!!!\n");
    printf("%x\n",&myQueue);                            //Prints location of myQueue
    printf("%x\n",myQueue->top);                        //prints address for pointer to top
    printf("%d",q_isEmpty(*myQueue));                   //prints result if empty
}