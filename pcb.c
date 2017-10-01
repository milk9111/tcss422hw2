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


/*
	The PCB constructor. This will allocate memory for the cpu context as well as the PCB
	pointer. It will also then set the PCB's mem pointer to this PCB's location in
	memory (in the heap).
*/
PCB_p pcbConstructor() {
	CPU_context_p temp_context = (CPU_context_p) malloc(sizeof(CPU_context_p));	//create cpu context to go inside pcb
	
	PCB_p pcb = (PCB_p) malloc(sizeof(PCB_p));	//create pcb
	
	pcb->context = temp_context;	
	(pcb->mem) = (char *) pcb;	//sets the location of this pcb to the mem pointer held by the pcb (so it knows where it is).

	return pcb;
}


/*
	Initializes the PCB values. This also contains a call to the cpu context initializer that
	will then initialize the cpu context values.
*/
int pcbInitialize(PCB_p thisPCB) {
	int errorNumber = 0;
	
	errorNumber = cpuContextInitialize(thisPCB->context);
	
	thisPCB->pid = 0;
	thisPCB->state = new;
	thisPCB->parent = 0;
	thisPCB->priority = 0;
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
	Prints out all contents of the PCB and its cpu context.
*/
void toString(PCB_p thisPCB) {
	printf("PCB values: \n");
	printf("pid: %d\n", thisPCB->pid);
	printf("%d\n", sizeof(thisPCB->pid));
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
	printf("%d\n", sizeof(thisPCB->state));
	printf("parent: %d\n", thisPCB->parent);
	printf("%d\n", sizeof(thisPCB->parent));
	printf("priority: %d\n", thisPCB->priority);
	printf("%d\n", sizeof(thisPCB->priority));
	printf("mem: 0x%04X\n", thisPCB->mem);
	printf("%d\n", sizeof(thisPCB->mem));
	printf("size: %d\n", thisPCB->size);
	printf("%d\n", sizeof(thisPCB->size));
	printf("channel_no: %d\n", thisPCB->channel_no);
	printf("%d\n", sizeof(thisPCB->channel_no));
	printf("%d\n", sizeof(thisPCB->context));
	
	printf("\nCPU context values: \n");
	printf("\t pc: %d\n", thisPCB->context->pc);
	printf("%d\n", sizeof(thisPCB->context->pc));
	printf("\t ir: %d\n", thisPCB->context->ir);
	printf("%d\n", sizeof(thisPCB->context->ir));
	printf("\t psr: %d\n", thisPCB->context->psr);
	printf("%d\n", sizeof(thisPCB->context->psr));
	printf("\t r0: %d\n", thisPCB->context->r0);
	printf("%d\n", sizeof(thisPCB->context->r0));
	printf("\t r1: %d\n", thisPCB->context->r1);
	printf("%d\n", sizeof(thisPCB->context->r1));
	printf("\t r2: %d\n", thisPCB->context->r2);
	printf("%d\n", sizeof(thisPCB->context->r2));
	printf("\t r3: %d\n", thisPCB->context->r3);
	printf("%d\n", sizeof(thisPCB->context->r3));
	printf("\t r4: %d\n", thisPCB->context->r4);
	printf("%d\n", sizeof(thisPCB->context->r4));
	printf("\t r5: %d\n", thisPCB->context->r5);
	printf("%d\n", sizeof(thisPCB->context->r5));
	printf("\t r6: %d\n", thisPCB->context->r6);
	printf("%d\n", sizeof(thisPCB->context->r6));
	printf("\t r7: %d\n\n", thisPCB->context->r7);
	printf("%d\n", sizeof(thisPCB->context->r7));
}


void main() {
	PCB_p thisPCB = pcbConstructor();
	pcbInitialize(thisPCB);
	toString(thisPCB);
}