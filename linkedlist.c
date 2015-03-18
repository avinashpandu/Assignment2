#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "linked_list.h"
#include "buffer_mgr.h"
#include "dberror.h"


struct frame* search_all_nodes(int pageno,struct frame **original){

printf("In Search for page number :- %d\n",pageno);
struct frame *ptr = head;
struct frame *temp = NULL;

bool found = false;
int i = 0;
while(ptr!=NULL){
	if(i<n){
	if(ptr->val == pageno){
		found = true;
		printf("HIT\n");break;
	}
	else{
		printf("FAULT.PAGE REPLACEMENT / INSERT \n");
		temp = ptr;
		ptr = ptr->next;
	}
	i = i+1;
	}
	else{
	break;
	}
}

if(true == found){
	if(original)
		*original = temp;
	return ptr;
}
else{
	return NULL;
}

}

insertFrame(int pagenumber,int numberOfFrames1){
printf("In Insert Frame method !\n");
struct frame *ptr = (struct frame*)malloc(sizeof(struct frame));
head->flag=false;
ptr->val = pagenumber;
ptr->ref_bit = 1;
printf("numberOfFrames1 = %d and n = %d \n",numberOfFrames1,n);
if(numberOfFrames1 == n-1){
ptr->flag = true;
current->flag=false;
current->next = ptr;
current = ptr;
current->next = head;
//head = current;
}
else{
current->flag=false;
ptr->flag=true;
current->next = ptr;
current = ptr;
printf("Inserted 1 frame !!\n");
}

}

intialize_ll(int val1 , int ref_bit1) {
printf("Initialising the buffer with first value. \n");
struct frame *ptr = (struct frame*)malloc(sizeof(struct frame));

ptr->val = val1;
ptr->ref_bit = ref_bit1;
ptr->flag = true;

ptr->next = NULL; 
head = current = ptr;
//free(ptr);
}


int number_of_frames(void) {
struct frame *ptr = head;

	int i =0;
    while(ptr != NULL)
    {
	if(i<n){
	i = i + 1;
        ptr = ptr->next;
	}
	else{
		break;
	}
    }
	printf("Number of Frames:- %d\n",i);
	return i;

}


int add_node(int pagenumber){

if(NULL == head){
printf("Buffer is not Initialized with any frame . So going to initialize frame method !\n");
intialize_ll(pagenumber,1);
return 0;
}
else{
printf("Buffer is Initialised. So  new page number [%d] is to be searched in the buffers !! \n",pagenumber);
struct frame *ptr = search_all_nodes(pagenumber,NULL);
if(NULL == ptr)
        {
            printf("\n Page number does not exists !!! \n");
		int numberOfFrames = number_of_frames();

		if(numberOfFrames < n){
			printf(" %d Frames are empty !! Call Insert Method .\n",(n -numberOfFrames));
			insertFrame(pagenumber,numberOfFrames);
		}
		else{
			printf("Frames are FULL. Call Page Replacement Method.\n");
			pageReplacement(pagenumber);
		}
	return 0;
        }
        else
        {
            printf("\n FOUND [val = %d]\n",ptr->val);
	return 1;
        }
}
}

pageReplacement(int pagenumber){
	printf("In PAGE REPLACEMENT!!!");
	struct frame *ptr = head;
        int i=0;
	int framePointer = getPointerLocation();
	printf("Frame Points to %d \n",framePointer);

	int frameWithRefBitIsZero = checkIfRefBitIsZero();
	printf("Frame contains Reference Bit is ZERO? [%d]\n",frameWithRefBitIsZero);

	if(frameWithRefBitIsZero == -1){ //No frame contains a reference bit zero. Replace all 1->0.
		while(ptr != NULL)
   			{
				if(i<n){
				if(i==framePointer){
					int j=0;
					while(j<n){
					ptr->flag = false;
					ptr = ptr->next;
					ptr->ref_bit = 0;
					j = j+1;
					}
					ptr = ptr->next;
					ptr->ref_bit = 1;
					ptr->flag = true;
					ptr->originalval = ptr->val;
					ptr->val = pagenumber;				
				}
				else{
					ptr = ptr->next;
					//DO NOTHING.
				}
				i = i+1;		
				}
				else{
					break;
				}
				
    			}

	}
	else{    //There is a frame which has reference bit zero.framePointer=0
		while(ptr != NULL)
   			{
				if(i<n){
				if(i==framePointer){
					ptr = ptr->next;
					ptr->ref_bit = 1;
					ptr->flag = true;
					ptr->originalval = ptr->val;
					ptr->val = pagenumber;				

				}
				else{
					ptr = ptr->next;
					ptr->flag = false;
					//DO NOTHING.
				}
				i=i+1;
				}
				else{
					break;
				}
			}
	}
/*
    while(ptr != NULL)
    {
	
    } */
	printf("Pointer Movements are [%d] \n",i+1);

}

int getPointerLocation(){
    struct frame *ptr = head;
    int i =0;
    int framePointer = -1;
    while(ptr != NULL)
    {
	if(i<n){
		if(ptr->flag == true){
			framePointer = i;
			break;
		}
		else{
			i = i + 1;
        		ptr = ptr->next;
		}
	}
	else break;
    }

return framePointer;
}

checkIfRefBitIsZero(){
   struct frame *ptr = head;
    int i =0;
    int frameWithRefBitOne = -1;
    while(ptr != NULL)
    {
	if(i<n){
		if(ptr->ref_bit == 0){
			frameWithRefBitOne = i;
			break;
		}
		else{
			i = i + 1;
        		ptr = ptr->next;
		}
	}
	else break;
    }

return frameWithRefBitOne;

}


struct frame *print_ll(int pageNum) {

struct frame *ptr = head;

    int originalValue;

    printf("\n -------Printing list Start------- \n");
    int i =0;
    
    while(ptr != NULL)
    {
	if(i<n){
	printf("---------------------%d----------------------\n",i);
        printf("VALUE = [%d] and REF BIT = [%d] and PREVIOUS VALUE = [%d] of FRAME [%d] with POINTER [%d] \n",
								ptr->val,ptr->ref_bit,ptr->originalval,i,ptr->flag);
	if(ptr->val == pageNum){
		return ptr;
	}
	i = i + 1;
        ptr = ptr->next;
	}
	else break;
    }
    printf("\n -------Printing list End------- \n");

}
