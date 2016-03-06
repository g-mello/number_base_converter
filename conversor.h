
#ifndef DEFAULT_H_
#define DEFAULT_H_

#endif

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

// Funções Conversoras 
int *base10_base2( int n_base10, int *tamanho){

    // Aloca um vetor int de 64 posições 
    int *binario;
    binario = (int *) calloc(64, 64 * sizeof(int));
    *tamanho=0;

    // Conversão de numero decimal positivo em binário positivo
    if( n_base10 > 0 ){

        // magnitude
        while( n_base10 > 0 ){
            binario[*tamanho] = n_base10 % 2;
            *tamanho = *tamanho+1;
            n_base10 = n_base10 / 2;
        }

        // sinal positivo
        binario[*tamanho]=0; 
        *tamanho = *tamanho + 1;

    }
    
    // Conversão de numero decimal negativo em binário negativo 
    else{
        
        // passa pra positivo
        n_base10= -1 * n_base10;

        // magnitude para o numero positivo 
        while( n_base10> 0 ){
            binario[*tamanho]=n_base10%2;        
            *tamanho = *tamanho + 1;
            n_base10 = n_base10 / 2;
        }

        // add sinal positivo
        binario[*tamanho]=0; 
        *tamanho = *tamanho + 1;
        
        //Complemento de 2, encontra o binario negativo
        // a partir do binario positivo
        for(int i=0; i <= *tamanho; i++){
            if( binario[i] == 1 ){
                for(int j=i+1; j <= *tamanho; j++){
                    if(binario[j] == 0)
                        binario[j]=1;
                    else
                        binario[j]=0;
                }
                break;
            }
        }

    }


   return binario;

}

char *base10_base16( int n_base10, int *tamanho){

    
    // Aloca um vetor char de 16 posições
    char *hexadecimais;
    hexadecimais = (char *) calloc(16, 16 * sizeof(char));

    *tamanho=0;

    if( n_base10 <= 16) {
        hexadecimais[*tamanho]=n_base10;
        *tamanho = *tamanho + 1;
    }
    else{
        while( n_base10 > 0 ){
            hexadecimais[*tamanho]=n_base10%16;        
            *tamanho = *tamanho + 1;
            n_base10 /= 16;
        }
    }

    return hexadecimais;

}

int *base10_base8( int n_base10, int *tamanho){

        // Aloca um vetor inteiro de 21 posições 
        int *octais;
        octais = (int *) calloc(21, 21 * sizeof(char));

        *tamanho=0;

        if( n_base10 <= 7 ){
            octais[*tamanho]=n_base10;
            *tamanho = *tamanho + 1;
        }
        else{
            while( n_base10 > 0 ){
                octais[*tamanho]=n_base10 % 8;
                *tamanho = *tamanho + 1;
                n_base10 /= 8;
            }
        }

        return octais;

}

int base2_base10c2( int n_base2[], int tamanho){

    float n_base10=0;

    // Verificar se o numero está na base 2
    for(int i=0; i < tamanho; i++){
        if( n_base2[i] != 0 && n_base2[i] != 1){
            printf("Erro: numero não pertence a base 2\n");
            return 0;
        }
    }

    // Verificar se o numero binario é positivo ou negativo
    // em complemento de 2
    if( n_base2[0] == 0 ){

        // Calcular a base10
        for(int i=0; i <= tamanho; i++){
            if( n_base2[i] == 1 ){
                n_base10 += pow(2,(-1*(i-(tamanho-1))));
            }
        }

    }
    else{

            // Complemento de 2, espelhamento 
            // converte de negativo para positivo
            for(int i=tamanho-1; i >= 0; i--){
                if( n_base2[i] == 1 ){
                    for(int j=i-1; j >= 0; j--){
                        if(n_base2[j] == 0)
                            n_base2[j]=1;
                        else
                            n_base2[j]=0;
                    }
                    break;
                }
            }
            
            // Calcular a base10
            for(int i=0; i <= tamanho; i++){
                if( n_base2[i] == 1 )
                    n_base10 += pow(2,(-1*(i-(tamanho-1))));
            }

            n_base10 = -1 * n_base10;
        }

    return (int ) n_base10;

}
int base2_base10( int n_base2[], int tamanho){

    float n_base10=0;

    // Verificar se o numero está na base 2
    for(int i=0; i < tamanho; i++){
        if( n_base2[i] != 0 && n_base2[i] != 1){
            printf("Erro: numero não pertence a base 2\n");
            return 0;
        }
    }

    // Calcular a base10
    for(int i=0; i <= tamanho; i++){
        if( n_base2[i] == 1 ){
            n_base10 += pow(2,(-1*(i-(tamanho-1))));
        }
    }

    return (int ) n_base10;
}


int base8_base10(int n_base8[], int tamanho){
    
      int n_base10 = 0;
      
      // Verificar se o numero está na base 8
      for(int i=0; i < tamanho; i++){
            if( n_base8[i] < 0 || n_base8[i] > 7 ){
                printf("Erro: numero não pertence a base 8\n");
                return 0;
            }
      }

      for(int i = 0; i < tamanho; i++){
          n_base10 += n_base8[i] * pow(8, (-1*(i-(tamanho-1))));
      }

      return n_base10;
}

int base16_base10(char n_base16[], int tamanho){
    
      int n_base10 = 0;

      for(int i = 0; i < tamanho; i++){
          n_base10 += n_base16[i] * pow(16,i );
      }

      return n_base10;

}

int *base16_base2( char n_base16[], int tamanho_hexa, int *tamanho_binario){

    int *binario = (int *) calloc(64, sizeof(int));
    int n_base10;
    *tamanho_binario=0;
    int j;

    for(int i=0; i < tamanho_hexa; i++){

        n_base10 = n_base16[i];

        if( n_base16[i] == 0 ){
            j=0;
            while( j != 4 ){
                binario[*tamanho_binario] = 0;
                *tamanho_binario += 1;
    
                j++;
            }
        }
        else{

            while( n_base10 != 0 ){
                binario[*tamanho_binario] = n_base10 % 2;
                *tamanho_binario = *tamanho_binario +1;

                n_base10 = n_base10 / 2;
            }
        }
        
    }

    return binario;
        
}

// Funções auxiliares
void ler_binario(int binario[64], int *tamanho, int numero){

    *tamanho = 0; 
    int aux[64]={0};
    int j=0;

    while( numero > 0){
      binario[*tamanho] = numero%10;   
      *tamanho = *tamanho + 1;

      numero /= 10;
    } 

    // Validação do número
    for(int i=0; i < *tamanho; i++)
        if( binario[i] != 1 && binario[i] != 0 ){
            printf("Erro: Numero não pertence a base 2.\n");

            // Apaga o vetor e o tamanho
            for(int j=0; j < *tamanho; j++)
                binario[j] = 0;

            *tamanho = 0;
            exit(1);
        } 

    // Inverter vetor
    for(int i=0; i < *tamanho; i++){
        j=-1 * (i-(*tamanho-1));
        aux[j] = binario[i];
    }

    for(int i=0; i < *tamanho; i++){
        binario[i] = aux[i];
    }
    
    // Debug: mostrar binario final
    printf("Debug Binario: ");
    for(int i=0; i < *tamanho; i++){
        printf("%d", binario[i]);
    }
    printf("\n");
}

void ler_octal( int octal[21], int *tamanho, int numero){

    *tamanho=0;
    int aux[21]={0};
    int j=0;

    while( numero > 0){
      octal[*tamanho] = numero%10;   
      *tamanho = *tamanho + 1;

      numero /= 10;
    } 

    //Validação
    for( int i=0; i < *tamanho; i++){
        if( octal[i] < 0 || octal[i] > 7){
            printf("Erro: Numero não pertence a base 8.\n");

            // Apaga o vetor e o tamanho
            for(int j=0; j < *tamanho; j++)
                octal[j] = 0;

            *tamanho = 0;
            exit(1);
        }
    }

    // Inverter vetor
    for(int i=0; i < *tamanho; i++){
        j=-1 * (i-(*tamanho-1));
        aux[j] = octal[i];
    }

    for(int i=0; i < *tamanho; i++){
        octal[i] = aux[i];
    }
    
    // Debug: mostrar Octal final
    printf("Debug Octal: ");
    for(int i=0; i < *tamanho; i++){
        printf("%d", octal[i]);
    }
    printf("\n");
}

void ler_hexa( char hexa[16], int *tamanho){

    *tamanho = 0;

    // Converter as letras em numeros
    for( int i=0; i < 16; i++){
        if( hexa[i] == 'A' || hexa[i] == 'a' ){ 
            hexa[i] = 10;
            *tamanho += 1;
        }
        else if( hexa[i] == 'B' || hexa[i] == 'b' ){ 
            hexa[i] = 11;
            *tamanho += 1;
        }
        else if( hexa[i] == 'C' || hexa[i] == 'c' ){
            hexa[i] = 12;
            *tamanho += 1;
        }
        else if( hexa[i] == 'D' || hexa[i] == 'd' ){ 
            hexa[i] = 13;
            *tamanho += 1;
        }
        else if( hexa[i] == 'E' || hexa[i] == 'e' ){ 
            hexa[i] = 14;
            *tamanho += 1;
        }
        else if( hexa[i] == 'F' || hexa[i] == 'f' ){
            hexa[i] = 15;
            *tamanho += 1;
        }
        else if( hexa[i] > 47 && hexa[i] < 58){
            hexa[i] = hexa[i] - 48;
            *tamanho += 1;
        }
        
    }

    //Validação
    for( int i=0; i < *tamanho; i++){
        if( hexa[i] < 0 ){
            printf("Erro: Numero não pertence a base 16.\n");

            // Apaga o vetor e o tamanho
            for(int j=0; j < *tamanho; j++)
                hexa[j] = 0;

            tamanho = 0;
            exit(1);
        }
    }


    /*
    printf("Debug Hexa: ");
    for(int i=0; i < *tamanho-1; i++)
        printf("%d", hexa[i]);
    printf("\n");
    */

}

