#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef min
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

typedef struct _node{
  int data;
  int prof;
  struct _node* sx;
  struct _node* dx;
}node;

void insert(node** root,int key){
  node* aux=(node*) malloc(sizeof(node));
  aux->data=key;
  aux->prof=0;
  aux->sx=NULL;
  aux->dx=NULL;
  if(*root==NULL){
    *root=aux;
  }
  else{
    node* parent;
    node* current=*root;
    while(current!=NULL){
      parent=current;
      aux->prof++;
      if(current->data < key) current=current->dx;
        else current=current->sx;
    }
    if (parent->data < key) parent->dx=aux;
     else parent->sx=aux;
  }
  return;
}

int simm(node* root){
 if(root!=NULL){
   simm(root->sx);
   printf("%d\n",root->data);
   simm(root->dx);
 }
}




int main(){
  node* abr1=NULL;
  int n,i,key,r;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&key);
    insert(&abr1,key);
  }
  simm(abr1);
}
