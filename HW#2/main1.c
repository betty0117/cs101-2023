#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_vorform(int i) {
    FILE* fp;
    fp = fopen("lotto.txt", "a+");
    time_t curtime;
    time(&curtime);
    fprintf(fp, "======== lotto649 =========\n= ");
    fwrite(ctime(&curtime), 24, 1, fp);
    fseek(fp, 0, SEEK_SET);
    fread(ctime(&curtime), 24, 1, fp);
    fprintf(fp,"= \n");
    fclose(fp);
}

int fwriteforma(int i) {
    FILE* fp;
    fp = fopen("lotto.txt", "a+");
    fprintf(fp, "[%d]: ", i);
    fclose(fp);
    return 0;
}

int rand_num_mod70(int lotto_array) {
    lotto_array = rand() % 69;
    while(lotto_array == 0) { 
        lotto_array = rand() % 69;
    } 
    return lotto_array;
}

int rand_num_mod11(int lotto_array) {
    lotto_array = rand() % 10;
    while(lotto_array == 0) { 
        lotto_array = rand() % 10;
    } 
    return lotto_array;
}

int get_rad_num(int lotto_array[7]) {

    for(int j = 0; j < 7; j++) {
        if(j < 6){
            lotto_array[j] = rand_num_mod70(lotto_array[j]);
        } else if (j = 6) {
            lotto_array[6] = rand_num_mod11(lotto_array[6]);
        }
        //check lotto array[i] isn't 0;
    }
    return lotto_array[7];
}

int array_swap(int lotto_array[7]) {
    int tmp = 0;
    for(int j = 0; j < 6 ;j++) {
        for(int arr_lotto = j; arr_lotto < 6; arr_lotto++) {
            if (lotto_array[j] > lotto_array[arr_lotto]) {
                tmp = lotto_array[j];
                lotto_array[j] = lotto_array[arr_lotto];
                lotto_array[arr_lotto] = tmp;
            }
        }
    }
    return lotto_array[7];
}

int array_rerandom(int lotto_array[7]) {
    for (int j = 0; j < 6; j++) {
        for(int z =0 ; z < 6; z++){
            while ((lotto_array[j] == lotto_array[z] && j != z) || 
                    lotto_array[j] == lotto_array[6]) {
                lotto_array[j] = rand_num_mod70(lotto_array[j]);
            }
        }
    }
    return lotto_array[7];
}

int print_array (int lotto_array[7]) {
    FILE* fp;
    fp = fopen("lotto.txt", "a");
    for(int j = 0 ; j < 7 ; j++) {
        fprintf(fp, "%.2d ", lotto_array[j]);
    }
    fprintf(fp, "\n");
    fclose(fp);
}

int print_last(int num_row) {
    FILE* fp;
    fp = fopen("lotto.txt", "a+");
    for(int i = num_row+1; i < 6; i++) {
        fprintf(fp,"[%d]: " , i);
        for(int j = 0; j < 7; j++) {
            fprintf(fp, "-- ");
            j == 6 ? fprintf(fp,"\n") : 1;
        }
    }
    fprintf(fp, "======== csie@CGU =========\n");
    fclose(fp);
}

int main() {
    FILE* fp;
    fp = fopen("lotto.txt", "w+");
    int row_num = 2;
    time_t curtime;
    time(&curtime);
    print_vorform(row_num); //fprintf1
    srand((unsigned) curtime);
 //   fprintf(fp,"=\n");
    for (int i = 1; i <= row_num; i++) {
        int lotto_array[8] = {0};
        get_rad_num(lotto_array);
        fwriteforma(i); //fprintf2
        lotto_array[8] = array_rerandom(lotto_array);
        lotto_array[8] = array_swap(lotto_array);
        print_array(lotto_array); //fprintf3
    }
    print_last(row_num); //fprintf4
    fclose(fp);
    return 0;
}
