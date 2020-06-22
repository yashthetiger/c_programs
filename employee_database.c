#include<stdio.h>
struct employee
{
	int empid;
	char emp_name[20];
	int age;
	char department[20];
	char phone_number[11];
	int salary;
};
void display(struct employee e)
{
	printf("%d\t",e.empid);
	printf("%s\t",e.emp_name);
	printf("%d\t",e.age);
	printf("%s\t",e.phone_number);
	printf("%d\t",e.salary);
	printf("%s\t",e.department);
}
int main()
{
	int i;
	int n;
	printf("Enter of employees:");
	scanf("%d",&n);
	struct employee emp[n];
	for(i=0;i<n;i++)
	{
		printf("Enter Emp_Id:");
		scanf("%d",&emp[i].empid);
		printf("Enter Name:");
		scanf("%s",emp[i].emp_name);
		printf("Enter Department:");
		scanf("%s",emp[i].department);
		printf("Enter Age:");
		scanf("%d",&emp[i].age);
		printf("Enter Phone number:");
		scanf("%s",emp[i].phone_number);
		printf("Enter Salary:");
		scanf("%d",&emp[i].salary);
	}
	printf("Emp_Id\tName\tAge\tPhone Number\tSalary\tDepartment");
	for(i=0;i<n;i++)
	{
		printf("\n");
		display(emp[i]);
	}
	return 0;
}

