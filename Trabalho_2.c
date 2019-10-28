// Informações do estudante
// Nome: Gabriel Rodrigues Malaquias
// Curso: Bacharelado em Ciência da Computação
// RA:  758906

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int qtd=0, qtdmutacao=0, aux=0, inicio=1, menor=0, posmenor=0;
    scanf("%d", &qtd);
    int genes[qtd];
    for(int i=0; i<qtd; i++){
        scanf("%d", &genes[i]);
    }
    for(int i=0; i<qtd; i++){
        int k=0;
        menor = genes[i];
        for(k=i+1; k<qtd; k++){
            if(genes[k]<menor){
                menor = genes[k];
                posmenor = k;
            }
        }
        while(posmenor>i){
            aux = genes[posmenor];
            genes[posmenor] = genes[posmenor-1];
            genes[posmenor-1] = aux;
            qtdmutacao++;
            posmenor--;
        }
    }
    printf("%d\n", qtdmutacao);
    for(int i=0; i<qtd; i++){
        printf("%d  ", genes[i]);
    }
    return 0;
}
