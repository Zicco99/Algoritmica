    #include<stdio.h>
    #include<stdlib.h>

    void read_input(int **a,int *dim){
    int i;
    scanf("%d\n",dim);
    *a = (int*)malloc(*dim * sizeof(int));
    for(i=0;i<*dim;i++){
      scanf("%d",(*a)+i);
      }
    }
    
    void print_output(int *a,int dim){
    int i;
    for(i=0;i<dim;i++){
      printf("%d\n",a[i]);
      }
    }
    
    void maxheapify(int a[],int i,int dim){
    int l,r,largest,scambio;
    l=(2*i);
    r=(2*i)+1;
    largest=i;
    if(l<=dim && a[largest]<a[l]) largest=l;
    if(r<=dim && a[largest]<a[r]) largest=r;
    // CALCOLO MAX TRA I TRE //
    if(largest!=i){
     scambio=a[i];
     a[i]=a[largest];
     a[largest]=scambio;
     maxheapify(a,largest,dim);
     }
    }
    
    void buildmaxheap(int *a,int dim){
    int i;
    for(i=dim/2;i>=0;i--){
      maxheapify(a,i,dim);
      }
    }
    
    void heapsort(int *a,int dim){
     int i,scambio;
     buildmaxheap(a,dim);
     i=dim;
     do{
       scambio=a[i];
       a[i]=a[0];
       a[0]=scambio;
       dim--;
       maxheapify(a,0,dim);
       i--;
      }while(i>0);
     }
    
    
    int main(){
    int dim,*vett;
    read_input(&vett,&dim);
    heapsort(vett,dim-1);
    print_output(vett,dim);
    
    }
    
    
