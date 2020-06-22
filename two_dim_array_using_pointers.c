#include<stdio.h>

int main()
{
	int A[3][3];
	int i,j;
	int count=1;
	int sum1=0;
	int sum2=0;
	printf("Enter the elements of Matrix A:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("Enter the element A[%d][%d]:",i,j);
			scanf("%d",(*(A+i)+j));
			count++;
		}
	}
	printf("Matrix A \n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",*(*(A+i)+j));
			if(i==j)
				sum1+=*(*(A+i)+j);
			if(i+j==2)
				sum2+=*(*(A+i)+j);
		}
		printf("\n");
	}
	printf("\n Sum of Diagonal 1:%d:",sum1);
	printf("\n Sum of Diagonal 2:%d:",sum2);
	return 0;
}
