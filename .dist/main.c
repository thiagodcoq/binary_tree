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

int main(void)
{
    NoArv *raiz = NULL;

    raiz = inserir_versao_1(raiz, 50);

    return 0;
}