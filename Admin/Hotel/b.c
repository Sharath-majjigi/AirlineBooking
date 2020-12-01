#include<stdio.h>
int main(){
    char *s;
    scanf("%[^\n]%c",s);
    printf("\n%s\n",s);

    scanf("%[^\n]",s);
    printf("i\n%s\n",s);
    return 0;
}