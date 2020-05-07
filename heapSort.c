#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define filho_esq (raiz * 2) + 1
#define filho_dir (raiz * 2) + 2

void createMaxHeap(int *vet, int n, int raiz){
	int maior = raiz;
	
	if(filho_esq < n && vet[filho_esq] > vet[maior])
		maior = filho_esq;
		
	if(filho_dir < n && vet[filho_dir] > vet[maior])
		maior = filho_dir;
		
	if(maior != raiz){
		int aux = vet[maior];
		vet[maior] = vet[raiz];
		vet[raiz] = aux;
		
		createMaxHeap(vet, n, maior);
	}
}

void heapSort(int *vet, int n){
	for(int i = (n / 2) - 1; i >= 0; i--){
		createMaxHeap(vet, n, i);
	}
	
	for(int i = n-1; i > 0; i--){
		int aux = vet[0];
		vet[0] = vet[i];
		vet[i] = aux;
		
		createMaxHeap(vet, i, 0);
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
	heapSort(vet, 10000);
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
