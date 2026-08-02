#include <stdio.h>
#include <string.h>

struct Employee
{
    char name[50];
    char post[50];
    char address[50];
    int emp_id;
    float salary;
};

void Display(struct Employee s[], int n);
void ArrangeSalary(struct Employee s[], int n);
void ArrangeNames(struct Employee s[], int n);
void SalaryConstraint(struct Employee s[], int n);
void Interns(struct Employee s[], int n);
void SalaryConstraintAddress(struct Employee s[], int n);

int main()
{
    int n, i, employee;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct Employee s[n];

    getchar(); 

    for (i = 0; i < n; i++)
    {
        s[i].emp_id = i + 1;

        printf("\nEmployee ID = %d\n", s[i].emp_id);
        s[i].name[strcspn(s[i].name, "\n")] = '\0';

        printf("Enter the name of the employee: ");
        fgets(s[i].name, sizeof(s[i].name), stdin);
       
        printf("Enter the post of the employee: ");
        fgets(s[i].post, sizeof(s[i].post), stdin);
        s[i].post[strcspn(s[i].post, "\n")] = '\0';

        printf("Enter the address of the employee: ");
        fgets(s[i].address, sizeof(s[i].address), stdin);
        s[i].address[strcspn(s[i].address, "\n")] = '\0';

        printf("Enter the salary of the employee: ");
        scanf("%f", &s[i].salary);

        getchar(); 
    }

    printf("\nWhich operation do you want to perform?\n");
    printf("1. Records based on salary\n");
    printf("2. Records based on name\n");
    printf("3. Salary between 40000 and 60000\n");
    printf("4. Records of interns\n");
    printf("5. Salary between 40000 and 60000 and living in Kathmandu\n");

    printf("Enter your choice: ");
    scanf("%d", &employee);

    switch (employee)
    {
    case 1:
        ArrangeSalary(s, n);
        printf("\nEmployees sorted according to salary:\n\n");
        Display(s, n);
        break;

    case 2:
    	ArrangeNames(s, n);
        printf("\nEmployees sorted according to names:\n\n");
        Display(s, n);
        break;

    case 3:
	    printf("\nEmployees sorted according to salary Range:\n\n");
    	SalaryConstraint(s, n);
        break;

    case 4:
        printf("\nEmployees sorted according to Interns:\n\n");
		Interns(s, n);
        break;

    case 5:
	    printf("\nEmployees sorted according to Salary Range in KTM are:\n\n");
    	SalaryConstraintAddress(s, n);
        break;

    default:
        printf("Invalid choice!\n");
    }

    return 0;
}

void ArrangeSalary(struct Employee s[], int n)
{
    int i, j;
    struct Employee temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (s[i].salary > s[j].salary)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

void ArrangeNames(struct Employee s[], int n)
{
	int i, j;
    struct Employee t;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(s[i].name, s[j].name) > 0)
            {
                t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
        }
    }
}

void SalaryConstraint(struct Employee s[], int n)
{
	int i;
	
	for(i= 0; i < n; i++)
	{
		if(s[i].salary >= 40000 && s[i].salary <= 60000)
		{
			printf("Employee ID : %d\n", s[i].emp_id);
            printf("Name        : %s\n", s[i].name);
            printf("Post        : %s\n", s[i].post);
            printf("Address     : %s\n", s[i].address);
            printf("Salary      : %.2f\n", s[i].salary);
            printf("-----------------------------\n");
		}
	}
	
}

void Interns(struct Employee s[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(strcmp(s[i].post,"Intern")==0)
		{
		   printf("Employee ID : %d\n", s[i].emp_id);
           printf("Name        : %s\n", s[i].name);
           printf("Post        : %s\n", s[i].post);
           printf("Address     : %s\n", s[i].address);
           printf("Salary      : %.2f\n", s[i].salary);
           printf("-----------------------------\n");
		}
	}
}

void SalaryConstraintAddress(struct Employee s[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		if(s[i].salary >= 40000 && s[i].salary <= 60000 && strcmp(s[i].address, "Kathmandu") == 0)
		{
			printf("Employee ID : %d\n", s[i].emp_id);
            printf("Name        : %s\n", s[i].name);
            printf("Post        : %s\n", s[i].post);
            printf("Address     : %s\n", s[i].address);
            printf("Salary      : %.2f\n", s[i].salary);
            printf("-----------------------------\n");
		}
	}
}

void Display(struct Employee s[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("Employee ID : %d\n", s[i].emp_id);
        printf("Name        : %s\n", s[i].name);
        printf("Post        : %s\n", s[i].post);
        printf("Address     : %s\n", s[i].address);
        printf("Salary      : %.2f\n", s[i].salary);
        printf("-----------------------------\n");
    }
}


