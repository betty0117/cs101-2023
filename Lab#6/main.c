#include <stdio.h>
int multi(int i,int j){
    if(j==1){
        printf("%d*%d=%d\n",i,j,i*j);
        return 0;
    }else{
        multi(i,j-1);
        printf("%d*%d=%d\n",i,j,i*j);
    }
}

int multiplication(int i,int j){
//    multi(9,9)
    if(i==9){
        printf("\n");
    }
    else{
        multi(i,j);
    }
}

int main(){
    multiplication(1,1);
    return 0;
}
