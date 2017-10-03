#include "pcb.h"


typedef struct other_ptr {
	int ptr;
} other_ptr_s;

typedef other_ptr_s * other_ptr_p;


typedef struct ptr {
	other_ptr_p pptr;
} ptr_s;

typedef ptr_s * ptr_p;


int ptrInit(ptr_p);
int change2(other_ptr_p);
ptr_p ptrConstructor();


void main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	PCB_p pcb = pcbConstructor();
	pcbInitialize(pcb);
	printf("%d\n", sizeof(PCB_p));
	printf("%d\n", sizeof(PCB_s));
	printf("%d\n", sizeof(pcb->mem));
	printf("%d\n", sizeof(CPU_context_p));
	printf("%d\n", sizeof(CPU_context_s));
	
	ptr_p ptr2 = ptrConstructor();
	//ptrInit(ptr2);
}

int ptrInit (ptr_p ptr2) {
	int test = 0;
	
	printf ("before: %d\n", ptr2->pptr->ptr);
	change2(ptr2->pptr);
	printf ("after: %d\n", ptr2->pptr->ptr);
	
	return test;
}


ptr_p ptrConstructor () {
	ptr_p ptr2 = (ptr_p) malloc (sizeof(ptr_p));
	other_ptr_p testOther = (other_ptr_p) malloc (sizeof(other_ptr_p));
	ptr2->pptr = testOther;
	
	return ptr2;
}


int change2(other_ptr_p ptr) {
	int test = 0;
	
	ptr->ptr = 10;
	
	return test;
}


PCB_p pcbConstructor () {
	PCB_p pcb = (PCB_p) malloc (sizeof(PCB_s));
	CPU_context_p cpuContext = (CPU_context_p) malloc (sizeof(CPU_context_s));
	char * mem = (char *) malloc (sizeof(char) * MAX_MEM_SIZE);
	pcb->mem = mem;
	
	pcb->context = cpuContext;
	return pcb;
}


int pcbInitialize (PCB_p pcb) {
	int errorCode = 0;
	pcb->context->pc = 20;
	printf ("pc before: %d\n", pcb->context->pc);
	cpuContextInitialize (pcb->context);
	printf ("pc after: %d\n", pcb->context->pc);
	
	return errorCode;
}


int cpuContextInitialize (CPU_context_p cpuContext) {
	int errorCode = 0;
	
	cpuContext->pc = 10;
	
	return errorCode;
}


/*typedef struct other_ptr {
	int ptr;
} other_ptr_s;

typedef other_ptr_s * other_ptr_p;


typedef struct ptr {
	other_ptr_p pptr;
} ptr_s;

typedef ptr_s * ptr_p;


void change(int *);
void change2(other_ptr_p);
ptr_p ptrConstructor();


void main () {
	int *ptr = (int *) malloc (sizeof(int));
	change(ptr);
	printf ("after: %d\n", *ptr);
	free(ptr);
	
	ptr_p ptr2 = ptrConstructor();
	
	change2(ptr2->pptr);
	printf ("after: %d\n", ptr2->pptr->ptr);
	free(ptr2->pptr);
	free(ptr2);
}

ptr_p ptrConstructor () {
	ptr_p ptr2 = (ptr_p) malloc (sizeof(ptr_p));
	other_ptr_p testOther = (other_ptr_p) malloc (sizeof(other_ptr_p));
	ptr2->pptr = testOther;
	
	return ptr2;
}

void change(int *ptr) {
	*ptr = 10;
	printf ("before: %d\n", *ptr);
}

void change2(other_ptr_p ptr) {
	ptr->ptr = 10;
	printf ("before: %d\n", ptr->ptr);
}*/