#include<stdio.h>
int prime(int, int);
int main()
{
	int np,remcheck=1;
	printf("Enter a number:");
	scanf("%d", &np);
	remcheck = prime(np, np/2);
	if(remcheck==1)
		printf("%d is a prime number",np);
	else
		printf("%d is not a prime number",np);
	return 0;
}

int prime(int npf, int maxfind)
{
	if(maxfind == 1)
    	return 1;
    else
    {
        if(npf % maxfind == 0)
        	return 0;
        prime(npf, maxfind-1);
    }
}
