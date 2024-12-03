/* 10 - Faça um programa que leia um numero inteiro positivo de
três dígitos (de 100 a 999). Gere outro numero formado pelos
dígitos invertidos do numero lido. Exemplo: número lido: 123 
e o resultado invertido deve ser 321.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Função para inversão do número
int inverterNumero(int numero);

//Função para testar se o número está
//compreendido entre 100 e 999
int testaNumero(int numero);

//Função para impressão do 
//cabeçalho
void imprime_cabec(void);


int main(){

    imprime_cabec();
    setlocale(LC_ALL,"");

    int numero=0, counter=1,fim=1;
    //Vetor para armazenar os números digitados
    int vet_num[100];
    //Vetor para armazenar os números convertidos
    int vet_inv[100];
    
    //Laço while para digitar diversos numero de 3 digitos
    //A saida do laço está condicionada ao usuario digitar 0
    while("true"){
        printf("Digite 0 para sair e imprimir os numeros!\n\n");
        printf("Entre com um numero de 3 digitos: \a");
        scanf("%d",&numero);

        //Este if testa se o usuario quer sair do programa
        if(numero == 0){break;}
        
        //Este if testa se o numero esta compreendido entre 100 e 999
        //Caso o numero digitado esteja fora do intervalo o laço while
        //que está dentro do if pedira o usuario para entrar com um numero
        //de tres digitos compreendido dentro do intervalo
        if(numero<100 || numero>999){        
           while(numero<100 || numero>999){            
               testaNumero(numero);
               printf("Digite novamente: ");
               scanf("%d", &numero);
               
               //Este if testa se o usuario quer sair do programa
               if(numero == 0){
                fim=0;
                break;
               }
           }
           if(fim==0){break;}
        }
        vet_num[counter]=numero;
        vet_inv[counter]=inverterNumero(numero);
        counter++;
        system("cls");
        imprime_cabec();
    }

    printf("Programa Encerrado!!\n\n");

    //Este if imprime a posição dentro do vetor "vet_num[]", os números digitados que
    //estão armazenado neste vetor assim os números invertidos que estao armazenados
    //no vetor vet_inv[].
    if(fim==0){
        printf("Nenhum numero de 3 digitos foi digitado!!\n");        
    }else{
        printf("%d numeros Digitados e Invertidos: \n",counter-1);    
        printf("Posicao    Numero Digitado      Numero Digitado Invertido \n");
        for(int j=1; j<counter; j++){
            printf("   %d\t\t  ",j);        
            printf("%d\t\t\t  ",vet_num[j]);
            printf("%d",vet_inv[j]);
            printf("\n");
        }
    }

    setlocale(LC_ALL,"");
    printf("\n\n");
    system("PAUSE");
    return 0;
}

int inverterNumero(int numero){

    int invertido = 0;
        
    while(numero != 0){
        invertido = invertido*10 + numero%10;
        numero /= 10;
    }
    return invertido;

}

int testaNumero(int numero){

    if(numero<100){
        return printf("Numero digitado menor que %d < 100 \n", numero);
    }else if(numero>999){
        return printf("Numero digitado maior que %d > 999 \n", numero);
    }
}

void imprime_cabec(void)
{
  printf("\n\n\n");
  printf("******************************************************\n");
  printf("***********ALGORITMO DE INVERSAO DE NUMERO************\n");
  printf("******************************************************\n\n");
  
  return;
}

