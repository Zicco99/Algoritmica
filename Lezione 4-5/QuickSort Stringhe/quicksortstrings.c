#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void swap (char **a,int i, int j) {
  char temp[101];
  strcpy(temp,a[i]);
  strcpy(a[i],a[j]);
  strcpy(a[j],temp);
}
int distribuzione(char **a, int sx, int px, int dx) {
  int i,j; 
  char x[101];
  if (px != dx){
   swap (a,px,dx);
  }
   strcpy(x,a[dx]);
   i=sx-1;
  for(j=sx;j<dx;j++){
      if (strcmp(a[j],x)<=0)
     {
      i=i+1;
      swap(a,i,j);
    }
  }
  i++;
  swap(a,i,dx);
  return i;
}
void quicksort(char** a, int sx, int dx ) {
  
  int perno, pivot;
  if( sx < dx ) {
    pivot = ( rand() %(dx-sx+1))+sx;
    perno = distribuzione(a, sx, pivot, dx); /* separa gli elementi minori di a[pivot] 
					        da quelli maggiori o uguali */
    /* Ordina ricorsivamente le due metà */
    quicksort(a, sx, perno-1);
    quicksort(a, perno+1, dx);
    
  }

}

int main() {
 int len,i;
 char **vett;
 scanf("%d",&len);
 vett = (char**) malloc(len*sizeof(char*));
 for(i=0;i<len;i++){
  vett[i]=(char *)malloc(101*sizeof(char));
  scanf("%s",vett[i]);
  }

 quicksort(vett,0,len-1);
 
 for(i=0;i<len;i++){
  printf("%s\n",vett[i]);
 
 }
 return 0;
}






