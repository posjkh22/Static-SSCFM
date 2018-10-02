
#include <stdio.h>
#include <stdlib.h>
 

 
typedef struct Node 
{
	unsigned int data;
	struct Node *next;
}Node;
 
typedef struct Stack 
{
	char name[10];
	unsigned int max_size;
	unsigned int size;
	Node *top;    
}Stack;
 
void InitStack(Stack *stack, const char* _name);
int IsEmpty(Stack *stack); 
void push(Stack *stack, int data); 
int pop(Stack *stack); 
void delete_stack(Stack* stack);
void show_elements(Stack* stack);
 
Stack* copy_stack(Stack* stack);
