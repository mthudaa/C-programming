#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 100

float hitung(char*n, int awal, int akhir);
float jadi_angka(char*n, int awal, int akhir);
void get_string(char * n);
int cek_persamaan(char *n);

int main()
{
    int len;
    char n[BUFFER];
    proses :
    get_string(n);
    len = strlen(n);
    while(1){
        if(cek_persamaan(n)==1){
            float  angka = hitung(n, 0,len-1);
            if (angka < pow(10,10))
            {
                printf("hasil dari persamaan %s = %.5f\n",n ,angka);
            }
            else if(angka < pow(10,11))
            {
                printf("hasil dari persamaan %s = %.5f x 10^10\n",n ,angka/pow(10,10));
            }
            else if(angka < pow(10,12))
            {
                printf("hasil dari persamaan %s = %.5f x 10^11\n",n ,angka/pow(10,11));
            }
            else if(angka < pow(10,13))
            {
                printf("hasil dari persamaan %s = %.5f x 10^12\n",n ,angka/pow(10,12));
            }
            else if(angka < pow(10,14))
            {
                printf("hasil dari persamaan %s = %.5f x 10^13\n",n ,angka/pow(10,13));
            }
            else if(angka < pow(10,15))
            {
                printf("hasil dari persamaan %s = %.5f x 10^14\n",n ,angka/pow(10,14));
            }
            else if(angka < pow(10,16))
            {
                printf("hasil dari persamaan %s = %.5f x 10^15\n",n ,angka/pow(10,15));
            }
            else if(angka < pow(10,17))
            {
                printf("hasil dari persamaan %s = %.5f x 10^16\n",n ,angka/pow(10,16));
            }
            else if(angka < pow(10,18))
            {
                printf("hasil dari persamaan %s = %.5f x 10^17\n",n ,angka/pow(10,17));
            }
            else if(angka < pow(10,19))
            {
                printf("hasil dari persamaan %s = %.5f x 10^18\n",n ,angka/pow(10,18));
            }
            else if(angka < pow(10,20))
            {
                printf("hasil dari persamaan %s = %.5f x 10^19\n",n ,angka/pow(10,19));
            }
            else
            {
                printf("hasil dari persamaan %s = %.5f x 10^20\n",n ,angka/pow(10,20));
            }
            goto proses;
        }
        else{
            printf("persamaan tidak valid\n");
            goto proses;
        }
    }
    return 0;
}

int cek_persamaan(char *n){
    int len = strlen (n);
    int status = 1;
    for (int i = 1; i < len; i++)
    {
        if (((n[i]=='+'||n[i]=='-'||n[i]=='*'||n[i]=='/'||n[i]=='^')
                &&
            (n[i+1]=='+'||n[i+1]=='-'||n[i+1]=='*'||n[i+1]=='/'||n[i+1]=='^'))
                ||
            (n[len-1]=='+'||n[len-1]=='-'||n[len-1]=='*'||n[len-1]=='/'||n[len-1]=='^'))
        {
	        status = 0;
	        break;
	    }
	    else if ((n[0]=='+'||n[0]=='-'||n[0]=='*'||n[0]=='/'||n[0]=='^'))
        {
            status = 0;
            break;
        }
    }
    return status;
}

float jadi_angka(char*n, int awal,int akhir)
{
    float hasil = 0;
    int len = akhir-awal+1;
    for(int i = 0; i < len; i++)
    {
	char split_char;
        float tmp;
        split_char = *(n+i+awal);

        if(split_char >= '0' && split_char <= '9')
        {
            tmp = (split_char) - '0';
            hasil += ( tmp * pow(10, len-i-1));
        }
    }
    return hasil;
}

float hitung(char *n, int awal, int akhir)
{
    for(int i = 0; i < 3;i++)
    {
        if((*(n+awal) == '(') && (*(n+akhir) == ')')){
            return hitung(n, awal+1,akhir-1);
        }
        int parameter = 0;
        for(int j = awal; j < akhir; j++)
        {
            if(*(n+j) == '(') parameter++;
            else if(*(n+j) == ')') parameter--;

            if(parameter == 0)
            {
                switch(i)
                {
                    case 0:
                        if(*(n+j) == '+') return hitung(n, awal, j-1) + hitung(n, j+1, akhir);
                        if(*(n+j) == '-') return hitung(n, awal, j-1) - hitung(n, j+1, akhir);
                        break;
                    case 1:
                        if(*(n+j) == '*') return hitung(n, awal, j-1) * hitung(n, j+1, akhir);
                        if(*(n+j) == '/') return hitung(n, awal, j-1) / hitung(n, j+1, akhir);
                        break;
                    case 2:
                        if(*(n+j) == '^') return pow(hitung(n, awal, j-1), hitung(n, j+1, akhir));
                        break;
                    default:
                        break;
                }
            }
        }
    }
    return jadi_angka(n,awal,akhir);
}
void get_string(char *n)
{
    printf("\nIni adalah kalkulator M. Taufiqul Huda_5022211007\nMasukan persamaan matematika anda\n");
    gets(n);
    char *a = n;
    char *b = n;
    while (*b != 0)
    {
        *a = *b++;
        if (*a != ' ')
	    {
	        a++;
	    }
    }
    *a = 0;
}
