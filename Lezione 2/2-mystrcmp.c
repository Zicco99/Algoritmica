#include <stdio.h>
#include <stdlib.h>
void my_strcmp(char *s1, char *s2)
{
    while((*s1!='\0' && *s2 != '\0' ) && *s1==*s2)
    {
        s1++;
        s2++;
    }
    if(*s1 == *s2)
    {
        printf("0");
    }
    else
    {
        if ((*s1-*s2)>0) printf("+1");
        else printf("-1");
    }
}
int main(){
char locs1[1000],locs2[1000];
scanf("%s",locs1);
scanf("%s",locs2);
my_strcmp(locs1,locs2);
}
