#include<stdio.h>

int main()
{
	int n;
	
	printf("1. Addition\n");
	printf("2. Subtraction\n");
	printf("3. Multiplication\n");
	printf("4. Division\n");
	
	printf("Select your choice:");
	scanf("%d", &n);
	
	int a,b;
	printf("Enter any two numbers");
	scanf("%d %d", &a, &b);
	
	switch(n)
	{
		case 1:
			printf("The sum is %d",a+b);
			break;
	    case 2:
	    	printf("The difference is %d",a-b);
	    	break;
	    case 3:
		    printf("The Product is %d",a*b);
			break;
		case 4:
		     printf("The division is %d",a/b);
			 break;
	    default:
	    	printf("SYNTAX ERROR");
	    	break;
		      	
	}
	
	return 0;
}
