#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//Constantes
#define TAMANHO 100 
#define M 50 // quantidade de tuplas (linhas)
#define N 2 // tamanho das tuplas (colunas)
#define TN 4 // tamanho dos neuronios (colunas), equivalente a 2^(tamanho da tupla)

//Definindo e Aleatorizando os endereços da tupla
int *enderecoTupla[TAMANHO];
int retina[TAMANHO];

void defineEnderecoTupla();
void embaralhar(int **vet, int vetSize);

//Definindo os discriminadores
int *discriminadorA;
int *discriminadorB;

void defineDiscriminador();

//Função principal de aprendizado
void treinamentoA(int entrada[]);
void treinamentoB(int entrada[]);
int NumeroExemplosA=0;
int NumeroExemplosB=0;

//Função de reconhecimento
void classificacao(int entrada[]);

//Conversão
int converteBinario(int bin);

int main()
{
    //Definindo Tupla e Discriminadores
    defineEnderecoTupla();
    defineDiscriminador();

    int e,e1,e2,e3,personalizado[TAMANHO];
    int F1[TAMANHO] = {
        1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,
        1,1,0,0,0,0,0,0,0,0,
        1,1,0,0,0,0,0,0,0,0,
        1,1,1,1,1,1,0,0,0,0,
        1,1,1,1,1,1,0,0,0,0,
        1,1,0,0,0,0,0,0,0,0,
        1,1,0,0,0,0,0,0,0,0,
        1,1,0,0,0,0,0,0,0,0,
        1,1,0,0,0,0,0,0,0,0};
    int F2[TAMANHO] = {
        1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,
        1,1,0,0,0,0,0,0,0,0,
        1,1,0,0,0,0,0,0,0,0,
        1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,
        1,1,0,0,0,0,0,0,0,0,
        1,1,0,0,0,0,0,0,0,0,
        1,1,0,0,0,0,0,0,0,0,
        1,1,0,0,0,0,0,0,0,0};
    int F3[TAMANHO] = {
        1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,
        1,1,1,0,0,0,0,0,0,0,
        1,1,1,0,0,0,0,0,0,0,
        1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,
        1,1,1,0,0,0,0,0,0,0,
        1,1,1,0,0,0,0,0,0,0,
        1,1,1,0,0,0,0,0,0,0,
        1,1,1,0,0,0,0,0,0,0};
    int J1[TAMANHO] = {
        0,0,0,0,0,0,0,0,1,1,
        0,0,0,0,0,0,0,0,1,1,
        0,0,0,0,0,0,0,0,1,1,
        0,0,0,0,0,0,0,0,1,1,
        0,0,0,0,0,0,0,0,1,1,
        0,0,0,0,0,0,0,0,1,1,
        1,1,0,0,0,0,0,0,1,1,
        1,1,0,0,0,0,0,0,1,1,
        1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1};
    int J2[TAMANHO] = {
        0,0,0,0,0,1,1,1,1,1,
        0,0,0,0,0,1,1,1,1,1,
        0,0,0,0,0,0,0,0,1,1,
        0,0,0,0,0,0,0,0,1,1,
        0,0,0,0,0,0,0,0,1,1,
        0,0,0,0,0,0,0,0,1,1,
        1,1,0,0,0,0,0,0,1,1,
        1,1,0,0,0,0,0,0,1,1,
        1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1};
    int J3[TAMANHO] = {
        0,0,0,0,1,1,1,1,1,1,
        0,0,0,0,1,1,1,1,1,1,
        0,0,0,0,0,0,0,0,1,1,
        0,0,0,0,0,0,0,0,1,1,
        0,0,0,0,0,0,0,0,1,1,
        0,0,0,0,0,0,0,0,1,1,
        1,1,1,0,0,0,0,0,1,1,
        1,1,1,0,0,0,0,0,1,1,
        1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1};

    while (e!=4)
    {
        printf("\n\nEscolha sua acao\n");
        printf("1.Treinar   2.Classificar   3.Mostrar Entradas   4.Sair\n");
        scanf("%i",&e);

        switch (e)
        {
        case 1:
            printf("\n\nEscolha o que quer treinar\n");
            printf("1.F   2.J\n");
            scanf("%i",&e1);
            if(e1==1){
                printf("\n\nEscolha o que quer treinar\n");
                printf("1.F1   2.F2   3.F3   4.Personalizado\n");
                scanf("%i",&e2);
                if(e2==1){
                    treinamentoA(F1);
                }
                if(e2==2){
                    treinamentoA(F2);
                }
                if(e2==3){
                    treinamentoA(F3);
                }
                if(e2==4){
                    printf("Insira os elementos separados por espaco\n");
                    printf("A B C D E F G H I J\n");
                    for (int i = 0; i < 100; i+=10)
                    {
                        scanf("%i %i %i %i %i %i %i %i %i %i",&personalizado[i],&personalizado[i+1],&personalizado[i+2],&personalizado[i+3],&personalizado[i+4],&   personalizado[i+5],&personalizado[i+6],&personalizado[i+7],&personalizado[i+8],&personalizado[i+9]);
                    }
                    treinamentoA(personalizado);
                }
            }
            if(e1==2){
                printf("\n\nEscolha o que quer treinar\n");
                printf("1.J1   2.J2   3.J3   4.Personalizado\n");
                scanf("%i",&e2);
                if(e2==1){
                    treinamentoB(J1);
                }
                if(e2==2){
                    treinamentoB(J2);
                }
                if(e2==3){
                    treinamentoB(J3);
                }
                if(e2==4){
                    printf("Insira os elementos separados por espaco\n");
                    printf("A B C D E F G H I J\n");
                    for (int i = 0; i < 100; i+=10)
                    {
                        scanf("%i %i %i %i %i %i %i %i %i %i",&personalizado[i],&personalizado[i+1],&personalizado[i+2],&personalizado[i+3],&personalizado[i+4],&   personalizado[i+5],&personalizado[i+6],&personalizado[i+7],&personalizado[i+8],&personalizado[i+9]);
                    }
                    treinamentoB(personalizado);
                }
            }
            if (e1==3)
            {
                printf("Insira os elementos separados por espaco\n");
                printf("A B C D E F G H I J\n");
                for (int i = 0; i < 100; i+=10)
                {
                    scanf("%i %i %i %i %i %i %i %i %i %i",&personalizado[i],&personalizado[i+1],&personalizado[i+2],&personalizado[i+3],&personalizado[i+4],&personalizado[i+5],&personalizado[i+6],&personalizado[i+7],&personalizado[i+8],&personalizado[i+9]);
                }
                treinamentoA(personalizado);
            }
            if (e1==4)
            {
                printf("Insira os elementos separados por espaco\n");
                printf("A B C D E F G H I J\n");
                for (int i = 0; i < 100; i+=10)
                {
                    scanf("%i %i %i %i %i %i %i %i %i %i",&personalizado[i],&personalizado[i+1],&personalizado[i+2],&personalizado[i+3],&personalizado[i+4],&personalizado[i+5],&personalizado[i+6],&personalizado[i+7],&personalizado[i+8],&personalizado[i+9]);
                }
                treinamentoB(personalizado);
            }
            
            break;
        case 2:
            printf("\n\nEscolha o que quer classificar\n");
            printf("1.F1   2.F2   3.F3   4.J1   5.J2   6.J3   7.Personalizado\n");
            scanf("%i",&e3);
                switch (e3)
                {
                case 1:
                    classificacao(F1);
                    break;
                case 2:
                    classificacao(F2);
                    break;
                case 3:
                    classificacao(F3);
                    break;
                case 4:
                    classificacao(J1);
                    break;
                case 5:
                    classificacao(J2);
                    break;
                case 6:
                    classificacao(J3);
                    break;
                case 7:
                    printf("Insira os elementos separados por espaco\n");
                    printf("A B C D E F G H I J\n");
                    for (int i = 0; i < 100; i+=10)
                    {
                        scanf("%i %i %i %i %i %i %i %i %i %i",&personalizado[i],&personalizado[i+1],&personalizado[i+2],&personalizado[i+3],&personalizado[i+4],&personalizado[i+5],&personalizado[i+6],&personalizado[i+7],&personalizado[i+8],&personalizado[i+9]);
                    }
                    classificacao(personalizado);
                    break;
                default:
                    printf("Erro 97\n");
                    break;
                }
            break;
        case 3:
            printf("F1:\n");
            for (int i = 0; i < 10; i++)
            {
                for (int k = 0; k < 10; k++)
                {
                    printf("%i ",F1[k+i*10]);
                }
                printf("\n");
            }
            printf("F2:\n");
            for (int i = 0; i < 10; i++)
            {
                for (int k = 0; k < 10; k++)
                {
                    printf("%i ",F2[k+i*10]);
                }
                printf("\n");
            }
            printf("F3:\n");
            for (int i = 0; i < 10; i++)
            {
                for (int k = 0; k < 10; k++)
                {
                    printf("%i ",F3[k+i*10]);
                }
                printf("\n");
            }
            printf("J1:\n");
            for (int i = 0; i < 10; i++)
            {
                for (int k = 0; k < 10; k++)
                {
                    printf("%i ",J1[k+i*10]);
                }
                printf("\n");
            }
            printf("J2:\n");
            for (int i = 0; i < 10; i++)
            {
                for (int k = 0; k < 10; k++)
                {
                    printf("%i ",J2[k+i*10]);
                }
                printf("\n");
            }
            printf("J3:\n");
            for (int i = 0; i < 10; i++)
            {
                for (int k = 0; k < 10; k++)
                {
                    printf("%i ",J3[k+i*10]);
                }
                printf("\n");
            }
            break;

        case 4:
            break;
        
        default:
            printf("Erro 87\n");
            break;
        }
    }

    //Mostrar Discriminadores
    /*for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < TN; j++)
        {
            printf("%i\t",discriminadorA[j + i*TN]);
        }
        printf("\n");
    }
    printf("\n\n");
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < TN; j++)
        {
            printf("%i\t",discriminadorB[j + i*TN]);
        }
        printf("\n");
    }*/

    free(discriminadorA);
    free(discriminadorB);
    
    return 0;
}

void defineEnderecoTupla(){
    //colocando todos os endereços da retina no vetor endercoTupla sem aleatorizar
    for(int i=0;i<TAMANHO;i++){
       enderecoTupla[i] = &retina[i];
    }
    srand((unsigned)(time(NULL)));
    //Aleatorizando os endereços
    embaralhar(enderecoTupla,TAMANHO);
}

void embaralhar(int **vet, int vetSize)
{
	for (int i = 0; i < vetSize; i++)
	{
		int r = rand() % vetSize;

		int *temp = vet[i];
		vet[i] = vet[r];
		vet[r] = temp;
	}
}

void defineDiscriminador(){
    discriminadorA = (int *) calloc(M*TN, sizeof(int));
    discriminadorB = (int *) calloc(M*TN, sizeof(int));
}

void treinamentoA(int entrada[]){
    int a = 0,b = 0;
    for (int i = 0; i < TAMANHO; i++) // copia os valores da entrada para o vetor retina que esta linkado com o vetor enderecoTupla
    {
        retina[i] = entrada[i];
    }

    while (a != TAMANHO || b != M) //roda 1 vez para cada linha da tupla e, a cada vez, preenche uma linha do vetor discriminadorA, ou seja, 1 neuronio
    {
        int Tupla = *(enderecoTupla[a])*10 + *(enderecoTupla[a+1]);

        discriminadorA[converteBinario(Tupla) + b*TN]++;

        a+=N;
        b++;
    }
    printf("Treinado!\n");
    NumeroExemplosA++;
}

void treinamentoB(int entrada[]){
    int a = 0,b = 0;
    for (int i = 0; i < TAMANHO; i++) // copia os valores da entrada para o vetor retina que esta linkado com o vetor enderecoTupla
    {
        retina[i] = entrada[i];
    }

    while (a!=TAMANHO || b != M) //roda 1 vez para cada linha da tupla e, a cada vez, preenche uma linha do vetor discriminadorA, ou seja, 1 neuronio
    {
        int Tupla = *(enderecoTupla[a])*10 + *(enderecoTupla[a+1]);

        discriminadorB[converteBinario(Tupla) + b*TN]++;

        a+=N;
        b++;
    }
    printf("Treinado!\n");
    NumeroExemplosB++;
}

void classificacao(int entrada[]){
    int a = 0,b = 0,somadorA = 0, somadorB = 0,bleaching = 0,limiteBleaching;
    for (int i = 0; i < TAMANHO; i++) // copia os valores da entrada para o vetor retina que esta linkado com o vetor enderecoTupla
    {
        retina[i] = entrada[i];
    }

    (NumeroExemplosA)>(NumeroExemplosB)?(limiteBleaching=NumeroExemplosB):(limiteBleaching=NumeroExemplosA);

    //Comparando a entrada com o discriminadorA e discriminadorB
    while (somadorA==somadorB && bleaching<limiteBleaching)
    {
        somadorA = 0, somadorB = 0;
        while (a!=TAMANHO || b != M)
        {
            int Tupla = *(enderecoTupla[a])*10 + *(enderecoTupla[a+1]);
        
            if (discriminadorA[converteBinario(Tupla) + b*TN] > bleaching)
            {
                somadorA++;
            }
            if (discriminadorB[converteBinario(Tupla) + b*TN] > bleaching)
            {
                somadorB++;
            }

        a+=N;
        b++;
        }
        bleaching++;
    }

    //Comparando os resultados dos contadores
    if (somadorA>somadorB)
    {
        printf("O elemento e uma letra F\n");
    }
    if (somadorA<somadorB)
    {
        printf("O elemento e uma letra J\n");
    }
    if (somadorA==somadorB)
    {
        printf("A inteligencia esta indecisa\n");
    }
    
    printf("somadorA = %i\n",somadorA);
    printf("somadorB = %i\n",somadorB);
}

int converteBinario(int bin){
    int dec = 0;
    for(int i = 0; bin > 0; i++)
    {
        dec = dec + pow(2, i) * (bin % 10);
        bin = bin / 10;
    }
    return dec;
}