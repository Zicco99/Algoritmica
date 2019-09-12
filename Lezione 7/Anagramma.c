#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
char parola[200];
char anpr[200];
}stringa;

char* princ(char* par,int n){
  int i,j;
  char temp;
  for (i = 0; i < n-1; i++) {
     for (j = i+1; j < n; j++) {
        if (strcmp(&par[i],&par[j])>0) {
           temp = par[i];
           par[i] = par[j];
           par[j] = temp;
        }
     }
  }
  return par;
}

int compare(const void* a,const void* b){
  stringa v1=*(stringa*)a;
  stringa v2=*(stringa*)b;
  if(strcmp(v2.anpr,v1.anpr)==0){
    return -strcmp(v2.parola,v1.parola);
  }
   return -strcmp(v2.anpr,v1.anpr);
}


int main(){
int i,dim;
stringa* vett;
char par[200];
scanf("%d",&dim);
vett=(stringa*)malloc(dim*sizeof(stringa));

for(i=0;i<dim;i++){
    scanf("%s",&vett[i].parola);
    strcpy(par,vett[i].parola);
    strcpy(vett[i].anpr,princ(par,strlen(par)));
}

qsort(vett,dim,sizeof(stringa),compare);
for(i=0;i<dim;i++){
  printf("%s ",vett[i].parola);
  if(*vett[i].anpr!=*vett[i+1].anpr){
    printf("\n");
  }
 }
}
