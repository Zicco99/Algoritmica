#include <stdio.h>
#include <stdlib.h>

#define Prime 999149

typedef struct _node{
  int data;
  struct _node* next;
}nodo;

typedef struct hashtable{
  int spazi;
  int a;
  int b;
  int p;
  int conflitti;
  int max;
  nodo** lista;
}hash;

int valhash(int x,int n,int a,int b,int p){
    return ((a*x+b)%p)%n;
}

void insert(hash* tab,int key){
  int l_list=0;
  int h;
  h=valhash(key,tab->spazi,tab->a,tab->b,tab->p);
  // CREO UN NODO E LO INSERISCO//
  nodo* aux=(nodo*)malloc(sizeof(nodo));
  aux->data=key;
  aux->next=NULL;
  if(tab->lista[h]==NULL){
    tab->lista[h]=aux;
    l_list++;
  }
  else{
    tab->conflitti++;
    l_list++;
    nodo* cur=tab->lista[h];
    while(cur->next!=NULL){
      l_list++;
      cur=cur->next;
    }
    cur->next=aux;
    l_list++;
  }
  if(l_list>tab->max) tab->max=l_list;
}












void createhash(hash* tab){
  int n,a,b;
  int i,key;
  scanf("%d",&n);
  scanf("%d",&a);
  scanf("%d",&b);
  //settiamo gli attributi//
  tab->spazi=2*n;
  tab->a=a;
  tab->b=b;
  tab->p=Prime;
  tab->conflitti=0;
  tab->max=0;

  //Allochiamo lo spazio delle liste//
  tab->lista=(nodo**)malloc(tab->spazi*sizeof(nodo*));

  // INIZIALIZZIAMO LE LISTE A LISTE VUOTE//
  for(i=0;i<tab->spazi;i++) tab->lista[i]=NULL;

  //CARICHIAMO//
  for(i=0;i<n;i++){
    scanf("%d",&key);
    insert(tab,key);
  }
}



int main(){
  hash tabella;
  createhash(&tabella);
  printf("%d\n",tabella.max);
  printf("%d",tabella.conflitti);



}
