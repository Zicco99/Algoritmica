#include <stdio.h>
#include <stdlib.h>
typedef struct elem{
  int data;
  struct elem *next;
} elemento;

void addo(elemento** head,int v){
    elemento* aux = malloc(sizeof(elemento));
    elemento* temp;
    aux->data = v;
    aux->next = NULL;
    if(*head == NULL){//Empty list
        *head = aux;
    }else{//At least one element in list
        temp=*head;
        while(temp->next==NULL) temp=temp->next;
        temp->next = aux;

    }
}

void stampainversa(elemento* head){
    if(head != NULL){
        stampainversa(head->next);
        printf("%d\n",head->data);
    }
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
