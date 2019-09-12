#include <stdio.h>
#include <stdlib.h>
void insertionsort(int *v,int dim){

}
int main(){
int n,i;
char vett**;
scanf("%d",&n);
char** vett = (char**) malloc (n*sizeof(char *));
for(i=0;i<n;i++){
  vett[i]= (char *) malloc (101*sizeof(char));
  scanf("%c",vett[i]);
  }
insertionsort(vett,n);
for(i=0;i<n;i++){
  printf("%c\n",vett[i]);
  }
return 0;
}
