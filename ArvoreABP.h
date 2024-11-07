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

void entraFila(Fila** frente, Fila** tras, Arvore* no);
Arvore* saiFila(Fila** frente);
void empilha(Pilha** topo, Arvore* no);
Arvore* desempilha(Pilha** topo);
Arvore* criaArv();
void insereArv(Arvore** raiz);
Arvore* removeNo(Arvore* raiz, int valor);
void listaArvore(Arvore* raiz);
void BuscaArvore(Arvore* raiz);
void ContaArvore(Arvore* raiz);
void FolhaArvore(Arvore* raiz);
void NaoFolhaArvore(Arvore* raiz);
void AlturaArvore(Arvore* raiz);
void MaiorArvore(Arvore* raiz);
void EspelhaArvore(Arvore* raiz);
void liberaArvore(Arvore* raiz);