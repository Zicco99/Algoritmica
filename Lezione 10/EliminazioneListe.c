#include <stdio.h>
#include <stdlib.h>
typedef struct _node{
  int data;
  struct _node* next;
}node;

void addbottom(node** lis,int key){
  node* aux=(node*)malloc(sizeof(node));
  aux->data=key;
  aux->next=NULL;
  if(*lis==NULL)  *lis=aux;
  else{
    node* temp=*lis;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=aux;
  }
}

void read_input(node** lista,int* n,int* sum){
  int key,i;
  scanf("%d",n);
  for(i=0;i<*n;i++){
    scanf("%d",&key);
    *sum=*sum+key;
    addbottom(lista,key);
  }
}

void printlist(node* lista){
  while(lista!=NULL){
    printf("%d ",lista->data);
    lista=lista->next;
  }
  printf("\n");
}

int sum (node* nodo){
  if(nodo==NULL){
    return 0;
  }
  return nodo->data + sum(nodo->next);
}

void suffix(node** lista){
  node* temp=*lista;
  while(temp!=NULL){
    temp->data=sum(temp->next);
    temp=temp->next;
  }
}




int main(){
  node* lista1=NULL;
  int n,s,med;
  s=0;
  read_input(&lista1,&n,&s);
  med=s/n;
  printlist(lista1);
  suffix(&lista1);
  printlist(lista1);
}
