#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>

using namespace std;

void troca(int v[], int a, int b) {
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

void merge(int v[], int s, int m, int e) {
    int tmp[(e - s) + 1];
    int i = s, j = m + 1, k = 0;
    while (i <= m && j <= e) {
        if (v[i] < v[j]) {
            tmp[k++] = v[i++];
        } else {
            tmp[k++] = v[j++];
        }
    }
    for (; i <= m; i++, k++) {
        tmp[k] = v[i];
    }
    for (; j <= e; j++, k++) {
        tmp[k] = v[j];
    }
    for (i = s, k = 0; i <= e; i++, k++) {
        v[i] = tmp[k];
    }
}

void mergeSort(int v[], int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        mergeSort(v, s, m);
        mergeSort(v, m + 1, e);
        merge(v, s, m, e); // Aqui é a lógica da conquista
    }
}

int particiona(int v[], int s, int e) {

    int pivot = v[s];
    int i = s;
    for (int j = s + 1; j <= e; j++) {
        if (v[j] <= pivot) {
            i++;
            troca(v, i, j);
        }
    }
    troca(v, s, i);
    return i;
}

int quickSort(int v[], int s, int e) {
    if (s < e) {
        int p = particiona(v, s, e);

        quickSort(v, s, p - 1);
        quickSort(v, p + 1, e);
    }
}

int buscaSequencial(int v[], int n, int x) {
    for (int i = 0; i < n; i++) { // O(n)
        if (v[i] == x) {
            printf("Encontrado na posicao: ");
            return i;
        }
    }
    printf("Nao encontrado");
    return -1;
}

int buscaBinaria(int v[], int n, int x) { // O(log n)
    int s = 0, e = n - 1;
    while (s <= e) {
        int m = (s + e) / 2;
        if (x == v[m]) {
            printf("Encontrado na posicao: ");
            return m;
        } else if (x > v[m]) {
            s = m + 1;
        } else if (x < v[m]) {
            e = m - 1;
        }
    }
    return -1;
}

void imprimirVetor(int v[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){
    int index;
    int numeroEscolha;
    int contaCaso = 0;
    int numVetor = 1000;
    int vetorNovo[numVetor];

    while(index != 5){

        printf("Selecione no menu: \n");
        printf("1 - Gerar Vetor\n");
        printf("2 - Ordenar Vetor\n");
        printf("3 - Busca Sequencial\n");
        printf("4 - Busca Binaria\n");
        printf("5 - Sair\n");

        scanf("%d", &index);

        switch(index){
            case 1:{ //cria vetor
                printf("Digite o numero de vetores: \n");
                scanf("%d", &numVetor);
                //int vetorNovo[numVetor];

                for(int i = 0; i<numVetor; i++){
                    vetorNovo[i] = rand() % 100;
                }

                imprimirVetor(vetorNovo, numVetor);
                contaCaso++;
                }
                break;

            case 2:{
                if(contaCaso == 0){
                    printf("Nao pode executar essa opcao \n");
                    break;
                }
                char Ordena;
                printf("Digite a forma como quer ordenar: \n");
                printf("Q - Quick Sort\n");
                printf("M - Merge Sort\n");
                scanf("%*c%c%*c", &Ordena);

                if(Ordena == 'm'){
                    printf("Escolheu Merge \n");
                    mergeSort(vetorNovo, 0, numVetor);
                    imprimirVetor(vetorNovo, numVetor);
                    contaCaso++;
                    break;
                }
                if(Ordena == 'q'){
                    printf("Escolheu Quick \n");
                    quickSort(vetorNovo, 0, numVetor);
                    imprimirVetor(vetorNovo, numVetor);
                    contaCaso++;
                    break;
                }
                }
            case 3:{
               if(contaCaso == 0){
                   printf("Nao pode executar essa opcao \n");
                   break;
               }
               printf("Qual numero voce procura? \n");
               scanf("%d", &numeroEscolha);
               printf("%d\n", buscaSequencial(vetorNovo, numVetor, numeroEscolha));
               break;
            }
            case 4:{
                if(contaCaso < 2){
                   printf("Nao pode executar essa opcao \n");
                   break;
               }
               printf("Qual numero voce procura? \n");
               scanf("%d", &numeroEscolha);
               printf("%d\n", buscaBinaria(vetorNovo, numVetor, numeroEscolha));
               break;
            }
            }
        }

        return 0;
    }
