#include<stdio.h>
#include<stdlib.h>
#include "buffer_mgr.h"
#include "storage_mgr.h"

#define n 3

struct frame{
int val;
//int alpha;
int originalval;
int ref_bit;
bool flag;
struct frame *next;
}*head,*current;


struct frame* search_all_nodes(int pageno,struct frame **original);

insertFrame(int pagenumber,int numberOfFrames1);

intialize_ll(int val1 , int ref_bit1);

int number_of_frames(void);

int add_node(int pagenumber);

pageReplacement(int pagenumber);

int getPointerLocation();

checkIfRefBitIsZero();

struct frame *print_ll(int pageNum);

