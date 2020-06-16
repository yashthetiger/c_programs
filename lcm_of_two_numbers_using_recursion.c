#include <stdio.h>
int lcm(int, int); 
int main()
{
	int a, b, result;
    int prime[100];
	printf("Enter first number: ");
    scanf("%d",&a);
    printf("Enter second number:");
    scanf("%d",&b);
    result = lcm(a, b);
    printf("LCM of %d and %d = %d\n",a,b,result);
    return 0;
}
 
int lcm(int n1, int n2)
{ 
    static int common = 1;
 
    if (common % n1 == 0 && common % n2 == 0)
    {
        return common;
    }
    common++;
    lcm(n1,n2);
    return common;
}
