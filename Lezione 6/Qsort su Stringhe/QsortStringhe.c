#include <stdio.h>
#include <stdlib.h>
char** read_input(int dim){
  int i;
  char** a;
  a = (char **) malloc(dim*sizeof(char**));
  for(i=0;i<dim;i++){
    a[i]=(char *) malloc(101*sizeof(char));
    scanf("%s",a[i]);
  }
  return a;
}



int compare (const void * a, const void * b) {
 char *x = *(char**)a;
 char *y = *(char**)b;
 return -strcmp(x,y);
}



int main(){
  int i;
  char** array;
  int dim;
     scanf("%d",&dim);
     array = read_input(dim);
     // CARICO SU ARRAY//
     qsort(array,dim,sizeof(char*),compare);
     //INIZIO STAMPA//
     for(i=0;i<dim;i++){
        printf("%s\n",array[i]);
       }
}
