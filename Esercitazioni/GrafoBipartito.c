#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _edge{
  int nedge;
  int* edges;
}edges;

edges* read_graph(int n){
int ne,i,j;
scanf("%d",&n);
edges* E=(edges*)malloc(n*sizeof(edges));
for(i=0;i<n;i++){
  scanf("%d",&ne);
  E[i].nedge=ne;
  E[i].edges=(int*) malloc(ne*sizeof(int));
  for(j=0;j<ne;j++) scanf("%d",E[i].edges+j);
   }
   return E;
}

int dfs(edges* E,int s,int* colore){
   int i,v;
   for(i=0;i<E[s].nedge;i++){
     v=E[s].edges[i];
     if(colore[v]==0){
       colore[v]=-colore[s];
       if(dfs(E,v,colore)==0) return 0;
     }
     else if(colore[s]==colore[v]) return 0;
   }
   return 1;
}

int bipartito(edges* E,int n){
  int i;
  int* colore=malloc(n*sizeof(int));
  for(i=0;i<n;i++) colore[i]=0;
  for(i=0;i<n;i++){
    if(colore[i]==0){
      colore[i]=1;
      if(dfs(E,i,colore)==0){
         free(colore);
          return 0;
      }
    }
  }
  return 1;
}
int main(){
int i,n;
scanf("%d",&n);
edges* E=read_graph(n);
printf("%d",bipartito(E,n));
for(i=0;i<n;i++) free(E[i].edges);
free(E);
return 0;
}
