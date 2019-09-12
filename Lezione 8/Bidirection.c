#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{//Nodo per lista unidirezionale
    int val;
    struct _Node * next;
} Node;

void append(Node ** h,Node ** t,int k){
  Node* aux=malloc(sizeof(Node));
  aux->val=k;
  aux->next=NULL;
  if(*t==NULL){
    *h=aux;
    *t=aux;
  }
  else{
    (*t)->next=aux;
    *t=aux;
  }

}

void readList(Node ** h,Node **t,int * n){
Node* head=NULL;
Node* tail=NULL;
int val;
scanf("%d",n);
for(int i=0;i<*n;i++){
  scanf("%d",&val);
  append(&head,&tail,val);

   }
   *h=head;
   *t=tail;
}

int Find(Node** h,int k){
  Node* cur=*h;
  Node* prev =NULL;
  int pos=0;

  if(*h == NULL) return -1;
   else{
     while(cur!=NULL && cur->val!=k){
       prev=cur;
       cur=cur->next;
       pos++;
     }
     if(cur==NULL) pos=-1;
     else{
       if(cur!=*h){
         prev->next=cur->next;
         cur->next=*h;
         *h=cur;
       }
     }
   }
   return pos;
}

void printListInv(Node * h){
    if(h != NULL){
        printListInv(h->next);
        printf("%d\n",h->val);
    }
}

void deleteList(Node ** h){
    if(*h != NULL){
        Node * p = *h;
        while(p != NULL){//Loop through all nodes
            p = p->next;
            free(p);
        }
        *h = NULL;
    }
}

void printList(Node * h){
    if(h != NULL){
        printf("%d\n",h->val);
        printList(h->next);
    }
}



int main(){
  Node* input_h=NULL;
  Node* input_t=NULL;
  Node* output_h=NULL;
  Node* output_t=NULL;


 int target;
 int res=-1;
 int n;
 readList(&input_h,&input_t,&n);
 do{
   scanf("%d",&target);
   res=Find(&input_h,target);
   append(&output_h,&output_t,res);
 }while(res!=-1);

    printList(output_h);

    deleteList(&input_h);
    deleteList(&output_h);
    return 0;

}
