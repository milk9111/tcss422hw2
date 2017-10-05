/*
	10/1/2017
	Authors: Connor Lundberg, Gardner Gomes
	
	In this assignment we are creating a PCB (Process Control Block), ReadyQueue, and 
	PriorityQueue. Each is made in sequence and then used to make the next one. The PCB
	is being held within the ReadyQueue, and the PriorityQueue holds 16 ReadyQueues. 
	This is going to be used for scheduling in the final OS project.
	
	In this file we are declaring the PCB which will hold the state of the cpu when it is
	saved, as well as more information about the process such as its identification, state,
	parent, priority, position in memory, size, and channel number.
	
	This is the header file for the PCB that holds the structs of the cpu context and the 
	PCB and the declarations of the different functions.
*/

//includes
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//defines
#define ZERO 0x0000
#define MAX_MEM_SIZE 10


//structs
typedef struct cpu_context {
 // CPU state for the LC-3 processor
 unsigned int pc;
 unsigned int ir;
 unsigned int psr;
 unsigned int r0;
 unsigned int r1;
 unsigned int r2;
 unsigned int r3;
 unsigned int r4;
 unsigned int r5;
 unsigned int r6;
 unsigned int r7;
} CPU_context_s; 	// _s means this is a structure definition

typedef CPU_context_s * CPU_context_p; 	// _p means that this is a pointer to a structure

enum state_type {new, ready, running, interrupted, waiting, halted};

typedef struct pcb {
 // Process control block
 unsigned int pid; // process identification
 enum state_type state; // process state (running, waiting, etc.)
 unsigned int parent; // parent process pid
 unsigned int priority; // 0 is highest – 15 is lowest. This was previously a char.
 unsigned char * mem; // start of process in memory
 unsigned int size; // number of bytes in process
 unsigned char channel_no; // which I/O device or service Q
							// if process is blocked, which queue it is in
							
 CPU_context_p context; // set of cpu registers
						// other items to be added as needed.
} PCB_s;

typedef PCB_s * PCB;

typedef struct pidNode {
	int pid;
	struct pidNode *next;
} pidNode_s;

typedef pidNode_s * pNode;

typedef struct pidQueue {
	pNode top;
	pNode bottom;
}pidQueue_s;

typedef pidQueue_s * pQueue;


//globals
extern int pidCounter;
extern pQueue openPids;


//function declarations
PCB pcbConstructor();

pQueue pQueueConstructor();

int pcbInitialize(PCB);

int cpuContextInitialize(CPU_context_p);

CPU_context_p getCPUContext(PCB);

int setCPUContext(CPU_context_p, PCB);

void assignPID(PCB);

void pcbDeconstructor(PCB);

void toStringPCB(PCB);
