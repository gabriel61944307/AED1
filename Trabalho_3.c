// Informações do estudante
// Nome: Gabriel Rodrigues Malaquias
// Curso: Bacharelado em Ciência da Computação
// RA:  758906

#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa Pessoa ;
struct pessoa {
int posicao ;
Pessoa *prox ;
};

Pessoa *inicio = NULL;
Pessoa *fim = NULL;
//inicio = NULL ;

void insereLista (int x){
	Pessoa *novo = malloc(sizeof(Pessoa));
	novo->posicao = x;
	if(inicio != NULL){
        fim->prox = novo;
        novo->prox = inicio;
	}
	else{
		novo->prox= novo;
		inicio = novo;
    }
    fim = novo;
}
void removeLista ( Pessoa *p ){
	//p é a pessoa que vai matar
	Pessoa *morta;
	morta=p->prox;
	if(morta == inicio)
		inicio = morta->prox;
	p->prox=morta->prox;
	free(morta);
}
void imprimeLista (){
	Pessoa *p = inicio->prox;
	printf("%d\n", inicio->posicao);
	while(p != inicio){
		printf("%d\n", p->posicao);
		p = p->prox;
	}
}
void resolveJosephus ( int n , int m ){
	for(int i=1; i<=n; i++){
		insereLista(i);
	}
    Pessoa *p = inicio;

	while(p->prox!=p){
		if(m!=1){
            Pessoa *matador = p;
			for (int i = 1; i < m; i++){
				p=p->prox;
			}
			if(p->prox == matador)
                p=p->prox;
		}
		removeLista(p);
		p=p->prox;
	}
}

int main () {
	int nroexecs;

	scanf ("%d", &nroexecs );
	int *n = malloc (nroexecs *sizeof(int));
	int *p = malloc (nroexecs *sizeof(int));

	for (int i = 0; i < nroexecs ; i ++){
		scanf("%d", &n[i]);
		scanf("%d", &p[i]);
	}

	for (int i = 0; i < nroexecs ; i ++) {
		printf("Usando n=%d, m=%d, resultado=", n[i] , p[i]);
		resolveJosephus(n[i], p[i]);
		imprimeLista();
		inicio = NULL;
	}

	return 0;
}
