#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int mm, n[5][7], count=1, num[3], truncation;
char lottoID[10];

//binary
typedef struct{
    int receipt_id;
    int receipt_price;
    char receipt_time[32];
    int lotto_set[5][7];
}lotto_record_t;
lotto_record_t lrt;

//
void Truncation(){
	FILE *tru;
	//read a truncation to know the record of check win number
	if((tru=fopen("truncation.bin","rb")) == NULL){
		truncation=0;
		return;
	}
	fread(&truncation,sizeof(int),1,tru);
	fclose(tru);
}

void change_Truncation(){
	FILE *tru;
	//write down the truncation to remember the record of check win number
	tru=fopen("truncation.bin","wb+");
	fwrite(&lrt.receipt_id,sizeof(int),1,tru);
	fclose(tru);
}




void readID(){
	FILE *id;
	//find lotto id to int count 
	sprintf(lottoID,"lotto[%05d].txt",count);
	if((id=fopen(lottoID,"r")) == NULL)
		return;
	else{
		while((id=fopen(lottoID,"r")) != NULL){
			count++;
			sprintf(lottoID,"lotto[%05d].txt",count);
			fclose(id);
		}
	}
	sprintf(lottoID,"lotto[%05d].txt",count-1);
	fclose(id);
}

void print_To_File(){
	FILE *lot;
	int i,j;
	time_t t=time(0);
	char *c=ctime(&t);
	c[strlen(c)-1]=0;
	// generate lotto[00001], lotto[00002], ... file
	sprintf(lottoID,"lotto[%05d].txt",count);
	lot = fopen(lottoID,"w+");
	fprintf(lot,"========= lotto649 =========\n");
	fprintf(lot,"========+ No.%05d +========\n",count);
	fprintf(lot,"= %s =",c);
	for(i=1;i<=5;i++){
		fprintf(lot,"\n[%d]: ",i);
		if(i<=mm)
			for(j=0;j<7;j++)
				fprintf(lot,"%02d ",n[i-1][j]);
		else
			for(j=0;j<7;j++)
				fprintf(lot,"-- ");
	}
	fprintf(lot,"\n========= csie@CGU =========");
	fclose(lot);
}
//void print_vorform(int i) {
 //   FILE* fp;
//    fp = fopen("lotto.txt", "a+");
//    time_t curtime;
 //   time(&curtime);
    //
//    sprintf(lottoID,"lotto[%05d].txt",count);
    //
//    fprintf(fp, "======== lotto649 =========\n");
//    fprintf(fp, "=======+ No.%05d +========\n= ",count);
//    fwrite(ctime(&curtime), 24, 1, fp);
//    fseek(fp, 0, SEEK_SET);
//    fread(ctime(&curtime), 24, 1, fp);
//    fprintf(fp,"= \n");
    
//    for(int i = 1; i < 6; i++) {
        
 //       fprintf(fp,"[%d]: " , i);
 //       if(i<=mm)
        
//            for(int j = 0; j < 7; j++) {
//                fprintf(fp, "%02d",n[i-1][j]);
                    //j == 6 ? fprintf(fp,"\n") : 1;
//                }
//        else
//            for(int j=0;j<7;j++)
//                fprintf(fp,"--");
        
//    }
//    fprintf(fp, "======== csie@CGU =========\n");
//    fclose(fp);
//}

void build_Lotto(){
	int i,j,k;
	int rd,b1,b2;
	for(k=0;k<mm;k++){
		b2=0;
		for(i=0;i<7;i++){
			rd=(i!=6)?rand()%69+1:rand()%9+1;
			b1=1;
			for(j=0;j<i;j++){
				if(rd==n[k][j]){
					i--;
					b1=0;
					break;
				}
			}
			if(i==6 && k>0){
				b2=1;
				for(j=0;j<mm && (1<=n[j][6]&&n[j][6]<=10);j++){ 
					if(rd==n[j][6]){
						i--;
						b2=0;
						break;
					}
				}
			}
			if(b1&&!b2)
				n[k][i]=rd;
			else if(b1&&b2)
				n[k][6]=rd;
		}
	}
}
void insert(int t,int i,int j){
	int e=t;
	while(e<n[i][j]){
		n[i][j+1]=n[i][j];
		j--;
	}
	n[i][j+1]=e;
}

void sort(){
	int i,j;
	for(i=0;i<mm;i++)
		for(j=1;j<6;j++){
			int t=n[i][j];
			insert(t,i,j-1);
		}
}

void LottoTXT(){
	FILE *read;
	int i,j,flag=0;
	char c[32];
	//read one of lotto[00001], lotto[00002], ..., and get value into struct
	read = fopen(lottoID,"r");
	while(fgets(c,sizeof(c),read) != NULL){
		if(flag==0){
			flag++;
			continue;
		}
		else if(flag==1){
			char temp[5];
			for(i=0;c[i]!=0;i++)
				if(c[i-1]=='.'){
					for(j=0;j<5;j++,i++)
						temp[j]=c[i];
					lrt.receipt_id=atoi(temp);
					break;
				}
		}
		else if(flag==2){
			for(i=2,j=0;c[i]!='=';i++,j++)
				lrt.receipt_time[j]=c[i];
		}
		else if(3<=flag && flag<=7){
			char temp[2];
			int k=0;
			if(c[5]!='-')
				lrt.receipt_price+=100;
			for(i=5,j=0;c[i]!=0 && c[i]!='-';i++){
				if(c[i]==' '){
					k=0;
					lrt.lotto_set[flag-3][j++]=atoi(temp);
					continue;
				}
				temp[k++]=c[i];
			}
		}
		flag++;
	}
	fclose(read);
}

//record.bin
void Record(){
	FILE *record;
	//write the struct value into record.bin
	record = fopen("record.bin","ab+");
	fwrite(&lrt,sizeof(lotto_record_t),1,record);
	fclose(record);
}

void check_WinNum(){
	FILE *record;
	int k=0;
	//find win number and print to terminal
	record=fopen("record.bin","rb");
	if(record == NULL){
		printf("\n結果沒有人買彩券qq\n");
		return;
	}
	while(fread(&lrt,sizeof(lotto_record_t),1,record) != 0){
		if(lrt.receipt_id<=truncation){
			continue;
		}
		int i,j,win[5]={0},data=lrt.receipt_price/100;
		for(i=0;i<data;i++)
			for(j=0;j<7;j++)
				if(lrt.lotto_set[i][j]==num[0] || lrt.lotto_set[i][j]==num[1] || lrt.lotto_set[i][j]==num[2])
					win[i]=1;
		if(win[0]==1 || win[1]==1 || win[2]==1 || win[3]==1 || win[4]==1){
			printf("彩券 NO. %d\n",lrt.receipt_id);
			printf("售出時間：%s\n",lrt.receipt_time);
			printf("號碼：");
			
			int cnt=0;
			for(i=0;i<data;i++)
				if(win[i]==1){
					if(cnt!=0)
						printf("      ");
					for(j=0;j<7;j++)
						printf("%02d ",lrt.lotto_set[i][j]);
					cnt++;
					printf("\n");
				}
		}
	}
	fclose(record);
}



//int fwriteforma(int i) {
//    FILE* fp;
//    fp = fopen("lotto.txt", "a+");
//    fprintf(fp, "[%d]: ", i);
//    fclose(fp);
//    return 0;
//}

//int rand_num_mod70(int lotto_array) {
//    lotto_array = rand() % 69;
//    while(lotto_array == 0) { 
//        lotto_array = rand() % 69;
//    } 
//    return lotto_array;
//}

//int rand_num_mod11(int lotto_array) {
//    lotto_array = rand() % 10;
//    while(lotto_array == 0) { 
//        lotto_array = rand() % 10;
//    } 
//    return lotto_array;
//}

//int get_rad_num(int lotto_array[7]) {

//    for(int j = 0; j < 7; j++) {
//        if(j < 6){
//            lotto_array[j] = rand_num_mod70(lotto_array[j]);
//        } else if (j = 6) {
//            lotto_array[6] = rand_num_mod11(lotto_array[6]);
//        }
        //check lotto array[i] isn't 0;
//    }
//    return lotto_array[7];
//}

//int array_swap(int lotto_array[7]) {
//    int tmp = 0;
//    for(int j = 0; j < 6 ;j++) {
//        for(int arr_lotto = j; arr_lotto < 6; arr_lotto++) {
//            if (lotto_array[j] > lotto_array[arr_lotto]) {
//                tmp = lotto_array[j];
//                lotto_array[j] = lotto_array[arr_lotto];
//                lotto_array[arr_lotto] = tmp;
//            }
//        }
//    }
//    return lotto_array[7];
//}

//int array_rerandom(int lotto_array[7]) {
//    for (int j = 0; j < 6; j++) {
//        for(int z =0 ; z < 6; z++){
//            while ((lotto_array[j] == lotto_array[z] && j != z) || 
//                    lotto_array[j] == lotto_array[6]) {
//                lotto_array[j] = rand_num_mod70(lotto_array[j]);
//            }
//        }
//    }
//    return lotto_array[7];
//}

//int print_array (int lotto_array[7]) {
//    FILE* fp;
//    fp = fopen("lotto.txt", "a");
//    for(int j = 0 ; j < 7 ; j++) {
//        fprintf(fp, "%.2d ", lotto_array[j]);
//    }
//    fprintf(fp, "\n");
//    fclose(fp);
//}

//int print_last(int num_row) {
  //  FILE* fp;
 //   fp = fopen("lotto.txt", "a+");
 //   for(int i = num_row+1; i < 6; i++) {
        
//        fprintf(fp,"[%d]: " , i);
   //     for(int j = 0; j < 7; j++) {
 //           fprintf(fp, "-- ");
 //           j == 6 ? fprintf(fp,"\n") : 1;
 //       }
 //   }
//    fprintf(fp, "======== csie@CGU =========\n");
//    fclose(fp);
//}

int main() {
//    FILE* fp;
//    fp = fopen("lotto.txt", "w+");
 //   int row_num = 2;
    //
    time_t curtime;
    time(&curtime);
    //
    printf("歡迎光臨長庚樂透購買機台\n");
    printf("請問您要買幾組樂透彩:");
    scanf("%d",&mm);
    //
    if (mm==0){
        printf("請輸入中獎號碼(最多三個):");
        int n1,i;
        while(scanf("%d",&n1)){
            num[i++]=n1;
            if(getchar()=='\n')
            break;
        }
        printf("輸入中獎號碼:");
        for(i=0;1<num[i] && num[i]<=69;i++)
        printf("%02d",num[i]);
        printf("\n以下未中獎彩券:\n");
        Truncation();
        check_WinNum();
        change_Truncation();
    }
    else{
        readID();
        printf("已為您購買的 %d 組樂透組合輸出至 lotto[%05d].txt\n",mm,count);
        
        build_Lotto();
        sort();
        print_To_File();
        LottoTXT();
        Record();
    }
    
    //
//    printToFile(row_num); //fprintf1
    srand((unsigned) curtime);
 //   fprintf(fp,"=\n");
//    for (int i = 1; i <= row_num; i++) {
 //       int lotto_array[8] = {0};
//        get_rad_num(lotto_array);
//        fwriteforma(i); //fprintf2
//        lotto_array[8] = array_rerandom(lotto_array);
//        lotto_array[8] = array_swap(lotto_array);
//        print_array(lotto_array); //fprintf3
 //   }
//    print_last(row_num); //fprintf4
 //   fclose(fp);
    return 0;
}
