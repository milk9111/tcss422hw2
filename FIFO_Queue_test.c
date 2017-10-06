#include "readyqueue.h"
// #include "pcb.h"
void main() {
    // PriorityQueue pQueue = priorityQueueConstructor();
    ReadyQueue testQueue = readyQueueConstructor();
    PCB pcb[MAX_MEM_SIZE];
    ReadyQueueNode tempNode = rdyQueueNodeConstructor();
	//printf ("PID:   PRIORITY:\n");
	for (int i = 0; i < MAX_MEM_SIZE; i++) {
		pcb[i] = pcbConstructor();
		//printf("%d        %d\n", pcb[i]->pid, pcb[i]->priority);
		// addProcess(pcb[i], pQueue);
	}
    //Print Size of Queue
    
    toStringReadyQueue(testQueue); //print queue 
    //print last node info if exists
    rdyQueueNodeSetPCB(tempNode,pcb[0]); //set pcb of node
    q_enqueue(testQueue,tempNode); //enqueue

    toStringReadyQueue(testQueue); //print queue
	// PCB nextProcess = getNextProcess(pQueue);
	// printf("Next Process ID: %d\n", nextProcess->pid);
	// toStringPriorityQueue(pQueue);
	
	// nextProcess = getNextProcess(pQueue);
	// printf("Next Process ID: %d\n", nextProcess->pid);
	// toStringPriorityQueue(pQueue);
	
	// nextProcess = getNextProcess(pQueue);
	// printf("Next Process ID: %d\n", nextProcess->pid);
	// toStringPriorityQueue(pQueue);
}