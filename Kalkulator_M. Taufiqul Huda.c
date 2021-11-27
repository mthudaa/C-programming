/**************************
KALULATOR BY M. TAUFIQUL HUDA_5022211007
***************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void HapusSpasi(char* n){
    char* a = n;
    char* b = n;
    while(*b!=0){
        *a = *b++;
        if(*a!=' '){
            a++;
        }
    }
    *a = 0;
}

int Hitung(char m[]){
    char *c = m;
    int jumlah = 0;
    while(*m){
        //nanti di ini kali bagi pangkat
        jumlah += strtol(m, &c, 10);
        m = c;
    }
    return jumlah;
}

int cek_persamaan(char *x){
    int len = strlen(x);
    int status;
    for(int i = 0; i<len; i++){
        if(x[i]=='-' && x[i+1]=='-'){
            status = 0;
            break;
        }
        else if(x[i]=='+' && x[i+1]=='+'){
            status = 0;
            break;
        }
        else if(x[i]=='-' && x[i+1]=='+'){
            status = 0;
            break;
        }
        else if(x[i]=='+' && x[i+1]=='-'){
            status = 0;
            break;
        }
        else{
            status = 1;
        }
    }
    return status;
}

int main()
{
    char num[100];
    int status;
    printf("KALKULATOR BY M. TAUFIQUL HUDA_5022211007\nMasukan persamaan matematika penjumlahan dan pengurangan\n");
    gets(num);
    HapusSpasi(num);
    status = cek_persamaan(num);
    if(status==1){
        int hasil = Hitung(num);
        printf("%s =", num);
        printf(" %d", hasil);
    }
    else{
        printf("Persamaan tidak valid");
    }
    return 0;
}
