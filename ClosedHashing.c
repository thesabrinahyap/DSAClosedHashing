#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#include "ClosedHashing.h"

VSpace newSpace(int max){
	VSpace VS;
	int ctr;
	
	VS.data = malloc(sizeof(Data) * max);
	VS.max = VS.max%2 == 0? max: max+1;
	VS.avail = max/2;
	
	for(ctr=0; ctr<max/2; ctr++){
		//main compartment link all is -1
		VS.data[ctr].elem = EMPTY;
		VS.data[ctr].link = -1;
	}
	for(ctr = max/2; ctr<max-1; ctr++){
		//synonyms compartment link is +1
		VS.data[ctr].elem = EMPTY;
		VS.data[ctr].link = ctr+1;
	}
	VS.data[ctr].elem = EMPTY;
	VS.data[ctr].link = -1;
	
	return VS;
}
int allocSpace(VSpace *VS){
	int retVal = -1;
	
	//meaning there's no more space to allocate
	if(VS->avail != -1){
		retVal = VS->avail;
		VS->avail = VS->data[retVal].link;
	}
	
	return retVal;
}
void deallocSpace(VSpace *VS, int node){
	int retVal = -1;
	if(VS->avail != -1){
		retVal = VS->avail;
		VS->avail = VS->data[VS->avail].link;
	}
	return retVal;
}

 //hash value is number mod size/2
int hash(int data, int size){
	return data % (size/2);
}

//call newSpace *2 then loop addelement from old vspace
int* rehash(VSpace VS){
	
}

bool addElement (VSpace *VS, int data){
	int ctr;
	
	int value = hash(data, VS->max);
	
	//Thresholding and Rehashing starts here
	int maxthreshold = (70.00 * VS->max) / 100.00;
	int synonymthreshold = (70.00 * ((VS->max/2)+1)) /100.00;
	
	
	//End
	
	if(VS->data[value].elem == EMPTY || VS->data[value].elem == DELETED){
		VS->data[value].elem = data;
	}else{
		while(VS->data[value].link != -1 && VS->data[value].elem != EMPTY && VS->data[value].elem != DELETED){
			top = VS->data[value].link;
		}
		int node = allocSpace(VS);
		
		VS->data[node].elem = data;
		VS->data[node].link = -1;
		
		VS->data[top].link = node;
	}
	
	VS->count++;
	return true;
	
}
bool removeElement (VSpace *VS, int data);
void visualize(VSpace VS){
	int half = VS.max/2;
	int ctr;
	
	printf("%5s | %5s | %5s %10s %5s | %5s | %5s\n", "INDEX", "DATA", "LINK"," ","INDEX", "DATA", "LINK");
	printf("---------------------            ---------------------\n");
	for(ctr = 0; ctr<half; ctr++){
		printf("%5d | %5d | %5d %10s %5d | %5d | %5d\n", 
			   ctr, VS.data[ctr].elem, VS.data[ctr].link," ",
			   ctr+half, VS.data[ctr+half].elem, VS.data[ctr+half].link);
	}
	printf("\nSIZE: %d\n\n", VS.max);
	printf("\nAVAIL: %d\n\n", VS.avail);
}
