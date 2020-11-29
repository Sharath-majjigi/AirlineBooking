#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    FILE *F;
    F = fopen("text.txt","r");
    char cities[30][10];
    float f[30];
    int i[30];
    char hotels[50][40];
    char c;
    char str[100];
    int count = 0;
    while(!feof(F)){
        printf("%c",fgetc(F));
        printf("%d\n",++count);
    }
   // printf("%s\n",str);
   // printf("%c",fgetc(F));
    fclose(F);
    return 0;
}