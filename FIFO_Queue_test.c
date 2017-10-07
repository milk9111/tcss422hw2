#include "readyqueue.h"
#include <stdlib.h>
// #include "pcb.h"
#define MAX_NODES 30
#define MIN_NODES 10

void main() {
    srand(time(NULL));
    int number = rand() % (MAX_NODES + 1 - MIN_NODES) + MIN_NODES;
    ReadyQueue testQueue = readyQueueConstructor();     //make initial queue
    ReadyQueueNode tempNodes[number];                   //make list of nodes between range 10-30
    PCB pcb[number];                                    //make list of PCB's same size of nodes
    for(int i = 0; i <= number; i++) {
        tempNodes[i] = rdyQueueNodeConstructor();       //COnstruct Nodes
        pcb[i] = pcbConstructor();                      //COnstruct PCB's for Nodes
        rdyQueueNodeSetPCB(tempNodes[i],pcb[i]);        //Seting the PCB's to the Nodes
    }

    printf("%d\n",number);                              //Random Number Generated
    for (int i = 0; i <= number; i++) {                 //Start Loop for printing to file or console
        printf("Q:Size = %d: ",testQueue->size);        //Print size of QUeue
        toStringReadyQueue(testQueue);                  //Print queue
        if(testQueue->bottom != 0) {
            toStringPCB(testQueue->bottom->myPCB,0);    //print last node info if exists
        }   
        q_enqueue(testQueue,tempNodes[i]);              //Enqueue next Node to Queue
        printf("\n");
    }
    printf("----------------------------------------------------------------------------------------\n");
    for (int i = 0; i <= number + 1; i++) {                 //Start Loop for printing to file or console
        printf("Q:Size = %d: ",testQueue->size);        //Print size of QUeue
        toStringReadyQueue(testQueue);                  //Print queue
        if(testQueue->top != 0) {
            toStringPCB(testQueue->top->myPCB,0);       //print top node info if exists
        }   
        q_dequeue(testQueue);                           //dequeue Node in Queue
        printf("\n");
    }
 
}