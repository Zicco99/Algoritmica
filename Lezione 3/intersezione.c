#include <stdio.h>

void insertion(int a[],int dim){
int i,j,key;
 for(i=1;i<dim;i++){
 key=a[i];
 j=i-1;
 while(j>=0 && a[j]>key) {
 a[j+1]=a[j];
 j=j-1;
 }
 a[j+1]=key;
 }
}
int main(){
int i,j,count;
int dima,dimb;
count=0;
j=0;

scanf("%d",&dima);
int a[dima];
for(i=0;i<dima;i++) scanf("%d",&a[i]);

scanf("%d",&dimb);
int b[dimb];
for(i=0;i<dimb;i++) scanf("%d",&a[i]);

insertion(a,dima);
insertion(b,dimb);

for(i=0;i<dimb;i++) printf("%d",&a[i]);
for(i=0;i<dimb;i++) printf("%d",&a[i]);

while(i<dima && j<dimb){
if(a[i]==b[i]){
   count++;
   printf("trovato");
   i++;
   j++;
   }
   else if (a[i]<b[j]) i++;
       else j++;
}

printf("%d",count);

}
