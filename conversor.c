
//Project Name: DefaultProject
//Owner: gmello
//UID : 1000

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "conversor.h"

int main(void){

    int numero;
    int decimal;

    int *p_binario;
    int tamanho_binario=0;
    int binario[64]={0}; 
    char complemento2;

    int *p_octal;
    int tamanho_octal;
    int octal[21]={0};

    char *p_hexadecimal;
    int tamanho_hexa=0;
    char hexadecimal[16]={0};

    int op;

    // Menu
    printf("==================== Menu ====================\n");
    printf("1. Base2 para Base8\n");
    printf("2. Base2 para Base10\n");
    printf("3. Base2 para Base16\n");
    printf("4. Base8 para Base2\n");
    printf("5. Base8 para Base10\n");
    printf("6. Base8 para Base16\n");
    printf("7. Base10 para Base2.\n");
    printf("8. Base10 para Base8.\n");
    printf("9. Base10 para Base16.\n");
    printf("10. Base16 para Base2.\n");
    printf("11. Base16 para Base8.\n");
    printf("12. Base16 para Base10.\n");
    printf(">> ");
    do{
        scanf("%d", &op);
    }while( op > 12 || op < 0);

    switch(op){
        case 1:
            printf("Numero (base 2): ");
            scanf("%d", &numero);

            // Leitura
            ler_binario(binario, &tamanho_binario, numero);
            p_octal = base10_base8( base2_base10(binario, tamanho_binario), &tamanho_octal);  

            printf("Numero (base 8):");
            for(int i=tamanho_octal-1; i >= 0; i--)
                printf("%d", p_octal[i]);
            printf("\n");

            break;

        case 2:
            printf("Em Complemento de 2 ? S-Sim N-Não ");
            do{
                scanf("%c", &complemento2);
                complemento2 = toupper(complemento2);
            }while( complemento2 != 'S' && complemento2 != 'N');

            if( complemento2 == 'S'){
                printf("Numero (base 2): ");
                scanf("%d", &numero);
                
                // Leitura
                ler_binario(binario, &tamanho_binario, numero);
                decimal = base2_base10c2(binario, tamanho_binario);  

                printf("Numero (base 10): %d\n", decimal);
            }
            else{
                printf("Numero (base 2): ");
                scanf("%d", &numero);
                
                // Leitura
                ler_binario(binario, &tamanho_binario, numero);
                decimal = base2_base10(binario, tamanho_binario);  

                printf("Numero (base 10): %d\n", decimal);
            }

            break;

        case 3:

            printf("Numero (base 2): ");
            scanf("%d", &numero);

            // Leitura
            ler_binario(binario, &tamanho_binario, numero);
            p_hexadecimal = base10_base16( base2_base10(binario, tamanho_binario), &tamanho_hexa);  

            printf("Numero (base 16): 0x");
            for(int i=tamanho_hexa-1; i >= 0; i--){
                if( p_hexadecimal[i] == 10)
                    printf("%c",'A');
                else if( p_hexadecimal[i] == 11)
                    printf("%c",'B');
                else if( p_hexadecimal[i] == 12)
                    printf("%c",'C');
                else if( p_hexadecimal[i] == 13)
                    printf("%c",'D');
                else if( p_hexadecimal[i] == 14)
                    printf("%c",'E');
                else if( p_hexadecimal[i] == 15)
                    printf("%c",'F');
                else
                    printf("%d", p_hexadecimal[i]);
            }
            printf("\n");


             
            printf("\n");

            break;

        case 4:
            printf("Numero (base 8): ");
            scanf("%d", &numero);

            // Leitura e conversão do numero na base 8 para base 2
            ler_octal( octal, &tamanho_octal, numero); 
            p_binario=base10_base2(base8_base10(octal, tamanho_octal), &tamanho_binario);

            // mostra o valor na base 2
            printf("Numero (base 2): ");
            for(int i=tamanho_binario-1; i >= 0; i--)
                printf("%d", p_binario[i]);
            printf("\n");

            break;

        case 5:
            printf("Numero (base 8): ");
            scanf("%d", &numero);

            // Leitura e conversão do numero na base 8 para base 2
            ler_octal( octal, &tamanho_octal, numero); 
            decimal=base8_base10(octal, tamanho_octal);

            // mostra valor na base 10
            printf("Numero (base 10): %d\n", decimal);

            break;
        case 6:
            printf("Numero (base 8): ");
            scanf("%d", &numero);

            // Leitura e conversão do numero na base 8 para base 16
            ler_octal( octal, &tamanho_octal, numero); 
            p_hexadecimal=base10_base16( base8_base10(octal, tamanho_octal), &tamanho_hexa);

            // mostra o valor na base 16
            printf("Numero (base 16): 0x");
            for(int i=tamanho_hexa-1; i >= 0; i--){
                if( p_hexadecimal[i] == 10)
                    printf("%c",'A');
                else if( p_hexadecimal[i] == 11)
                    printf("%c",'B');
                else if( p_hexadecimal[i] == 12)
                    printf("%c",'C');
                else if( p_hexadecimal[i] == 13)
                    printf("%c",'D');
                else if( p_hexadecimal[i] == 14)
                    printf("%c",'E');
                else if( p_hexadecimal[i] == 15)
                    printf("%c",'F');
                else
                    printf("%d", p_hexadecimal[i]);
            }
            printf("\n");

            break;

        case 7:
            printf("Numero (base 10): ");
            scanf("%d", &decimal);

            p_binario = base10_base2(decimal, &tamanho_binario);

            printf("Numero (base 2): ");
            for(int i=tamanho_binario-1; i >= 0; i--)
                printf("%d", p_binario[i]);
            printf("\n");

            break;

        case 8:
            printf("Numero (base 10): ");
            scanf("%d", &decimal);

            p_octal=base10_base8(decimal, &tamanho_octal);

            printf("Numero (base 8): ");
            for(int i=tamanho_octal-1; i >= 0; i--)
                printf("%d", p_octal[i]);
            printf("\n");
            
            break;

        case 9:
            printf("Numero (base 10): ");
            scanf("%d", &decimal);

            p_hexadecimal=base10_base16(decimal, &tamanho_hexa);

            // mostra o valor na base 16
            printf("Numero (base 16): 0x");
            for(int i=tamanho_hexa-1; i >= 0; i--){
                if( p_hexadecimal[i] == 10)
                    printf("%c",'A');
                else if( p_hexadecimal[i] == 11)
                    printf("%c",'B');
                else if( p_hexadecimal[i] == 12)
                    printf("%c",'C');
                else if( p_hexadecimal[i] == 13)
                    printf("%c",'D');
                else if( p_hexadecimal[i] == 14)
                    printf("%c",'E');
                else if( p_hexadecimal[i] == 15)
                    printf("%c",'F');
                else
                    printf("%d", p_hexadecimal[i]);
            }

            printf("\n");


            break;

        case 10:
           printf("Numero (base 16): ");
           scanf("%s", hexadecimal);
           tamanho_hexa=16;

           // Leitura
           ler_hexa(hexadecimal, tamanho_hexa);
           p_binario=base10_base2(base16_base10(hexadecimal, tamanho_hexa), &tamanho_binario);

           printf("Numero (base 2): ");
           for(int i=tamanho_binario-1; i >= 0; i--)
               printf("%d", p_binario[i]);
           printf("\n");

            break;

        case 11:
           printf("Numero (base 16): ");
           scanf("%s", hexadecimal);
           tamanho_hexa=16;

           // Leitura
           ler_hexa(hexadecimal, tamanho_hexa);
           p_octal=base10_base8(base16_base10(hexadecimal, tamanho_hexa), &tamanho_octal);

           printf("Numero (base 8): ");
           for(int i=tamanho_octal-1; i >= 0; i--)
               printf("%d", p_octal[i]);

           printf("\n");
            break;

        case 12:
           printf("Numero (base 16): ");
           scanf("%s", hexadecimal);
           tamanho_hexa=16;

           // Leitura
           ler_hexa(hexadecimal, tamanho_hexa);
           decimal=base16_base10(hexadecimal, tamanho_hexa);

           printf("Numero (base 10): %d\n", decimal);

           printf("\n");
            break;


    }

	return 0;

}


