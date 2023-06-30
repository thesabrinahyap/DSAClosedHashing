#ifndef CLOSEDHASHING_H
#define CLOSEDHASHING_H

#include<stdbool.h>

#define EMPTY 0
#define DELETED -1
typedef struct{
	int elem;
	int link;
}Data;
 
typedef struct{
	Data *data;
	int avail;
	int count;
	int max;	
}VSpace;


int hash (int value, int size);
VSpace newVSpace(int max);
int allocSpace(VSpace *VS);
void freeSpace(VSpace *VS, int loc);
bool addElement (VSpace *VS);
bool removeElement(VSpace *VS);
void visualizeVSpace(VSpace VS);

#endif
