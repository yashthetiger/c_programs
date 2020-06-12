#include<stdio.h>
int sum_of_digits(int n);
int main()
{
	int number;
	printf("Input number: ");
	scanf("%d",&number);
	printf("Sum of digits: %d",sum_of_digits(number));
	return 0;
}

int sum_of_digits(int n)
{
	int sum=0;
	if(n!=0)
		return sum+(n%10)+sum_of_digits(n/10);   //Statement Causing Recursion
	else
		return 0;
}
