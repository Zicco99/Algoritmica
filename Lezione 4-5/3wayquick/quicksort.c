#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int min(int a, int b){
 if(a > b) 
    return b;
  return a;
}
 
void swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
 
void quicksort(int a[], int low, int high){
    int pivot = a[high];
     
    int lt = low;
    int reader = low ;
    int gt = high;
     
    while(reader < gt){
        if(a[reader] < pivot){
            swap(a, reader, lt);
            reader++;
            lt++;
        }
        else if(a[reader] == pivot){
            gt--;
            swap(a, reader, gt);
        }
        else{
            reader++;
        }
    }
   
    int minimum = min( gt-lt, high-gt+1);
    for(int i=0; i<minimum; i++){
        swap(a, lt+i, high-minimum+1+i); 
    }
 
    if( low < high){
        quicksort(a, low, lt-1);
        quicksort(a, high-gt+lt, high);
    }
    return ;
}

/* Lettura di un array di interi da input. 
Il primo elemento è la lunghezza dell'array */
int legge(int **a, int *len) {

  int i;
  scanf("%d", len);
  if(*len <= 0) return 1;

  *a = (int *) malloc(*len * sizeof(int));
  if(*a == NULL) return 1;

  for( i = 0; i < *len; i++ ) 
	  scanf("%d", (*a)+i);
  
  return 0;

}

int main() {
  
  int i, n, *A;

  if( legge(&A, &n)) return 1;

  srand(time(NULL));
  quicksort(A, 0, n-1);
  
  /* Stampa l'array ordinato */
  for( i = 0; i < n; i++ ) 
    printf("%d ", A[i]);
	
  return 0;
}
