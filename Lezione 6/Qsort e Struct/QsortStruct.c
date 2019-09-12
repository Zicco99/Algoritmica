#include <stdio.h>
#include <stdlib.h>
typedef struct {
  int x;
  int y;
} point;

void print_output(point *array,int dim){
  int i;
  for(i=0;i<dim;i++){
    printf("%d ",array[i].x);
    printf("%d\n",array[i].y);
  }

}
int compare(const void* a,const void* b){
  point v1=*(point*)a;
  point v2=*(point*)b;
  if(v1.x != v2.x) return v1.x-v2.x;
    else return v2.y - v1.y;
}

void funct(point *a,int *dim){
  int i;
  scanf("%d",dim);
  a=(point*) malloc (*dim*sizeof(point));
  for(i=0;i<*dim;i++){
    scanf("%d",&(a[i].x));
    scanf("%d",&(a[i].y));
  }
  qsort(a,*dim,sizeof(point),compare);
  print_output(a,*dim);
}


int main(){
  int i;
  point* array;
  int dim;
  funct(&array,&dim);
}
