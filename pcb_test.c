/*
	10/6/2017
	Authors: Connor Lundberg
	
	This is a simple test file to create two separate PCB objects and show that
	they both receive different PIDs and priorities.
*/

#include "pcb.h"


void main() {
	PCB test1 = pcbConstructor();
	toStringPCB(test1, 1);
	printf("\n");
	PCB test2 = pcbConstructor();
	toStringPCB(test2, 1);
	/*PCB pcbs[MAX_MEM_SIZE + 1];
	for (int i = 0; i < MAX_MEM_SIZE; i++) {
		pcbs[i] = pcbConstructor();
		toStringPCB(pcbs[i]);
	}
	printf("\n--------------------------------\n");
	pcbDeconstructor(pcbs[8]);
	pcbs[8] = NULL;
	for (int i = 0; i < MAX_MEM_SIZE; i++) {
		if (pcbs[i]) {
			toStringPCB(pcbs[i]);
		}
	}
	printf("\n--------------------------------\n");
	pcbs[MAX_MEM_SIZE] = pcbConstructor();
	for (int i = 0; i < MAX_MEM_SIZE + 1; i++) {
		if (pcbs[i]) {
			toStringPCB(pcbs[i]);
		}
	}*/
}