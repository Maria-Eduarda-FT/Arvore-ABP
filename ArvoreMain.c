#include <stdio.h>
#include <stdlib.h>
#include "ArvoreABP.h"

int main(){
    int resp, elem;
    Arvore* arv = NULL;

    do{
    printf("         /\\\n");
    printf("        /  \\\n");
    printf("       /    \\\n");
    printf("      /      \\\n");
    printf("     ||Arvore||\n");
    printf("     || ABP  ||\n");
    printf("      ||    ||\n");
    printf("        |  |\n");
    printf("        |__|\n");
        printf("\n1-Inserir");
        printf("\n2-Remover");
        printf("\n3-Listar");
        printf("\n4-Buscar");
        printf("\n5-Contar quantidade de elementos");
        printf("\n6-Contar quantidade de elementos NAO folha");
        printf("\n7-Contar quantidade de elementos folha");
        printf("\n8-Calcular Altura da Arvore");
        printf("\n9-Achar o Maior numero");
        printf("\n10-Espelhar a arvore");
        printf("\n11-Sair\n");
        scanf("%d", &resp);

        switch(resp){
            case 1:
                insereArv(&arv);
                break;
            case 2:
                printf("\nDigite o numero a ser removido: ");
                scanf("%d", &elem);
                arv = removeNo(arv, elem);
                break;
            case 3:
                listaArvore(arv);
                break;
            case 4:
                BuscaArvore(arv);
                break;
            case 5:
                ContaArvore(arv);
                break;
            case 6:
                NaoFolhaArvore(arv);
                break;
            case 7:
                FolhaArvore(arv);
                break;
            case 8:
                AlturaArvore(arv);
                break;
            case 9:
                MaiorArvore(arv);
                break;
            case 10:
                EspelhaArvore(arv);
                break;
            case 11:
                liberaArvore(arv);
                printf("\nAte mais!! :D\n");
                break;
        }
    }while(resp != 11);
    return 0;
}