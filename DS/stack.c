#include<stdio.h>
#include<conio.h>
#define max 3
int main(void){
	int stk[max],i,top=-1,item,n;
	
	
	while(1)
	{
	
		printf("\n 1.push 2.pop");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
	printf("enter an item");
	scanf("%d",&item);
			if(top==max-1)
			printf("overflow");
			else
			{
				top=top+1;
				stk[top]=item;
			}
			for(i=0;i<=top;i++)
			printf("%d\t",stk[i]);
			break;
			case 2:
			if(top<0)
			printf("underflow");
			else {
				item=stk[top];
				top--;
			}
				for(i=0;i<=top;i++)
			printf("%d",stk[i]);
			break;
			case 3:
			default:
			printf("invalid ");
		}
	}
}