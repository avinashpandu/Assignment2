#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>



struct frame{
int val;
int originalval;
int ref_bit;
bool flag;
struct frame *next;
}*head,*current;

struct frame* search_all_nodes(int pageno,struct frame **original){

printf("In Search for page number :- %d\n",pageno);
struct frame *ptr = head;
struct frame *temp = NULL;

bool found = false;
int i = 0;
while(ptr!=NULL){
	if(i<3){
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
ptr->val = pagenumber;
ptr->ref_bit = 1;
if(numberOfFrames1 == 2){
ptr->flag = true;
current->next = ptr;
current = ptr;
current->next = head;
//head = current;
}
else{
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

ptr->next = NULL; 
head = current = ptr;

//free(ptr);
}


int number_of_frames(void) {
struct frame *ptr = head;

	int i =0;
    while(ptr != NULL)
    {
	if(i<3){
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


add_node(int pagenumber){

if(NULL == head){
printf("Buffer is not Initialized with any frame . So going to initialize frame method !\n");
intialize_ll(pagenumber,1);
}

printf("Buffer is Initialised. So  new page number [%d] is to be searched in the buffers !! \n",pagenumber);
struct frame *ptr = search_all_nodes(pagenumber,NULL);
if(NULL == ptr)
        {
            printf("\n Page number does not exists !!! \n");
		int numberOfFrames = number_of_frames();

		if(numberOfFrames < 3){
			printf(" %d Frames are empty !! Call Insert Method .\n",(3 -numberOfFrames));
			insertFrame(pagenumber,numberOfFrames);
		}
		else{
			printf("Frames are FULL. Call Page Replacement Method.\n");
			pageReplacement(pagenumber);
		}
        }
        else
        {
            printf("\n FOUND [val = %d]\n",ptr->val);
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
				if(i<3){
				if(i==framePointer){
					int j=0;
					while(j<3){
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
				if(i<3){
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
	if(i<3){
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
	if(i<3){
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
main(){
printf("IN MAIN\n");
//intialize_ll(3,2);

add_node(1);
add_node(3);
add_node(6);
print_ll();
add_node(2);
print_ll();
add_node(4);
print_ll();
add_node(5);
print_ll();
add_node(2);
print_ll();
add_node(5);
print_ll();
add_node(0);
print_ll();
add_node(3);
print_ll();
add_node(1);
print_ll();
add_node(2);
print_ll();
add_node(5);
print_ll();
add_node(4);
print_ll();
add_node(1);
print_ll();
add_node(0);
print_ll();


}



print_ll(void) {

struct frame *ptr = head;

    printf("\n -------Printing list Start------- \n");
    int i =0;
    
    while(ptr != NULL)
    {
	if(i<3){
	printf("---------------------%d----------------------\n",i);
        printf("VALUE = [%d] and REF BIT = [%d] and PREVIOUS VALUE = [%d] of FRAME [%d] with POINTER [%d] \n",
								ptr->val,ptr->ref_bit,ptr->originalval,ptr->flag);
	i = i + 1;
        ptr = ptr->next;
	}
	else break;
    }
    printf("\n -------Printing list End------- \n");


}
