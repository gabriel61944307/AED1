// Informações do estudante
// Nome: Gabriel Rodrigues Malaquias
// Curso: Bacharelado em Ciência da Computação
// RA:  758906

#include <stdio.h>
#include <stdlib.h>

typedef struct  tabuleiro{
    int numLins;
    int **pos;
} *Tabuleiro;

int posValida(Tabuleiro tab, int lin, int col){
    int tamTab = tab->numLins;
    if((lin>=0 && lin<tamTab) && (col>=0 && col<tamTab)){
        int i=0, j=0;
        //Coluna
        for(i=0; i<tamTab; i++){
            if(tab->pos[i][col]==1){
                return 0;
            }
        }

        //Linha
        for(i=0; i<tamTab; i++){
            if(tab->pos[lin][i]==1){
                return 0;
            }
        }

        //Diagonal cima para baixo com rainha acima da diagonal ou nela
        int k=0;
        if(lin<=col){
            i = lin;
            j = col;
            while(k<tamTab){
                i=i%tamTab;
                j=j%tamTab;
                if(i<=j){
                    if(tab->pos[i][j]==1){
                        return 0;
                    }
                }
                i++;
                j++;
                k++;
            }
        }

        //Diagonal cima para baixo com rainha abaixo da diagonal
        else{
            i = lin;
            j = col;
            while(k<tamTab){
                i=i%tamTab;
                j=j%tamTab;
                if(i>j){
                    if(tab->pos[i][j]==1){
                        return 0;
                    }
                }
                i++;
                j++;
                k++;
            }
        }

        //Diagonal baixo para cima
        k=0;
        i=lin;
        j=col;
        int aux;
        while(k<tamTab){
            if(tab->pos[i][j]==1){
                return 0;
            }
            if(i==0 || j==tamTab-1){
                aux = i;
                i = j;
                j = aux;
                k++;
                if(i==j){
                    return 1;
                }
                if(tab->pos[i][j]==1){
                    return 0;
                }
            }
            i=(i-1)%tamTab;
            j = (j+1)%tamTab;
            k++;
        }
        return 1;
    }
    return 0;
}

int resolveRainha(Tabuleiro tab, int lin, int col, int n, int * a){
    if(posValida(tab, lin, col)){
        tab->pos[lin][col] = 1;
        if(n==tab->numLins-1){
            tab->pos[lin][col] = 0;
            *a = *a +1;
            return 1;
        }
        for(int i=0; i<tab->numLins; i++){
            resolveRainha(tab, lin+1, i, n+1, a);
        }
        tab->pos[lin][col] = 0;
    }
    return 0;
}


int main(){
    int tamTab;
    scanf("%d", &tamTab);
    int *a = malloc(sizeof(int));
    *a=0;

    Tabuleiro tab = malloc(sizeof(Tabuleiro));
    tab->numLins=tamTab;
    tab->pos = (int **) malloc(tamTab * sizeof(int *));
    for (int i=0; i<tamTab; i++){
    	tab->pos[i] = (int *) malloc(tamTab * sizeof(int));
	}

    for(int k=0; k<tamTab; k++){
        for(int l=0; l<tamTab; l++){
            tab->pos[k][l] = 0;
        }
    }

    for(int i=0; i<tamTab; i++){
        resolveRainha(tab, 0, i, 0, a);
    }

    printf("%d", *a);
    return 0;
}
