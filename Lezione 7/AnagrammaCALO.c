#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLENSTRING 20

typedef struct stringanagramma{
	unsigned char* string;
	int *caratteri;
	int len;
}stgram;

void stringchar(unsigned char *s,int a[],int dim);
int cmp1(const void *x,const void *y);
int cmp2(const void *x,const void *y);
void print(stgram *a,int N);
int arraycompare(int *x,int *y,int dim);


int main(){
	stgram *b;
	int N;
	int i;
	scanf("%d",&N);
	b=(stgram*)malloc(N*sizeof(stgram));
	for(i=0;i<N;i++){
		b[i].string=(unsigned char*)malloc(MAXLENSTRING*sizeof(unsigned char));
		scanf("%s",b[i].string);
		b[i].len=strlen((char*)b[i].string);
		b[i].caratteri=(int*)malloc((b[i].len)*sizeof(int));
		stringchar(b[i].string,b[i].caratteri,b[i].len);
		qsort(b[i].caratteri,b[i].len,sizeof(int),cmp1);
	}
	qsort(b,N,sizeof(stgram),cmp2);

	/*for(i=0;i<N;i++){
		printf("%s\n",b[i].string);
	}*/
	print(b,N);
	return 0;
}

void stringchar(unsigned char *s,int a[],int dim){
	int i;
	for(i=0;i<dim;i++){
		a[i]=(int)s[i];
	}
}
int cmp1(const void *x,const void *y){
	int a=*(int*)x;
	int b=*(int*)y;
	return a-b;
}

int cmp2(const void *x,const void *y){
	stgram *a=(stgram*)x;
	stgram *b=(stgram*)y;
	int i;
	if(a->len==b->len){
		for(i=0;i<a->len;i++){
			if(a->caratteri[i]<b->caratteri[i])
				return -1;
			else if(a->caratteri[i]>b->caratteri[i])
				return 1;
		}
		return strcmp((char*)a->string,(char*)b->string);
	}
	else if (a->len<b->len){
		for(i=0;i<a->len;i++){
			if(a->caratteri[i]<b->caratteri[i])
				return -1;
			else if(a->caratteri[i]>b->caratteri[i])
				return 1;
		}
		return -1;
	}
	else if (a->len>b->len){
		for(i=0;i<a->len;i++){
			if(a->caratteri[i]<b->caratteri[i])
				return -1;
			else if(a->caratteri[i]>b->caratteri[i])
				return 1;
		}
		return 1;
	}
	return 0;
}

void print(stgram *a,int N){
	int i=0;
	printf("%s ",a[i].string);
	for(i=1;i<N;i++){
		if(a[i].len==a[i-1].len && arraycompare(a[i].caratteri,a[i-1].caratteri,a[i].len))
			printf("%s ",a[i].string);
		else printf("\n%s ",a[i].string);
	}
	printf("\n");
}





int arraycompare(int *x,int *y,int dim){
	for(int i=0;i<dim;i++){
		if(x[i]!=y[i])
			return 0;
	}
	return 1;
}
