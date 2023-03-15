#include <stdio.h>
int main(){
	FILE *fp=fopen("main.c", "r+");
	FILE *fpw = fopen("main2.txt", "w+");
	int c, line=1;
	
	fprintf(fpw,"01  ");
	while ((c = getc(fp)) != EOF)
	    c ==('\n')? fprintf(fpw,"\n%02d  ", ++line) : fprintf(fpw,"%c", c);
	fclose(fp);
	fclose(fpw);
	return 0;
}
