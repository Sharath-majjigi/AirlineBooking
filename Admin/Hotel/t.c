#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *F;
    F = fopen("text.txt", "r");
    char cities[30][10];
    float f[30];
    int i[30];
    char hotels[50][40];
    char c;
    char str[100];
    int count = 0;
    char *_;
    while (!count)
    {
        int j = 0;
        while((c = fgetc(F)) != ','){
            str[j++] = c;
        }
        printf("%s",str);
        j = 0;
        while(( c = fgetc(F)) != '|'){
            str[j++] = c;
        }
        printf("%s",str);
        j = 0;
        while(( c = fgetc(F)) != '|'){
            str[j++] = c;
        }
        double r = strtod(str,&_);
        printf("\n%lf\n",r);
        count = 1;
    }
    printf("a%d", feof(F));
    // printf("%s\n",str);
    // printf("%c",fgetc(F));
    fclose(F);
    return 0;
}