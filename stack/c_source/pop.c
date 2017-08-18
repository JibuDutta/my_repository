#include"headers.h"

extern int top;
extern int stack[];

void pop()
{
		if(top==-1)
		{
				printf("STACK IS UNDERFLOW\n");
		}

		else
		{	
				printf("\nTHE POP DATA IS %d\n",stack[top]);
				top--;
		}

}
