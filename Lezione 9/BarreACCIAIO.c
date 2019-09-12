#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void crealistino(int prezzi[],int* n){
    int n;
    scanf("%d",&n);
    if(n<=0) printf("Non si accettano lunghezze negative");
    else{
        a = (int *)malloc(n * sizeof(int));
        for (int i=0; i<n; i++) //Read prices
        scanf("%d",&a[i]);
    }
}

int max(int a,int b){
    int m = a;
    if(b > m)m = b;
    return m;
}

int getMaxProfit_Inefficient(int * p,int n){
    if(n == 0) return 0; //Price for bar of lenght 0
    int m = INT_MIN; // -infinity
    for(int i=1;i<=n;i++)
        m = max(m,p[i-1] + getMaxProfit_Inefficient(p, n - i));
    return m;
}

int bottomUp_MaxProfit(int * p,int n,int * optimal_size){
    int * r = malloc( (n+1) * sizeof(int)); //r[0...n]
    int * s = malloc( (n+1) * sizeof(int)); //s[0...n]
    int m; //hold max revenue
    r[0] = 0;
    for(int j = 1; j<= n; j++){
        m = INT_MIN;
        for(int i = 1; i<= j; i++){
            if(m < p[i -1] + r[j - i]){//New optimal size
                m = p[i -1] + r[j - i]; //Updated max revenue
                s[j] = i;
            }
        }
        r[j] = m; //get max revenue for rod of lenght j
    }
    *optimal_size = s[n]; //get optimal size cut for rod n
    return r[n];
}


int main() {
    int* prezzi = NULL; //ARRAY LISTINO PREZZI//
    int lun; //Lunghezza Barra
    crealistino(&prezzi,&lun);

    if(n>0){//Bar is at least 1 inch long
        int optimalSize = n;
        int maxRevenue = bottomUp_MaxProfit(prices,n,&optimalSize);
        printf("%d\n",maxRevenue);
        if(optimalSize == n) printf("%d\n",n);
        else
            printf("%d %d\n",optimalSize,n-optimalSize);

    }
