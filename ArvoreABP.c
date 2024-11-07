#include <stdio.h>
#include <stdlib.h>
#include "ArvoreABP.h"

typedef struct no{
    int info;
    struct no *esq;
    struct no *dir;
}Arvore;

typedef struct pilha{
    Arvore* no;
    struct pilha* prox;
} Pilha;

typedef struct fila {
    Arvore* no;
    struct fila* prox;
} Fila;

void entraFila(Fila** frente, Fila** tras, Arvore* no){
    Fila* novo = (Fila*)malloc(sizeof(Fila));
    novo->no = no;
    novo->prox = NULL;
    if (*tras == NULL){
        *frente = *tras = novo;
    } else {
        (*tras)->prox = novo;
        *tras = novo;
    }
}

Arvore* saiFila(Fila** frente){
    if (*frente == NULL) return NULL;
    Fila* temp = *frente;
    Arvore* no = temp->no;
    *frente = (*frente)->prox;
    free(temp);
    return no;
}

void empilha(Pilha** topo, Arvore* no){
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    novo->no = no;
    novo->prox = *topo;
    *topo = novo;
}

Arvore* desempilha(Pilha** topo){
    if (*topo == NULL) return NULL;
    Pilha* temp = *topo;
    Arvore* no = temp->no;
    *topo = temp->prox;
    free(temp);
    return no;
}

Arvore* criaArv(){
    Arvore* arve;
    arve = (Arvore*)malloc(sizeof(Arvore));
    if (arve == NULL){
        printf("\nAlocacao mal sucedida!!\n");
        return;
    }
    printf("\nInsira um numero: ");
    scanf("%d", &arve->info);
    arve->dir = NULL;
    arve->esq = NULL;
    return arve;
}

void insereArv(Arvore** raiz){
    Arvore* no = criaArv();
    if (no == NULL) return;

    if (*raiz == NULL){
        *raiz = no;
        printf("\nElemento inserido com sucesso!\n");
        return;
    }

    Arvore* atual = *raiz;
    Arvore* pai = NULL;
    while (atual != NULL){
        pai = atual;
        if (no->info < atual->info)
            atual = atual->esq;
        else
            atual = atual->dir;
    }

    if (no->info < pai->info)
        pai->esq = no;
    else
        pai->dir = no;

    printf("\nElemento inserido com sucesso!\n");
}

Arvore* removeNo(Arvore* raiz, int valor){
    if (raiz == NULL) {
        printf("A árvore está vazia!\n");
        return;
    }
    Arvore* atual = raiz;
    Arvore* pai = NULL; // funciona como um no anterior

    while (atual != NULL && atual->info != valor){
        pai = atual;
        if (valor < atual->info){
            atual = atual->esq;
        }
        else{
            atual = atual->dir;
        }
    }
    if (atual == NULL){
        printf("\nElemento não encontrado!\n");
        return raiz;
    }
    //else o elemento foi encontrado
    // sem filhos
    if (atual->esq == NULL && atual->dir == NULL) {
        if (pai == NULL) {
            free(atual);  // era a raiz e unico elemento
            return NULL;
        }
        if (pai->esq == atual){
            pai->esq = NULL;
        } else {
            pai->dir = NULL;
        }
        free(atual);// removido
    }
    // um filho à direita
    else if (atual->esq == NULL) {
        if (pai == NULL) {
            Arvore* temp = atual->dir;
            free(atual);
            return temp;
        }
        if (pai->esq == atual){
            pai->esq = atual->dir;
        }
        else {
            pai->dir = atual->dir;
        }
        free(atual); //removendo
    }
    // um filho à esquerda
    else if (atual->dir == NULL) {
        if (pai == NULL) {
            Arvore* temp = atual->esq;
            free(atual);
            return temp;
        }
        if (pai->esq == atual) {
            pai->esq = atual->esq;
        } else {
            pai->dir = atual->esq;
        }
        free(atual); // removendo
    }
    // dois filhos
    else {
        Arvore* aux = atual->dir;
        Arvore* paiAux = atual;

        // menor valor
        while (aux->esq != NULL) {
            paiAux = aux;
            aux = aux->esq;
        }
        atual->info = aux->info;

        if (paiAux->esq == aux)
            paiAux->esq = aux->dir;
        else
            paiAux->dir = aux->dir;
        free(aux);
    }
    return raiz;
}

void listaArvore(Arvore* raiz){
    if (raiz == NULL) {
        printf("A Arvore nao foi plantada!\n");
        return;
    }
    Pilha* pilha = NULL;
    Arvore* atual = raiz;

    printf("\n");
    while (atual != NULL || pilha != NULL){
        while (atual != NULL) {
            empilha(&pilha, atual);
            atual = atual->esq;
        }
        atual = desempilha(&pilha);
        printf(" %d", atual->info);
        atual = atual->dir;
        if(atual != NULL || pilha != NULL)
            printf(",");
    }
    printf("\n");
}

void BuscaArvore(Arvore* raiz){
    if (raiz == NULL) {
        printf("A Arvore nao foi plantada!\n");
        return;
    }
    Pilha* pilha = NULL;
    Arvore* atual = raiz;
    int elem, cont=0;

    printf("\n");
    printf("\nInsira o elemento que deseja encontrar:");
    scanf("%d", &elem);

    while (atual != NULL || pilha != NULL){
        while (atual != NULL) {
            empilha(&pilha, atual);
            cont++;
            if (atual->info == elem){
                printf("\nElemento %d encontrado apos percorrer %d nos", elem, cont-1);
                printf("\n");
                return;
            }
            if (elem < atual->info)
                atual = atual->esq;
            else
                atual = atual->dir;
        }
        atual = desempilha(&pilha);
    }
    printf("\nElemento NAO encontrado :(\n");
    return;
}

void ContaArvore(Arvore* raiz){
    if (raiz == NULL) {
        printf("A Arvore nao foi plantada!\n");
        return;
    }
    Pilha* pilha = NULL;
    Arvore* atual = raiz;
    int cont = 0;

    while (atual != NULL || pilha != NULL){
        while (atual != NULL){
            empilha(&pilha, atual);
            atual = atual->esq;
        }
        atual = desempilha(&pilha);
        cont++;
        atual = atual->dir;
    }
    printf("\nA Arvore possui %d elementos\n", cont);
    printf("\n");
}

void FolhaArvore(Arvore* raiz){
    if (raiz == NULL) {
        printf("A Arvore nao foi plantada!\n");
        return;
    }
    Pilha* pilha = NULL;
    Arvore* atual = raiz;
    int cont = 0;

    while (atual != NULL || pilha != NULL) {
        while (atual != NULL){
            empilha(&pilha, atual);
            atual = atual->esq;
        }
        atual = desempilha(&pilha);
        if (atual->esq == NULL && atual->dir == NULL){
            cont++;
            printf("\nFolha %d: %d", cont, atual->info);
        }
        atual = atual->dir;
    }
   printf("\nA Arvore possui %d elementos que SAO FOLHAS\n", cont);
}

void NaoFolhaArvore(Arvore* raiz){
    if (raiz == NULL) {
        printf("A Arvore nao foi plantada!\n");
        return;
    }
    Pilha* pilha = NULL;
    Arvore* atual = raiz;
    int cont = 0;

    while (atual != NULL || pilha != NULL) {
        while (atual != NULL) {
            empilha(&pilha, atual);
            atual = atual->esq;
        }
        atual = desempilha(&pilha);
        if (atual->esq != NULL || atual->dir != NULL){
            cont++;
            printf("\nNo nao folha: %d", atual->info);
        }
        atual = atual->dir;
    }

    printf("\nA Arvore possui %d elementos que NAO sao FOLHAS\n", cont); // Exibe o total de nós não folhas
}

void AlturaArvore(Arvore* raiz){
    if (raiz == NULL) {
        printf("A Arvore nao foi plantada!\n");
        return;
    }

    Fila* frente = NULL;
    Fila* tras = NULL;
    entraFila(&frente, &tras, raiz);
    int altura = 0;

    while(frente != NULL){
        int tamanhoNivel = 0;
        Fila* temp = frente;
        while (temp != NULL) {
            tamanhoNivel++;
            temp = temp->prox;
        }
        for (int i = 0; i < tamanhoNivel; i++){ //percorre o nivel
            Arvore* no = saiFila(&frente);
            if (no->esq != NULL) {
                entraFila(&frente, &tras, no->esq);
            }
            if (no->dir != NULL) {
                entraFila(&frente, &tras, no->dir);
            }
        }
        altura++;
    }
    printf("Altura da Arvore: %d\n", altura);
}

void MaiorArvore(Arvore* raiz){
    if (raiz == NULL) {
        printf("A Arvore nao foi plantada!\n");
        return;
    }
    Arvore* atual = raiz;
    while (atual->dir != NULL) {
        atual = atual->dir;
    }
    printf("Maior numero da Arvore: %d\n", atual->info);
}

void EspelhaArvore(Arvore* raiz){
    if (raiz == NULL) return;

    Pilha* pilha = NULL;
    empilha(&pilha, raiz);

    while (pilha != NULL){
        Arvore* atual = desempilha(&pilha);
        Arvore* temp = atual->esq;
        atual->esq = atual->dir;
        atual->dir = temp;
        if (atual->esq != NULL){
            empilha(&pilha, atual->esq);
        }
        if (atual->dir != NULL){
            empilha(&pilha, atual->dir);
        }
    }
}

void liberaArvore(Arvore* raiz){
    if (raiz == NULL) {
        return;
    }
    liberaArvore(raiz->esq);
    liberaArvore(raiz->dir);
    free(raiz);
}
