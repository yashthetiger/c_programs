#include<stdio.h>
int main()
{
	int a,b;
	printf("Enter number 1:");
	scanf("%d",&a);
	printf("Enter number 2:");
	scanf("%d",&b);
	a=a+b;
	b=a-b;
	a=a-b;
	//After Swapping
	printf("Number 1:%d",a);
	printf("\n");
	printf("Number 2:%d",b);
	return 0;
}
