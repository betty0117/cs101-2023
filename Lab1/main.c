#include <stdlib.h>
#include <stdio.h>

int main()
{
    FILE* fp;
    
    int a[]={1,2,3};
    char b[]="ABC";
    float c[]={1.1,1.2,1.3};
    int d[3];
    fp=fopen("a.bin","wb+");
    fwrite(a,sizeof(int),3,fp);
    fseek(fp,0,SEEK_SET);
    fread(d,sizeof(int),3,fp);
    for(int i=0;i<=2;i++){
        printf("%d",d[i]);
    }
    fclose(fp);

    return 0;
}
