/*
	10/1/2017
	Authors: Connor Lundberg, Gardner Gomes
	
	In this assignment we are creating a PCB (Process Control Block), ReadyQueue, and 
	PriorityQueue. Each is made in sequence and then used to make the next one. The PCB
	is being held within the ReadyQueue, and the PriorityQueue holds 16 ReadyQueues. 
	This is going to be used for scheduling in the final OS project.
	
	In this file we are defining the functions declared in pcb.h. This will consist of
	a constructor, initializer, deconstructor, and various getters and setters, along
	with whatever other miscellaneous functions we may need. It also includes a main
	function to test the PCB and its functions.
*/

#include "pcb.h"

int pidCounter;
pQueue openPids;

/*
	The PCB constructor. This will allocate memory for the cpu context as well as the PCB
	pointer. It will also then set the PCB's mem pointer to this PCB's location in
	memory (in the heap).
*/
PCB pcbConstructor() {
	CPU_context_p temp_context = (CPU_context_p) malloc(sizeof(CPU_context_s));	//create cpu context to go inside pcb
	
	PCB pcb = (PCB) malloc(sizeof(PCB_s));	//create pcb
	
	pcb->context = temp_context;	
	pcb->mem = (char *) pcb;	//sets the location of this pcb to the mem pointer held by the pcb (so it knows where it is).

	return pcb;
}


/*
	Initializes the PCB values. This also contains a call to the cpu context initializer that
	will then initialize the cpu context values.
*/
int pcbInitialize(PCB thisPCB) {
	int errorNumber = 0;
	
	//time_t t;
	//srand((unsigned) time(&t));
	
	errorNumber = cpuContextInitialize(thisPCB->context);
	
	thisPCB->pid = 0;
	thisPCB->state = new;
	thisPCB->parent = 0;
	thisPCB->priority = rand() % 15;
	thisPCB->channel_no = 0;
	thisPCB->size = sizeof(thisPCB);
	
	return errorNumber;
}


/*
	Initializes the cpu context values.
*/
int cpuContextInitialize(CPU_context_p thisPCBContext) {
	int errorNumber = 0;
	
	 thisPCBContext->pc = 0;
	 thisPCBContext->ir = 0;
	 thisPCBContext->psr = 0;
	 thisPCBContext->r0 = 0;
	 thisPCBContext->r1 = 0;
	 thisPCBContext->r2 = 0;
	 thisPCBContext->r3 = 0;
	 thisPCBContext->r4 = 0;
	 thisPCBContext->r5 = 0;
	 thisPCBContext->r6 = 0;
	 thisPCBContext->r7 = 0;
	
	return errorNumber;
}


/*
	Returns a copy of the PCB parameter's CPU Context. This had allocated memory so it
	will need to be freed.
*/
CPU_context_p getCPUContext(PCB thisPCB) {
	CPU_context_p cpuCopy = (CPU_context_p) malloc (sizeof(CPU_context_s));
	*cpuCopy = *(thisPCB->context);
	return cpuCopy;
}


/*
	Sets the values of the passed PCB's CPU Context to the passed CPU Context values.
	This will actually set the values of the struct, not link the pointers. Returns 
	0 if everything went smoothly.
*/
int setCPUContext(CPU_context_p thisCPUContext, PCB thisPCB) {
	int errorCode = 0;
	*(thisPCB->context) = *thisCPUContext;
	return errorCode;
}


/*
	Assigns the next available Process ID to the passed PCB. It will first check the
	pid queue if there is one available, otherwise it will get the next one from the
	pidCounter and increment it.
*/
void assignPID(PCB thisPCB) {
	if (openPids->top) {
		thisPCB->pid = openPids->top->pid;
		pNode next = openPids->top->next;
		free(openPids->top);
		openPids->top = next;
	} else {
		thisPCB->pid = pidCounter;
		pidCounter++;
	}
}


/*
	Prints out all contents of the PCB and its CPU Context.
*/
void toString(PCB thisPCB) {
	printf("\nPCB values: \n");
	printf("pid: %d\n", thisPCB->pid);
	switch(thisPCB->state) {
		case new:
			printf("state: new\n");
			break;
		case ready:
			printf("state: ready\n");
			break;
		case running:
			printf("state: running\n");
			break;
		case interrupted:
			printf("state: interrupted\n");
			break;
		case waiting:
			printf("state: waiting\n");
			break;
		case halted:
			printf("state: halted\n");
			break;
	}
	printf("parent: %d\n", thisPCB->parent);
	printf("priority: %d\n", thisPCB->priority);
	printf("mem: 0x%04X\n", thisPCB->mem);
	printf("size: %d\n", thisPCB->size);
	printf("channel_no: %d\n", thisPCB->channel_no);
	printf(" |\n");
	printf(" +---> CPU context values: \n");
	printf("\t pc:  %d\n", thisPCB->context->pc);
	printf("\t ir:  %d\n", thisPCB->context->ir);
	printf("\t psr: %d\n", thisPCB->context->psr);
	printf("\t r0:  %d\n", thisPCB->context->r0);
	printf("\t r1:  %d\n", thisPCB->context->r1);
	printf("\t r2:  %d\n", thisPCB->context->r2);
	printf("\t r3:  %d\n", thisPCB->context->r3);
	printf("\t r4:  %d\n", thisPCB->context->r4);
	printf("\t r5:  %d\n", thisPCB->context->r5);
	printf("\t r6:  %d\n", thisPCB->context->r6);
	printf("\t r7:  %d\n\n", thisPCB->context->r7);
}


/*
	Returns an allocated Process ID Queue.
*/
pQueue pQueueConstructor() {
	pidCounter = 0;
	pQueue pidsTemp = (pQueue) malloc (sizeof(pidQueue_s));
	//pNode front = (pNode) malloc (sizeof(pidNode_s));
	
	pidsTemp->top = NULL;
	pidsTemp->bottom = pidsTemp->top;
	
	return pidsTemp;
}


/*
	Frees up the given PCB and puts the pid into the open pid queue.
*/
void pcbDeconstructor(PCB thisPCB) {
	if (openPids->top) {
		openPids->bottom->next = (pNode) malloc (sizeof(pidNode_s));
		openPids->bottom = openPids->bottom->next;
		openPids->bottom->pid = thisPCB->pid;
		openPids->bottom->next = NULL;
		free(thisPCB->context);
		free(thisPCB);
	} else {
		openPids->top = (pNode) malloc (sizeof(pidNode_s));
		openPids->top->next = NULL;
		openPids->top->pid = thisPCB->pid;
		free(thisPCB->context);
		free(thisPCB);
	}
}


// void main() {
// 	time_t t;
// 	srand((unsigned) time(&t));
	
// 	openPids = pQueueConstructor();
	
// 	PCB pcbs[MAX_MEM_SIZE + 1];
// 	for (int i = 0; i < MAX_MEM_SIZE; i++) {
// 		pcbs[i] = pcbConstructor();
// 		pcbInitialize(pcbs[i]);
// 		assignPID(pcbs[i]);
// 		toString(pcbs[i]);
// 	}
// 	printf("\n--------------------------------\n");
// 	pcbDeconstructor(pcbs[8]);
// 	pcbs[8] = NULL;
// 	for (int i = 0; i < MAX_MEM_SIZE; i++) {
// 		if (pcbs[i]) {
// 			toString(pcbs[i]);
// 		}
// 	}
// 	printf("\n--------------------------------\n");
// 	pcbs[MAX_MEM_SIZE] = pcbConstructor();
// 	pcbInitialize(pcbs[MAX_MEM_SIZE]);
// 	assignPID(pcbs[MAX_MEM_SIZE]);
// 	for (int i = 0; i < MAX_MEM_SIZE + 1; i++) {
// 		if (pcbs[i]) {
// 			toString(pcbs[i]);
// 		}
// 	}
// }