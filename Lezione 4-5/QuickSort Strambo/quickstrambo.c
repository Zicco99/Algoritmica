
    #include<stdio.h>
    #include<stdlib.h>

    void read_input(int **a,int *dim);
    void quick_sort(int *a,int sx,int dx);
    void print_output(int *a,int dim);
    int partition(int *a,int sx,int dx);
    void pre_partition(int *a,int sx,int dx,int *p1,int *r1,int *p2,int *r2);

    int main (int argc, char *argv[])
    {
       int *array;
       int dim;
       int p1,r1,p2,r2;

       read_input(&array,&dim);

       pre_partition(array,0,dim-1,&p1,&r1,&p2,&r2);

       quick_sort(array,p1,r1);

       quick_sort(array,p2,r2);

       print_output(array,dim);

       return 0;

    }
    /*Partiziona l`array in 2 parti : a sinistra i pari a destra i dispari*/
    void pre_partition(int *a,int sx,int dx,int *p1,int *r1,int *p2,int *r2)
    {
       int i=sx-1;
       int k=dx+1;
       int j=0;
       int tmp;

       while(j < k)
       {
          if(a[j] % 2 == 0)
          {
             i++;
             tmp=a[j];
             a[j]=a[i];
             a[i]=tmp;
             j++;
          }

          else
          {
             k--;
             tmp=a[j];
             a[j]=a[k];
             a[k]=tmp;
          }
       }

       *p1=sx;
       *r1=j-1;
       *p2=k;
       *r2=dx;
    }



    void read_input(int **a,int *dim)
    {
       int i;

       scanf("%d",dim);

       *a=(int*)malloc(*dim * sizeof(int));

       for(i=0; i < *dim;i++)
       {
          scanf("%d",a[i]);
       }
    }

    /*
       Divide et impera: Con partition
       divido l'array in 2 parti,elementi piu'
       piccoli del pivot,elementi piu' grandi
       del pivot,chiamo la ricorsione sulla parte
       destra e sinistra dell'array tranne la parte
       centrale (pivot)che è gia ordinato.
    */

    void quick_sort(int *a,int sx,int dx)
    {
       int q;//elemento centrale

       if(sx < dx)
       {
          q=partition(a,sx,dx);
          quick_sort(a,sx,q-1);
          quick_sort(a,q+1,dx);
       }
    }

    int partition(int *a,int sx,int dx)
    {
       int i=sx-1;
       int j,tmp;

       for(j=sx;j < dx;j++)
       {
          if(a[j] <= a[dx])
          {
             i++;
             tmp=a[i];
             a[i]=a[j];
             a[j]=tmp;
          }
       }

       tmp=a[i+1];
       a[i+1]=a[dx];
       a[dx]=tmp;

       return i+1;
    }

    void print_output(int *a,int dim)
    {
       int i;

       for(i=0; i < dim;i++)
       {
          printf("%d ",a[i]);
       }
    }
