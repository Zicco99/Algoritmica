#include <stdio.h>
#include <stdlib.h>
void selectionsort(int *v,int dim){
int i,j,smallest,trade;
for(i=0;i<dim-1;i++){
smallest=i;
for(j=i+1;j<dim;j++){
 if(v[j]<v[smallest]) smallest=j;
}
 trade=v[i];
 v[i]=v[smallest];
 v[smallest]=trade;
}
}
int main(){
int n,i,*vett;
scanf("%d",&n);
vett = (int*) malloc (n*sizeof(int));
for(i=0;i<n;i++){
  scanf("%d",vett+i);
  }
selectionsort(vett,n);
for(i=0;i<n;i++){
  printf("%d\n",*(vett+i));
  }
return 0;
}
