#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void insertionsort(char** v,int dim){
char *key;
int i,j,k;
for(i=1;i<dim;i++){
   key = v[i];
   j=i-1;
   while(j>=0 && strcmp(v[j],key)>0){
         v[j+1]=v[j];
         j--;
         }
         v[j+1]=key;
     }
}
int main(){
int n,i;
char **vett;
scanf("%d",&n);
vett = (char**) malloc(n*sizeof(char*));
for(i=0;i<n;i++){
  vett[i]=(char *)malloc(101*sizeof(char));
  scanf("%s",vett[i]);
  }
insertionsort(vett,n);
for(i=0;i<n;i++){
  printf("%s\n",vett[i]);
  }

return 0;
}
