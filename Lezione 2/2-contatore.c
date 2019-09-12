#include <stdio.h>

void reset(int array[],int len){
  int i;
   for(i=0;i<len;i++){
   array[i]=0;
  }
}

void add(int array[],int len,int val){
 if(val>=0 && val<len){
   array[val]=array[val]+1;
   }
 }

int main(){
int ris[10];
int n,i;
reset(ris,10);
for( ; ; ){
   scanf("%d",&n);
   if(n==-1){
     break;
   }
   add(ris,10,n);
   }
for(i=0;i<10;i++) printf("%d\n",ris[i]);
}





