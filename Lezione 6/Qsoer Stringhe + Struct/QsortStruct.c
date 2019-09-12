#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  char parola[100];
  int y;
} elenco;

void print_output(elenco *array,int dim){
  int i;
  for(i=0;i<dim;i++){
    printf("%s\n",array[i].parola);
  }

}
int compare(const void* a,const void* b){
elenco v1=*(elenco*)a;
elenco v2=*(elenco*)b;
if(v1.y==v2.y)
  return strcmp(v1.parola,v2.parola);
else return v1.y-v2.y;
}

void funct(elenco *a,int *dim){
  int i;
  scanf("%d",dim);
  a=(elenco*) malloc (*dim * sizeof(elenco));
  for(i=0;i<*dim;i++){
    scanf("%s",&(a[i].parola));
    a[i].y=strlen(a[i].parola);
  }
  qsort(a,*dim,sizeof(elenco),compare);
  print_output(a,*dim);
}


int main(){
  int i;
  elenco* array;
  int dim;
  funct(array,&dim);
}
