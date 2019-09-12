#include <stdio.h>
int sommamax(int v[],int dim){
int i,max,somma;
i=0;max=0;somma=0;
for(i=0;i<dim;i++){
 if (somma>0) somma+=v[i];
  else somma=v[i];
 if (somma>max) max=somma;
 }
 return max;
}
int main(){
int i,j,z,count;
int dima,dimb;
count=0;

scanf("%d",&dima);
int a[dima];
for(i=0;i<dima;i++) scanf("%d",&a[i]);
printf("%d",sommamax(a,dima));

}
