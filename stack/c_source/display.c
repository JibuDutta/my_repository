#include"headers.h"
extern int top;
extern int stack[];
void display()
{
		int i;
		if(top==-1)
		{	
		printf("EMPTY LIST\n");
		return;
		}
		
		printf("THE ELEMENTS ARE\n");
		
		for(i=0;i<=top;i++)
		{

				printf("%d\n",stack[i]);

		}
}
