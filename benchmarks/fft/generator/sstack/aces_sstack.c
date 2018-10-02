


#include "aces_sstack.h"
#include <stdio.h>


#define MAX_STACK_NUM 7
#define MAX_NODE_NUM 100


ACES_SSTACK stack_pool[MAX_STACK_NUM] = {0, };
NODE stack_node_pool[MAX_STACK_NUM][MAX_NODE_NUM] = {0, };


void static_InitStack(int stack_number)
{
	if(stack_number >= MAX_STACK_NUM)
	{
		printf("InitStack: error!\n");
	}

	ACES_SSTACK* stack = &stack_pool[stack_number];
	stack->stack_number = stack_number;	
	stack->size = 0;
	stack->max_size = MAX_NODE_NUM;
	stack->node_pool = stack_node_pool[stack_number];
}

int static_IsEmpty(int stack_number)
{
	ACES_SSTACK* stack = &stack_pool[stack_number];
	return stack->size == 0;
}

void static_push(int stack_number, int data)
{
	ACES_SSTACK* stack = &stack_pool[stack_number];

	if(stack->size >= stack->max_size)
	{
		printf("stack push error: Stack is full\n");
		return;
	}
	stack->node_pool[stack->size].data = data;
	stack->size++;
}

int static_pop(int stack_number)
{
	ACES_SSTACK* stack = &stack_pool[stack_number];
	if(stack->size == 0)
	{
		printf("stack pop error: Stack is empty\n");
		return -1;
	}
	int ret = stack->node_pool[stack->size].data;
	stack->size--;
	return ret;
}

void static_copy_stack(int from_stack_number, int to_stack_number)
{
	static int stack_selector = 1;
	
	ACES_SSTACK* from_stack = NULL;
	ACES_SSTACK* to_stack = NULL ;

	if(to_stack_number != -1)
	{
		from_stack = &stack_pool[from_stack_number];
		to_stack = &stack_pool[to_stack_number];
	}
	else
	{
		stack_selector++;
		from_stack = &stack_pool[from_stack_number];
		to_stack = &stack_pool[stack_selector];
	}
	to_stack->size = from_stack->size;
	
	for(int i=0; i<from_stack->size; i++)
	{
		to_stack->node_pool[i].data = from_stack->node_pool[i].data;
	}
}

void static_show_stack(int stack_number)
{
	ACES_SSTACK* stack = &stack_pool[stack_number];

	for(int i=0; i<stack->size; i++)
	{
		printf("%d ", stack->node_pool[i].data);
	}
	printf("\n");
}


unsigned int static_show_stack_size(int stack_number)
{
	ACES_SSTACK* stack = &stack_pool[stack_number];
	return stack->size;
}



