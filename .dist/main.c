#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *direita;
    struct no *esquerda;

} NoArv;

NoArv *inserir_versao_1(NoArv *raiz, int num)
{
    if (raiz == NULL)
    {
        NoArv *aux = (NoArv *)malloc(sizeof(NoArv));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else
    {
        if (num < raiz->valor)
        {
            raiz->esquerda = inserir_versao_1(raiz->esquerda, num);
        }
        else
        {
            raiz->direita = inserir_versao_1(raiz->direita, num);
        }
        return raiz;
    }
}

void imprimir_versao_1(NoArv*raiz){
    if(raiz){
        printf("%d ",raiz->valor);
        imprimir_versao_1(raiz->esquerda);
        imprimir_versao_1(raiz->direita);
    }
}

/*Ordenada*/
void imprimir_versao_2(NoArv*raiz){
    if(raiz){
        imprimir_versao_2(raiz->esquerda);
        printf("%d ",raiz->valor);
        imprimir_versao_2(raiz->direita);
    }
}

int main(void)
{
    NoArv *raiz = NULL;
    int opcao,valor;
    do {
        printf("\nt0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Digite um valor: "); // Corrigido o "print" (veja o próximo erro)
                scanf("%d", &valor);     // Adicionado para ler o valor
                raiz = inserir_versao_1(raiz, valor);
                break;
            case 2:
                printf("Primeira impressão:\n");
                imprimir_versao_1(raiz);
                printf("\n");
                printf("Segunda impressão:\n");
                imprimir_versao_2(raiz);
                printf("\n");
                break;
            default:
                if (opcao != 0) {
                    printf("Invalido\n"); // Adicionado "\n" para melhor formatação
                }
                break; // Boa prática: adicionar break no default
        }
    } while (opcao != 0);

    return 0;
}
