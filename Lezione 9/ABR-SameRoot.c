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

void simm(node* root){
 if(root!=NULL){
   simm(root->sx);
   printf("%d\n",root->data);
   simm(root->dx);
 }
}

int percorsi(node* root1,node* root2,int k){
    if(root1 == NULL && root2 == NULL)
    { return 1; } //Sono entrambi alberi vuoti//

    if( (root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL) )
    {return 0; } //Uno dei due è pieno mentre l'altro è vuoto//

    if(root1->data == k && root2->data == k) return 1; //Both nodes contain k

    if( (root1->data == k && root2->data != k) || (root1->data != k && root2->data == k) ) return 0; //Non tutti e due nodi contengono k//

    if(root1->data != root2->data)return 0; //Hanno percorsi diversi se le chiavi non corrispondono//

    if(k < root1->data)
        return percorsi(root1->sx,root2->sx,k);
    else
        return percorsi(root1->dx,root2->dx,k);
}




int main(){
  node* abr1=NULL;
  node* abr2=NULL;
  int n,i,key,k;
  scanf("%d",&n);
  scanf("%d",&k);
  for(i=0;i<n;i++){
    scanf("%d",&key);
    insert(&abr1,key);
  }
  for(i=0;i<n;i++){
    scanf("%d",&key);
    insert(&abr2,key);
  }
  printf("%d",percorsi(abr1,abr2,k));
}
