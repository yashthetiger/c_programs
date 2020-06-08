#include<stdio.h>
int main()
{
	int mark;
	printf("Enter Marks:");
	scanf("%d",&mark);    //Getting Mark from the user in the range of 100
	if(mark>=85 && mark<=100)
		printf("Grade A");
	else if(mark>=70 && mark<=84)
		printf("Grade B");
	else if(mark>=55 && mark<=69)
		printf("Grade C");
	else if(mark>=40 && mark<=54)
		printf("Grade D");
	else
		printf("Grade F");
	return 0;
}
