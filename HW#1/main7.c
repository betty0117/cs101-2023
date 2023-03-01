#include <stdio.h>

int main() {
    char a[] = "10001111";
    int decimal = 0;
    for (int i = 0; a[i] != '\0'; i++) {
        decimal = decimal << 1;  
        if (a[i] == '1') {
            decimal = decimal | 1;  
        }
    }
    char hex_str[3];
    int high = decimal >> 4; 
    int low = decimal & 0x0F;  
    hex_str[0] = (high < 10) ? (high + '0') : (high - 10 + 'A');  
    hex_str[1] = (low < 10) ? (low + '0') : (low - 10 + 'A');  
    hex_str[2] = '\0';  
    
    printf("%s\n", hex_str);
    return 0;
}
