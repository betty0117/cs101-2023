#include <stdlib.h>
#include <stdio.h>

int main()
{
    FILE* fp;
    fp=fopen("a.bin","wb+");
    int a[]={1,2,3};
    char b[]="ABC";
    float c[]={1.1,1.2,1.3};
    for(int i=0;i<=2;i++){
        fprintf(fp,"%d ",a[i]);
    }
    fclose(fp);

    return 0;
}
