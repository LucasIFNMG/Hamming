#include <stdio.h>
#include <math.h>
#include <locale.h>


int main()
{
    setlocale(LC_ALL, "Portuguese");
    int numBitsOriginal; 

    printf("Informe a quant. de bits da mensagem original: \n");
    scanf(" %d", &numBitsOriginal);

    int numBitsParidade; 
    int numBitsTotal = 0;
    int k = 0;

    while (numBitsOriginal >= numBitsTotal)
    {
        if ((pow(2, k)) >= numBitsTotal)
            numBitsTotal = (pow(2, k)) - 1;

        numBitsParidade = k;
        k++;
    }

    numBitsTotal = numBitsOriginal + numBitsParidade; 

    printf("Nº Bits Msg Original: %d\nNº Bits Paridade: %d\nNº Bits Total: %d\n", numBitsOriginal, numBitsParidade, numBitsTotal);

    int vetorPosicaoBitsOriginal[numBitsTotal];
    int vetorPosicaoBitsVerificacao[numBitsParidade];

    int contVetorPosicaoBitsOriginal = 0;

    vetorPosicaoBitsVerificacao[0] = 1;

    int contVetorPosicaoBitsVerificacao = 1;

    int cont = 1;

    while (contVetorPosicaoBitsOriginal < numBitsOriginal)
    {

        for (int i = cont; i >= 2; i /= 2)
        {
            if (i == 2)
            {
                vetorPosicaoBitsVerificacao[contVetorPosicaoBitsVerificacao] = cont;
                contVetorPosicaoBitsVerificacao++;
                break;
            }

            if (i % 2 != 0)
            {
                vetorPosicaoBitsOriginal[contVetorPosicaoBitsOriginal] = cont;
                contVetorPosicaoBitsOriginal++;
                break;
            }
        }

        cont++;
    }

    printf("Posições dos Bits de Verificação:\n");
    for (int i = 0; i < contVetorPosicaoBitsVerificacao; i++)
        printf("%d ", vetorPosicaoBitsVerificacao[i]);

    printf("\nPosições dos Bits da Mensagem Original:\n");
    for (int i = 0; i < contVetorPosicaoBitsOriginal; i++)
        printf("%d ", vetorPosicaoBitsOriginal[i]);

    int mensagemOriginal[numBitsOriginal];
    int vetorHamming[numBitsTotal];

    printf("\nInforme os %d bits da mensagem original:\n",contVetorPosicaoBitsOriginal);
    for(int i = 0; i < contVetorPosicaoBitsOriginal; i++)
        scanf(" %d", &mensagemOriginal[i]);

    printf("Mensagem Original: ");
    for(int i = 0; i < numBitsOriginal; i++)
        printf("%d ",mensagemOriginal[i]);

    int contMensagemOriginal = 0;
    int contBitsVerificacao = 0;

//TODO: Cálculos dos bits de Hamming, utilizando a porta lógica XOR

    for(int i = 1; i <= numBitsTotal; i++)
    {
        if(vetorPosicaoBitsVerificacao[contBitsVerificacao] == i )
        {
            vetorHamming[i] = 0; //Calcular os bits de Hamming e substituir nessa atribuição
            contBitsVerificacao++;
        }

        else if(vetorPosicaoBitsOriginal[contMensagemOriginal] == i)
        {
            vetorHamming[i] = mensagemOriginal[contMensagemOriginal];
            contMensagemOriginal++;
        }

    }


    printf("\nVetor Hamming:\n");
    for (int i = 1; i <= numBitsTotal; i++)
        printf("%d ", vetorHamming[i]);

}
