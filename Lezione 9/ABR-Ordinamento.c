#include <stdio.h>
#include <stdlib.h>
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

int profsearch(node* root,int key){
  node* temp=root;
  while(temp!=NULL){
    if(temp->data==key) return temp->prof;
    else{
      if(temp->data<key) temp=temp->dx;
      else temp=temp->sx;

    }
  }
  return -1;
}




int main(){
  node* abr1=NULL;
  int n,i,key,r;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&key);
    insert(&abr1,key);
  }
  for(;;){
    scanf("%d",&key);
    if(key<0) break;
    r=profsearch(abr1,key);
    if(r==-1) puts("NO");
      else printf("%d\n",r);
  }

}
