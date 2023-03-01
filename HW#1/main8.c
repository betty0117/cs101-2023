#include <stdio.h>

int main()
{
    char a[] = "Hello";    
    int i;
    int len = sizeof(a)/sizeof(a[0])-1;
    int oz[len];
    int word[len];
    
    for(i = 0;i<len;i++){
        if(a[i]>='A' && a[i]<='Z'){
            oz[i] = 1;
            word[i] = a[i]-'A';
        }
        else{
            oz[i] = 0;
            word[i] = a[i]-'a';
        }
    }
    
    for(i = len-1;i>=0;i--){
        if(oz[len - i-1] == 1){
            printf("%c", 'A' + word[i]);
        }
        else{
            printf("%c", 'a' + word[i]);
        }
        
    }
    return 0;
}
