#include <stdio.h>
#include <stdlib.h>
char* conca(int a,char* s1,int b,char* s2){
int i;
char* s3=(char*) malloc((a+b+1)*sizeof(char));
int pos=0;
for(i=0;i<a;i++){
s3[pos++]=s1[i];
}
for(i=0;i<b;i++){
s3[pos++]=s2[i];
}
s3[pos]='\0';
return s3;
}


int main(){
char *locs1,*locs2,*locs3;
int x,y,sum;
scanf("%d",&x);
locs1 = (char*) malloc((x+1)*sizeof(char));
scanf("%s",locs1);

scanf("%d",&y);
locs2 = (char*) malloc((y+1)*sizeof(char));
scanf("%s",locs2);

locs3 = (char*) malloc((y+x+1)*sizeof(char));

locs3 = conca(x,locs1,y,locs2);

puts(locs3);
}




