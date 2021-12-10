#include <stdio.h>
#include <stdlib.h>

typedef struct no
    {char *nome;
    int num_vidas;
    struct no *prox;
    struct no *ant;}NO;

NO *inicio = NULL;
int tam =0;

void adicionar(char *nome, int num_vidas, int pos)
    {NO *novo = malloc (sizeof (NO));
    novo->nome = nome;
    novo->num_vidas = num_vidas;
    novo->prox = NULL;
    novo->ant = NULL;

    if(tam == 0 && pos == 0)//Constante
        {inicio = novo;
        tam++;}
    else if(pos == 0)//Constante
        {novo->prox = inicio;
        inicio->ant = novo;
        inicio = novo;
        tam++;}
    else if( pos > 0 && pos < tam){//Linear || Questão a)Inserção - Luis Antonio Viana Franklin - Matrícula 514146 
        NO * aux = inicio;
        for(int i = 0 ; i < pos; i++){
            aux = aux->prox;
        }
        novo->prox = aux;
        aux->ant->prox = novo;
        novo->ant = aux->ant;
        aux->ant = novo;
        tam++;
    }

    else{printf("insercao invalida! :/\n");}
} 


void imprimir(){ //Questão c)Imprimir - Luis Antonio Viana Franklin - Matrícula 514146 
    NO * aux = inicio;
    for (int i = 0; i < tam; i++){
        printf("Personagem: %s\nVida dele: %d\n", aux->nome, aux->num_vidas);
        aux = aux->prox;}}


void remover(char *nome){
    if(tam == 1 && inicio->nome == nome){//Constante
        NO *lixo = inicio;
        inicio = NULL;
        free(lixo);
        tam --;
    }else if(tam > 1 && inicio->nome == nome){//Constante
        NO *lixo = inicio;
        inicio = inicio->prox;
        inicio->ant = NULL;
        free(lixo);
        tam--;
    }else{//Linear || Questão a)Remoção - Luis Antonio Viana Franklin - Matrícula 514146 
        NO * aux = inicio;
        NO * lixo;
        for(int i = 0; aux->nome != nome && i<tam;i++){
            aux = aux->prox;
        }
        aux = aux->ant;
        lixo = aux->prox;
        aux->prox = aux->prox->prox;
        free(lixo);
        tam--;
    }
}


char* persMaisVidas(){ //Questão d)Mostra o personagem de maior vida - Luis Antonio Viana Franklin - Matrícula 514146
    NO * aux = inicio;
    NO * num_maior = aux;
    int maior = aux->num_vidas;
    for (int i = 0; i < tam; i++){
        if(aux->num_vidas > maior)
            {num_maior = aux;}
        aux = aux->prox;
    }
    return num_maior->nome;
}


int main(){
    adicionar("Mario", 2, 0);
    adicionar("Luigi", 9, 0);
    adicionar("Princesa", 7, 0);
    adicionar("Toad", 3, 0);
    imprimir();
    printf("Personagem com mais vidas: %s\n", persMaisVidas());
}
