#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node{
  char* nome;
  char* numero;
  struct _node* next;
}node;

void print(node* head){
  if (head==NULL) return;
   printf("%s %s\n",head->nome,head->numero);
   print(head->next);
}

int valhash(char* v, int dim){
 int ctr=0;
 int i=0;
 while(v[i]!='\0'){
   ctr+=(int)v[i];
   i++;
 }
 return (ctr % (2*dim)); }

void insert(node** head,char* nom,char* num){
  node* aux=malloc(sizeof(node));
  aux->nome=nom;
  aux->numero=num;
  aux->next=*head;
  *head=aux;
  printf("inserito\n");
}
void addo(node** head,char* nom,char* num){
    node* aux=malloc(sizeof(node));
    aux->nome=nom;
    aux->numero=num;
    node* cur=*head;
    if(*head==NULL || strcmp((*head)->nome,aux->nome)>=0){
       aux->next=*head;
       *head=aux;
    }
    else{
        while(cur->next!=NULL && strcmp(cur->nome,nom)<=0){
           cur=cur->next;
        }
    aux->next=cur->next;
    cur->next=aux;
  }
}


int main(){
  int n,i,h,k;
  scanf("%d",&n);
  node** tab=malloc((2*n)*sizeof(node*));
  for(i=0;i<(n*2);i++){
    tab[i]=NULL;

  }
  for(i=0;i<n;i++){
    char* nom=malloc(21*sizeof(char));
    char* num=malloc(21*sizeof(char));
    scanf("%s",nom);
    scanf("%s",num);
    h=valhash(nom,n);
    addo(&tab[h],nom,num);
  }
  scanf("%d",&k);
  print(tab[k]);

}
