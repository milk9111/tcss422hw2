/*
	10/1/2017
	Authors: Gardner Gomes, Connor Lundberg
	
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
ReadyQueueNode rdyQueueNodeConstructor() {
    ReadyQueueNode myNode = (ReadyQueueNode) malloc(sizeof(rdyQueueNode_s));
    rdyQueueNodeInitializer(myNode);
    return myNode;
}


void rdyQueueNodeDeconstructor(ReadyQueueNode thisNode) {
    pcbDeconstructor(thisNode->myPCB);
	free(thisNode);
}


void rdyQueueNodeInitializer(ReadyQueueNode theNode) {
    theNode->next = 0;
    theNode->myPCB = 0;
}


void rdyQueueNodeSetPCB(ReadyQueueNode theNode, PCB thePCB) {
    theNode->myPCB = thePCB;
}


/* 
    Sets the Value for the next Node
*/
void rdyQueueNodeSetNext(ReadyQueueNode theNode, ReadyQueueNode nextNode) {
    theNode->next = nextNode;
}
/*
    q_isEmpty Return 1 if the queue is empty 
*/
int q_isEmpty(ReadyQueue theQueue) {
    int isEmpty = 0;
    if(!theQueue->top) {
        isEmpty = 1;
    }
    return isEmpty;
}

/*
    Constructor for the Ready Queue
*/
ReadyQueue readyQueueConstructor() {
	ReadyQueue myReadyQueue = (ReadyQueue) malloc(sizeof(readyQueue_s));
    readyQueueInitializer(myReadyQueue);
	return myReadyQueue;
}


void readyQueueDeconstructor(ReadyQueue theQueue) {
	while(!q_isEmpty(theQueue)) {
		ReadyQueueNode node = q_dequeue(theQueue);
		rdyQueueNodeDeconstructor(node);
	}
	free(theQueue);
}


/*
    The Initializer for the values of the ReadyQueue
*/
void readyQueueInitializer(ReadyQueue theQueue) {
    theQueue->top = 0;
    theQueue->bottom = 0;
    theQueue->size = 0;
}





/*
    sets the last nodes next value to the address of the node sent in as a paramater
    code 1 means it set the node properly.
*/
int q_enqueue(ReadyQueue theQueue, ReadyQueueNode theNode) {
    int success = 0;
    if(q_isEmpty(theQueue)) {
        theQueue->top = theNode;
        theQueue->bottom = theNode;
        theQueue->top->myPCB->state = ready;
        success = 1;
        //set node to top
    } else {
        //if top has next bottom next == node
        //top next == node && bottom == node
        if(theQueue->top->next == 0) {
            theQueue->top->next = theNode;
            theQueue->bottom = theNode;
            theQueue->bottom->myPCB->state = ready;
            success = 1;
        } else {
            theQueue->bottom->next = theNode;
			theQueue->bottom = theQueue->bottom->next;
            theQueue->bottom->next = NULL;
            theQueue->bottom->myPCB->state = ready;
        }
            success = 1;
    }
    if(success == 1) {
        theQueue->size = theQueue->size + 1;
    }
    return success;
}


/*
    Dequeues the first node in the queue and returns the pointer to the caller.
    then it makes the next in the queue the top of queue.
*/
ReadyQueueNode q_dequeue(ReadyQueue theQueue) {
    ReadyQueueNode theTopNode;
    if(q_isEmpty(theQueue)) {
        theTopNode = 0;
        theQueue->size = 0;
    } else {
        ReadyQueueNode temp;
        theTopNode = theQueue->top;
        theQueue->top = theQueue->top->next;
        theQueue->size = theQueue->size - 1;
        theTopNode->myPCB->state = running;
    }
    return theTopNode;
}


int getSize (ReadyQueue theQueue) {
	int size = theQueue->size;
	return size;
}


void toStringReadyQueueNode(ReadyQueueNode theNode) {
	printf("|%d|",theNode->myPCB->pid);
    if(theNode->next != 0) {
        printf("--->");
    } else {
        printf("--->NULL");
    }
}

void toStringReadyQueue(ReadyQueue theQueue) {
    if(theQueue->top == 0) {
        printf("NULL\r\n");
    } else {
        ReadyQueueNode temp = theQueue->top;
        while(temp != 0) {
            toStringReadyQueueNode(temp);
            temp = temp->next;
        }
		printf("\r\n");
    }
}

