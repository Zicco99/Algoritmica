#include <stdio.h>
#include <stdlib.h>
typedef struct elem{
  int data;
  struct elem *next;
} elemento;

void addo(elemento** head,int n){
  elemento* temp;
  elemento* nuovo=(elemento*)malloc(sizeof(elemento));
  nuovo->data=n;
  nuovo->next=NULL;
  if(*head==NULL){
    *head=nuovo;
  }
  else{
    temp=*head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=nuovo;
  }
}

void stampainversa(elemento* head){
  if(head)
  stampainversa(head->next);
  else
  return;
  printf("%d\n", head->data);
}

int main(){
  elemento* lista1=NULL;
  int i,n,d;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&d);
    addo(&lista1,d);
  }

  stampainversa(lista1);



}
