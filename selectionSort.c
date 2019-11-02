#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int *vet, int n){
	int i = 1, menor = 0, inicio = 0;
	while(inicio < n){
		menor = inicio;
		i = inicio + 1;
		while(i < n){
			if(vet[i] < vet[menor]){
				menor = i;
			}
			i++;
		}
		int aux = vet[inicio];
		vet[inicio] = vet[menor];
		vet[menor] = aux;
		inicio++;
	}
}

int main(){
	int vet[10000], i = 0, tempo_passado[2];
	for(i = 0; i < 10000; i++){
		vet[i] = rand() % 10000;
	}
	
	i = 0;
	printf("Vetor inicial:\n");
	while(i<10000){
		printf("%d ", vet[i]);
		i++;
	}
	
	tempo_passado[0] = clock();
	selectionSort(vet, 10000);
	tempo_passado[1] = clock();
	float tempo = (tempo_passado[1] - tempo_passado[0]) * 1000 / CLOCKS_PER_SEC;

	i = 0;
	printf("Vetor final:\n");
	while(i<10000){
		printf("%d ", vet[i]);
		i++;
	}
  
	printf("\nTempo gasto: %.3f ms.\n", tempo);
  
	return 0;
}
