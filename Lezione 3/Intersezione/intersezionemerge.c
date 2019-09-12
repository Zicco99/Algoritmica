#include <stdio.h>
int similmerge(int a[],int x,int b[],int y){
int i,j,count;
i=0;j=0,count=0;
while(i<x && j<y){
if(a[i]<b[j]) i++;
   else if (a[i]>b[j]) j++;
       else {
              i++;
              j++;
              count++;
              }
 }
 return count;
}



void insertion(int v[],int dim){
int i,j,key;
for(i=1;i<dim;i++){
   key=v[i];
   j=i-1;
   while(v[j]>key && i>=0){
     v[j+1]=v[j];
     j--;
   }
   v[j+1]=key;
   }
}
   


int main(){
int i,j,count;
int dima,dimb;
count=0;

scanf("%d",&dima);
int a[dima];
for(i=0;i<dima;i++) scanf("%d",&a[i]);

scanf("%d",&dimb);
int b[dimb];
for(i=0;i<dimb;i++) scanf("%d",&b[i]);

i=1;
while(a[i]>a[i-1] && i<dima){ count++; i++;}
  
if(count<(dima-1)) insertion(a,dima);

i=1;
count=0;

while(b[i]>b[i-1] && i<dimb){count++; i++;}
 
if(count<(dimb-1)) insertion(b,dimb);


printf("%d\n",similmerge(a,dima,b,dimb));


}
