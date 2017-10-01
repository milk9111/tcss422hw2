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
	*(pcb->mem) = pcb;	//sets the location of this pcb to the mem pointer held by the pcb (so it knows where it is).

	return pcb;
}


/*
	Initializes the PCB values. This also contains a call to the cpu context initializer that
	will then initialize the cpu context values.
*/
int pcbInitialize(PCB_p thisPCB, CPU_context_p thisPCBContext) {
	int errorNumber = 0;
	
	errorNumber = cpuContextInitialize(thisPCB->context);
	
	return errorNumber;
}


/*
*/
int cpuContextInitialize(CPU_context_p thisPCBContext) {
	int errorNumber = 0;
	
	
	
	return errorNumber;
}



void main() {
	
}