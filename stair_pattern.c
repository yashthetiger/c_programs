#include<stdio.h>
int main()
{
	int n;
	int i,j;
	printf("Enter number of stairs:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
			printf("01");
		}
		printf("\n");
	}
	
}
