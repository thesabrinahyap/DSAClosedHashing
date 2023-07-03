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

VSpace newSpace(int max);
int allocSpace(VSpace *VS);
void deallocSpace(VSpace *VS, int node);
int hash(int data, int size); //hash value is number mod size/2
int* rehash(VSpace VS); //call newSpace *2 then loop addelement from old vspace
bool addElement (VSpace *VS, int data);
bool removeElement (VSpace *VS, int data);
void visualize(VSpace VS);

#endif
