#include <stdio.h>
int main()
{
    char a[] ="81c8g8u168";
    
    for ( int i =0; i <10;i++){
        if ( a[i] > 48 && a[i] <52){
            for( int j =0; j <a[i]-48; j++){
                printf("I");
            }
        }
        else if( a[i] ==52)
            printf("IV");
        else if( a[i] ==53)
            printf("V");
        else if( a[i] >53 && a[i] <57){
            printf("V");
            for( int j =0; j <a[i]-53; j++){
                printf("I");
            }
        }
        else if( a[i] ==57)
            printf("IX");
        else
            printf("%C",a[i]);
        
        printf(" ");
    }    
    return 0;
}
