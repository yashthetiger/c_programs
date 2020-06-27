#include<stdio.h>
#include<string.h>
#include<conio.h>
int main()
{
	FILE *fp,*fp1;
	char a[80];
	char filename[20];
	char filename1[20];   //file to which contents are to be copied
	printf("Enter file name:");
	scanf("%s",filename);
	printf("Enter the copy filename:");
	scanf("%s",filename1);
	fp=fopen(filename,"r");
	fp1=fopen(filename1,"w");
	if(feof(fp))
		printf("File doesn't contain anything");
	else
	{
		while(!feof(fp))
		{
			fgets(a,80,fp);
			fputs(a,fp1);
			printf("%s",strrev(a));
		}
	}
	fclose(fp);
	fclose(fp1);
	return 0;
}
