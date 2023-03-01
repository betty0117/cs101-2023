/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<string.h>
int main()
{
    char a[]="ABC123";
    int shift=4;
    for(int z=0;z<shift;z++){
    char tmp=a[0];
    for(int i=0;i<5;i++){
        a[i]=a[i+1];
    
    }
    a[5]=tmp;
    
    }
    //print
    for(int j=0;j<1;j++){
        printf("%s",&a[j]);
    }
    
    
}
