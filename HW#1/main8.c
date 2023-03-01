#include <stdio.h>
#include <string.h>


int main() 
{
   
	char a[] = "Hello";

	int i, j, temp;
	int len=5;
	for (i = 0; i < len; i++){         
		for (j = 0; j < len - i; j++)  
			if (a[j] < a[j + 1])       
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
			
	}
	a[0]=a[0]-32;
	a[len-1]=a[len-1]+32;
        printf("a=Hello\n");
		printf("a=%s ", a);
		
	return 0;
}
