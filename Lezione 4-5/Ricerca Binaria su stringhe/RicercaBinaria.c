#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ricercabinaria(char** v,char* key,int sx,int dx){
int cx,cmp;
if(sx>dx) return -1;
if(sx==dx){
   if(strcmp(v[sx],key)==0) return sx;
     else return -1;
}
cx=(sx+dx)/2;
cmp=strcmp(key,v[cx]);
if (cmp==0) return cx;
if (cmp<0) return ricercabinaria(v,key,sx,cx-1);
       else return ricercabinaria(v,key,cx+1,dx);

}
int main(){
int n,i,m;
char **vett;
scanf("%d",&n);
vett = (char**) malloc(n*sizeof(char*));
for(i=0;i<n;i++){
  vett[i]=(char *)malloc(101*sizeof(char));
  scanf("%s",vett[i]);
  }


for( ; ; ){
   scanf("%d",&m);
   if(m!=1){
     break;
   }
   char key[1000];
   scanf("%s",key);
   printf("%d\n",ricercabinaria(vett,key,0,n-1)); 
   }
return 0;
}
