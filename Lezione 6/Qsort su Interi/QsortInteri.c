#include <stdio.h>
#include <stdlib.h>
void read_input(int **a,int *dim){
  int i;
  scanf("%d",dim);
  *a=(int *) malloc (*dim * sizeof(int));
  for(i=0;i<*dim;i++){
    scanf("%d",(*a+i));
  }
}
void print_output(int *a,int dim)
{
   int i;
   for(i=0; i < dim;i++)
   {
      printf("%d\n",a[i]);
   }
}

int compare(const void *a,const void *b){
int v = *( (int*)a );
int v2 = *( (int*)b );
int rs = abs(v % 2);
int rs2 = abs(v2 % 2);
if (rs == 0) return rs - rs2;
else if (rs != rs2) return v - v2;
else return v2 - v;
}
int main (){
  int *array,dim,pivot;
  read_input(&array,&dim);
  qsort(array,dim,sizeof(int),compare);
  print_output(array,dim);
}
