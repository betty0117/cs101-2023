/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>

int main(){
    int A=0,B=0,C=0,d=0;
    char a[]="AABBBCCCCddd";
    int n=sizeof(a);
    int i;
    for(i=0;i<n;i++){
        if(a[i]=='A')
        A++;
        else if(a[i]=='B')
        B++;
        else if(a[i]=='C')
        C++;
        else if(a[i]=='d')
        d++;
    }
    printf("A%dB%dC%dd%d\n",A,B,C,d);
}
