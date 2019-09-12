#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1001
void product(char* s1,int v){
int i;
int len=strlen(s1);
int lentot = len*v+1;
char* ris = (char*) malloc(lentot*sizeof(len));
for(i=0;i<lentot-1;i++){
   ris[i]=s1[i%len];
   }
   ris[lentot-1]='\0';
printf("%s",ris);
}
int main(){
int k;
char locs1[MAX];
scanf("%s",locs1);
scanf("%d",&k);
product(locs1,k);
}




