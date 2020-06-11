#include<stdio.h>
int main()
{
	int option;
	printf("Enter the option:");   //Gets the option
	scanf("%d",&option);
	switch(option)
	{
		case 1:
			printf("\nFood item - Chicken Biryani");
			printf("\nPrice - Rs179");
			break;
		case 2:
			printf("\nFood item - Regular Full Meals");
			printf("\nPrice - 100");
			break;
		case 3:
			printf("\nFood item - Chicken 65");
			printf("\nPrice - 95");
			break;
		case 4:
			printf("\nFood item - veg Fried Rice");
			printf("\nPrice - 110");
			break;
		case 5:
			printf("\nFood item - Special Veg Biryani");
			printf("\nPrice - 149");
			break;
		default:
			printf("option is invalid");
	}
	return 0;
}
