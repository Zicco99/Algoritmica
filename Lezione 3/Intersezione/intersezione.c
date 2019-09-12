#include <stdio.h>
int ricercabinaria(int b[],int x,int sx,int dx){
int cx;
if (sx>dx) return -1;
if (sx==dx) {
        if(b[sx]==x) return 1;
          else return -1;
          }
cx=(sx+dx)/2;
if (x==b[cx]) return 1;
   else if (x<b[cx]) return ricercabinaria(b,x,sx,cx-1);
        else return ricercabinaria(b,x,cx+1,dx);
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

for(i=0;i<dima;i++){
   if(ricercabinaria(b,a[i],0,dimb)==1) count++;
  }


printf("%d\n",count);


}
