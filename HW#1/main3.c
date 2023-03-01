#include <stdio.h>
#include<string.h>
int main()
{
    char a[]="ABC123";
    int shift=4;
    int n=sizeof(a)-2;
    for(int z=0;z<shift;z++){
    char tmp=a[0];
    for(int i=0;i<n;i++){
        a[i]=a[i+1];
    
    }
    a[n]=tmp;
    
    }
    //print
        printf("%s",a);
    
    
    
}
