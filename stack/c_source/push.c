#include"headers.h"
extern int top;
extern int stack[];
void push(void)
{
	int num;
	if( top == MAX-1 )
	{
		printf("STACK IS OVERFLOW\n");
		return;
	}
	else
	{
		printf("ENTER THE DATA TO PUSH\n");
		scanf("%d",&num);

//		top++;
		stack[++top]=num;
	}

}

