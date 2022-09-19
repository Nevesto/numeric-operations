#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 255
#define ALG 17

void decToBase(int num_dec, int base) {
   char resto[ALG] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'}, num_conv[SIZE];
   int indx = 0;

   while(num_dec > 0) {
       num_conv[indx] = resto[num_dec % base];
       num_dec /= base;
       indx++;
   }
   
   indx -= 1;
    
   switch(base) {
       case 2 : printf("BINÁŔIO: "); break;
       case 8 : printf("OCTAL: "); break;
       case 16 : printf("HEXADECIMAL: "); break;
   }
    
   for(indx; indx >= 0; indx--) 
       printf("%c", num_conv[indx]);
   printf("\n");

}

void baseToDec(char* num_base, int base) {
    int indx = 0, exp = 0, len = 0, dec = 0, num = 0;
    
    while(num_base[len] != '\0') {
        len++;
    }
    
    for(exp, indx=(len-1); exp < len; exp++, indx--) {
        if(base == 16) {
            switch(num_base[indx]) {
                case 'A' : num = 10; break;
                case 'a' : num = 10; break;
                case 'B' : num = 11; break;
                case 'b' : num = 11; break;
                case 'C' : num = 12; break;
                case 'c' : num = 12; break;
                case 'D' : num = 13; break;
                case 'd' : num = 13; break;
                case 'E' : num = 14; break;
                case 'e' : num = 14; break;
                case 'F' : num = 15; break;
                case 'f' : num = 15; break;
                default : num = (int)num_base[indx] - (int)'0';
            }
        }
        else
            num = (int)num_base[indx] - (int)'0';

        if(num > (base-1) || num < 0) {
            printf("Você informou um número inválido!\n");
            exit(0);
        }
        dec += num * pow(base, exp);
    }

    printf("DECIMAL: %d\n", dec);
}

void menu(void) {
    printf("\n===========================================================\n");
    printf("\nBEM-VINDO AO CONVERSOR DE BASES NUMÉRICAS\n\n");
    printf("QUAL OPERAÇÃO DESEJA REALIZAR? \n\n");
    printf("[ 1 ] BINÁRIO     ->  DECIMAL\n");
    printf("[ 2 ] DECIMAL     ->  BINÁRIO\n");
    printf("[ 3 ] OCTAL       ->  DECIMAL\n");
    printf("[ 4 ] DECIMAL     ->  OCTAL\n");
    printf("[ 5 ] HEXADECIMAL ->  DECIMAL\n");
    printf("[ 6 ] DECIMAL     ->  HEXADECIMAL\n");
    printf("[ 0 ] SAIR\n");
    printf("\n===========================================================\n");
}

void process_calc(int opt) {
    int number;
    char str[SIZE];
    switch(opt) {
        case 0 :
            printf("CALCULADORA ENCERRADA!\n");
            exit(0);
        case 1 : 
            printf("BINÁRIO: ");
            scanf("%s", str);
            baseToDec(str, 2);
            break;
        case 2 : 
            printf("DECIMAL: ");
            scanf("%d", &number);
            decToBase(number, 2);
            break;
        case 3 : 
            printf("OCTAL = ");
            scanf("%s", str);
            baseToDec(str, 8);
            break;
        case 4 : 
            printf("DECIMAL = ");
            scanf("%d", &number);
            decToBase(number, 8);
            break;
        case 5 : 
            printf("HEXADECIMAL = ");
            scanf("%s", str);
            baseToDec(str, 16);
            break;
        case 6 : 
            printf("DECIMAL: ");
            scanf("%d", &number);
            decToBase(number, 16);
            break;
        default :
            printf("OPÇÃO NÃO PERMITIDA!\nTENTE NOVAMENTE\n");
            break;
    }
}

int main(void) {
    int opcao;
    menu();
    printf("QUAL OPERAÇÃO DESEJA REALIZAR? ");
    scanf("%d", &opcao);
    process_calc(opcao);
    
    return 0; 
}