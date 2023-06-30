#include <stdio.h>
#include <stdlib.h>
#include"ClosedHashing.h"

int hash (int value, int size){
	return value %(size/2);
}
VSpace newVSpace(int max){
	VSpace VS;
	VS.max = max%2 == 0? max:max+1;
	VS.count = 0;
	VS.data = malloc(sizeof(Data) * VS.max);
	VS.avail = VS.max/2;
	
	int ctr;
	for(ctr=0; ctr<VS.avail; ++ctr){
		VS.data[ctr].elem = EMPTY;
		VS.data[ctr].link = -1;
	}
	for(; ctr<VS.max-1;++ctr){
		VS.data[ctr].elem = EMPTY;
		VS.data[ctr].link = ctr+1;
	}
	VS.data[ctr].elem = EMPTY;
	VS.data[ctr].link = -1;
	
	return VS;
}
int allocSpace(VSpace *VS){
	int retVal = VS->avail;
	
	if(retVal != -1){
		VS->avail = VS->data[VS->avail].link;
	}
	
	int retVal;
}
void freeSpace(VSpace *VS, int loc);
bool addElement (VSpace *VS, int elem){
	int ndx = hash(elem, VS->max);
	
}
bool removeElement(VSpace *VS);

void visualizeVSpace(VSpace VS){
	int ctr, half = VS.max/2;
    printf("%5s | %5s | %5s %10s %5s | %5s | %5s \n", "INDEX", "DATA", "LINK", "","INDEX", "DATA", "LINK");
    printf("----------------------          ----------------------\n");    
    for(ctr = 0; ctr < half; ++ctr) {
        printf("%5d | %5d | %5d %10s %5d | %5d | %5d \n", 
                ctr, VS.data[ctr].elem, VS.data[ctr].link, "",
                ctr + half, VS.data[ctr+half].elem, VS.data[ctr+half].link);
    }
}
