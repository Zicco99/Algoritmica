    #include<stdio.h>
    #include<stdlib.h>

    void read_input(int **a,int *dim) {
        int i;
        scanf("%d",dim);
        *a = (int *) malloc(*dim * sizeof(int));
        for (i = 0; i < *dim; i++) {
            scanf("%d", *a + i);
        }
    }

    void print_array(int array[],int dim) {
        int i;
        for(i=0;i<dim;i++) {
            printf("%d ",array[i]);
        }

    }





    void merge(int arr[], int sx, int cx, int dx)
    {
        int i, j, k;
        int n1 = cx - sx + 1;
        int n2 =  dx - cx;

        /* create temp arrays */
        int L[n1], R[n2];

        /* Copy data to temp arrays L[] and R[] */
        for (i = 0; i < n1; i++)
            L[i] = arr[sx + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[cx + 1+ j];

        /* Merge the temp arrays back into arr[l..r]*/
        i = 0; // Initial index of first subarray
        j = 0; // Initial index of second subarray
        k = sx; // Initial index of merged subarray
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k]=L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        /* Copy the remaining elements of L[], if there
           are any */
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        /* Copy the remaining elements of R[], if there
           are any */
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

void mergesort(int arr[], int sx, int dx)
{
    if (sx<dx)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int cx=sx+(dx-sx)/2;

        // Sort first and second halves
        mergesort(arr, sx,cx);
        mergesort(arr, cx+1,dx);

        merge(arr, sx, cx,dx);
    }
}

    int main(){
    int *array;
    int dim;

    read_input(&array,&dim);
    mergesort(array,0,dim);
    print_array(array,dim);
}
