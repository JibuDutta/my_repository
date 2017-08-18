#include"headers.h"

int stack[MAX];
int top=-1;

int main()
{
		char choice;

		while(1){

				printf("\n>>>>>>>MY STACK LIST<<<<<<<<<\n");
				printf(" i:PUSH\n p:POP\n d:DISPLAY\n q:QUIT\n\n");
				printf("ENTER YOUR CHOICE\n");
				scanf(" %c",&choice);
				switch(choice)
				{
						case 'i':push();
								 break;

						case 'p':pop();
								 break;

						case 'd':display();
								 break;

						case 'q':return;

						default:printf("INVALID CHOICE\n");
				}
		}
		return 0;
}

