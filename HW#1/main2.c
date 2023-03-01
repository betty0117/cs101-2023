#include <stdio.h>
int main() {
    char a[] = "A3B2C4A9";
    int x=0;
    for (int i=0; i<sizeof(a)/sizeof(a[0])-1; i++) {
        if (a[i]>='0' && a[i]<='9') {
            for (int j=0; j<a[i]-'0'; j++) {
                for (int k=x; k<i; k++) {
                    printf("%c",a[k]);
                }
            }
            x=i+1;
        }
    }
    printf("\n");
    return 0;
}
