#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int *vet, int n){
	int i = 0;
	while(i < n-1){
		int j = i+1;
		while(j > 0 && vet[j] < vet[j-1]){
				int aux = vet[j];
				vet[j] = vet[j-1];
				vet[j-1] = aux;
				j--;
		}
		i++;
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
	insertionSort(vet, 10000);
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
