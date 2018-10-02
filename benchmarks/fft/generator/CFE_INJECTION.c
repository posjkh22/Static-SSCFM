
#include "CFE_INJECTION.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


int CFE_INJECTION_NUMBER = 0;

void CFE_INJECTION(int i, int type)
{
	
	srand(time(NULL));

	static int flag = 0;
	static int rand_value = 0;


	if(flag == 0)
	{
		rand_value = rand() % 100;
		flag = 1;
	}
	
	if(rand_value == i)
	{
		printf(" CFE_OCCURS: %d", i);

		if(type == 0)
		{
			printf(" (return basicblock)\n");
		}
		else if(type == 1)
		{
			printf(" (call basicblock)\n");
		}
		else if(type == 2)
		{
			printf(" (branch basicblock)\n");
		}
		/*
		else if(type == 3)
		{
			printf(" (return basicblock)\n");
		}
		*/
		else
		{
			printf(" (undefined basicblock type)\n");
		}
	}

	/*
	asm ("jmp 0x4035d5;");
	*/

	void* current_address = &&current_address_label;
current_address_label:

	printf(" current address: %x\n", current_address);


	//goto (&&current_address_label - 0x10);

}
