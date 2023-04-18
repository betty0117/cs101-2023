#include <stdio.h>

int g_mem[10]={0};

typedef struct my_mm{
	int a[10];
} my_mm_t;

my_mm_t ms;



int* my_calloc(int n, int size){
	int i,j;
	int t=0,b=0,c=0;
	for(i=0;i<10;i++){
		if(ms.a[i]==0)
			t++;
		else if(ms.a[i]==1){
			if(t>=size){
				b=1;
				break;
			}
			else
				t=0;	
		}
		if(ms.a[i]==1 && ms.a[i+1]==0)
			c=i+1;
	}
	if(t>=size)
		b=1;
	
	if(b){
		for(j=0;ms.a[j]!=0;j++);
		i=(c)?c:j;
		for(;i<size+c;i++){
			g_mem[i] = size;
			ms.a[i] = 1;
		}
	}
	
	for(i=0;i<10;i++)
		printf("%d",ms.a[i]);
	printf("\n");
	if(b)
		return &g_mem[j];
	else
		return NULL;
}

void my_free(int *p){
	int *q;
	int n=*p;
	int i;
	for(i=0;i<10;i++)
		if(g_mem[i]==n)
			break;
	for(q=p;*q==n;q++,i++){
		*q=0;
		ms.a[i]=0;
	}
	for(i=0;i<10;i++)
		printf("%d",ms.a[i]);
	printf("\n");
}

int main(){
	int i;
	for(i=0;i<10;i++)
		ms.a[i] = 0;
	int *anp1 = my_calloc(1,1);
	int *anp2 = my_calloc(1,2);
	int *anp3 = my_calloc(1,3);
	int *anp4 = my_calloc(1,4);
	my_free(anp1);
	my_free(anp4);
	int *anp5 = my_calloc(1,3);
	return 0;
}
