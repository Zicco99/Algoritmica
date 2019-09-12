#include <stdio.h>
int* FindVal(int a[],int len,int val)
{
  int i;
  for(i=0;i<len;i++){
  if (a[i]==val) return &a[i];
  }
  return NULL;
}


int main(){
int v[10];
int* pos;
int i,n;

for(i=0;i<10;i++) scanf("%d",&v[i]);
scanf("%d",&n);
pos=FindVal(v,10,n);
if (pos!=NULL) printf("trovato");
  else printf("non trovato");
 return 0;
 }
 

