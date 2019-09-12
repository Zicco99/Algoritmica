    #include<stdio.h>
    #include<stdlib.h>

    void read_input(int **a,int *dim){
    int i;
    scanf("%d\n",dim);
    *a = (int*)malloc(*dim*sizeof(int));
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
    
    
    int checkheapify(int arr[],int i,int dim){
    for(i=0;i<dim;i++){
    if((2*i+1)<=dim){
        if( arr[i]<arr[2*i] || arr[i]<arr[2*i+1] ) 
           return 0;
           }
    else if((2*i)<=dim){
        if( arr[i]<arr[2*i]) 
           return 0;
    }
    else break;
   }
   return 1;
   }
   
   
    
    int main(){
    int dim,*vett,res;
    read_input(&vett,&dim);
    res=checkheapify(vett,0,dim);
    printf("%d",res);
    print_output(vett,dim);
    }
    
    
