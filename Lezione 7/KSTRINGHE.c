#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  char parola[100];
  int count;
} elenco;

int ricerca(elenco* v,char* key,int dim){
int i;
for(i=0;i<dim;i++){
   if(strcmp(v[i].parola,key)==0) return i;
 }
 return -1;
}

void print_output(elenco* array,int k){
  int i;
  for(i=0;i<k;i++){
    printf("%s\n",array[i].parola);
  }
}


int compare(const void* a,const void* b){
  elenco v1=*(elenco *)a;
  elenco v2=*(elenco *)b;
  return v2.count-v1.count;
}
int compare2(const void* a,const void* b){
  elenco v1=*(elenco *)a;
  elenco v2=*(elenco *)b;
  return strcmp(v1.parola,v2.parola);
}

void funct(elenco *a,int *dim,int *k){
  int i,j,res;
  j=0; //POS ULTIMA STRINGA//
  char temp[100];
  scanf("%d",dim);
  scanf("%d",k);
  a=(elenco*) malloc (*dim * sizeof(elenco));
  for(i=0;i<*dim;i++){
        scanf("%s",temp);
        res=ricerca(a,temp,*dim);
        if(res==-1) {
           strcpy(a[j].parola,temp); //NON c'è AGGIUNGO //
           a[j].count=1;
           j++;
         }
        else  a[res].count++; // SE C'è GIA' INCREMENTA //
       }
  qsort(a,j,sizeof(elenco),compare);
  qsort(a,*k,sizeof(elenco),compare2);
  print_output(a,*k);
}


int main(){
  int i,k,dim;
  elenco* array;
  funct(array,&dim,&k);
}
