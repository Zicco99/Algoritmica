#include <stdio.h>
#include <stdlib.h>
typedef struct _node{
  int data;
  struct _node* sx;
  struct _node* cx;
  struct _node* dx;
  int full;
}node;


node* insert(node* tree,int k){
    node* aux=(node*)malloc(sizeof(node));
    aux->data = k;
    aux->sx = NULL;
    aux->dx = NULL;
    aux->cx = NULL;
    if(tree==NULL) return aux;
    //PERCORRO//
    if(k < tree->data) {
    tree->sx = insert(tree->sx,k);
    }
    else {
      if((k%(tree->data))==0) tree->cx = insert(tree->cx,k);
      else tree->dx = insert(tree->dx,k);
    }
  return tree;

}

node* initree(int* n){
  node* tree=NULL;
  int i,key;
  scanf("%d",n);
  for(i=0;i<*n;i++){
    scanf("%d",&key);
    tree=insert(tree,key);
  }
  return tree;
}

int conta(node * tree){
    if(tree == NULL) return 0;
    if(tree->sx != NULL && tree->cx != NULL && tree->dx != NULL){ // QUESTO NODO HA TRE FIGLI!//
    return 1 + conta(tree->sx) + conta(tree->cx) + conta(tree->dx);
    }

    if(tree->sx == NULL && tree->cx == NULL && tree->dx == NULL)//E' Foglia perchè non ha figli//
        return 0;

    //Non rispetta i casi base,concludo//
    return conta(tree->sx) + conta(tree->cx) + conta(tree->dx);
}

int main(){
  int n;
  node* abr1=initree(&n);
  printf("%d",conta(abr1));
}
