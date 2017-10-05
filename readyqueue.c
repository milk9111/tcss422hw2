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
    theQueue->bottom = 0;
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
    code 1 means it set the node properly.
*/
int q_enqueue(readyQueue_p theQueue, rdyQueueNode_p theNode) {
    int success = 0;
    if(q_isEmpty(*theQueue)) {
        theQueue->top = theNode;
        theQueue->bottom = theNode;
        success = 1;
        //set node to top
    } else {
        //if top has next bottom next == node
        //top next == node && bottom == node
        if(theQueue->top->next == 0) {
            theQueue->top->next = theNode;
            theQueue->bottom = theNode;
            success = 1;
        } else {
            theQueue->bottom->next == theNode;
            success = 1;
        }
    }
    return success;
}
/*
    Dequeues the first node in the queue and returns the pointer to the caller.
    then it makes the next in the queue the top of queue.
*/
rdyQueueNode_p q_dequeue(readyQueue_p theQueue) {
    rdyQueueNode_p theTopNode;
    if(q_isEmpty(*theQueue)) {
        theTopNode = 0;
    } else {
        rdyQueueNode_p temp;
        theTopNode = theQueue->top;
        theQueue->top = theQueue->top->next;
    }
    return theTopNode;
}

void main() {
    readyQueue_p myQueue= readyQueueConstructor();
    printf("HELLO WORLD!!!!\n");
    printf("%x\n",&myQueue);                            //Prints location of myQueue
    printf("%x\n",myQueue->top);                        //prints address for pointer to top
    printf("%d\n",q_isEmpty(*myQueue));                   //prints result if empty
    rdyQueueNode_p myNode1 = rdyQueueNodeConstructor();
    rdyQueueNode_p myNode2 = rdyQueueNodeConstructor();
    rdyQueueNode_p myNode3 = rdyQueueNodeConstructor();
    printf("Nodes %x %x %x\n", myNode1,myNode2,myNode3); //address of all nodes
    printf("Node %x\n", myNode1);                        //address of first node
    printf("Node 1 Next = %x\n", myNode1->next);           //address of node 1 next
    int x = q_enqueue(myQueue, myNode1);                //enqueue node 1 to top
    x = q_enqueue(myQueue, myNode2);
    printf("Node 1 Next = %x\n", myNode1->next);          
    x = q_enqueue(myQueue, myNode3);
    printf("top = %x\n",myQueue->top);                 //checking top before dequeue
    q_dequeue(myQueue);                                //dequeing         
    printf("top = %x\n",myQueue->top);                 //checking new top

}