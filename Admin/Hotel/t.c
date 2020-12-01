#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void extractCity(FILE *file, char str[90])
{
    char character;
    int j = 0;
    while ((character = fgetc(file)) != ',')
    {
        str[j++] = character;
    }
}
void extractHotel(FILE *file, char str_h[90],double *p, int *r)
{
    char str[200];
    char character, *c;
    char temp[50];
    double price;
    int rooms;
    int j = 0, i = 0;
    while((character = fgetc(file)) != ','){
        str[j++]=character;
    }
    str[j] = '|';
    j = 0;
    while (str[j] != '|')
    {
        str_h[j] = str[j];
        j++;
    }
    j++;
    while (str[j] != '|')
    {
        temp[i++] = str[j];
        j++;
    }
    j++;
    price = strtod(temp,&c);
    printf("\nPRICE\n%lf",price);
    i = 0;
    while (str[j] != '|')
    {
        temp[i++] = str[j];
        j++;
    }
    rooms  = atoi(temp);
    printf("\nROOMS\n%d\n",rooms);
    *p = price;
    *r = rooms;
}
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
    char hotelname[40];
    double *price = (double *)malloc(sizeof(double));
    int *rooms = (int *)malloc(sizeof(int));
    while (!count)
    {
        char s[90];
        extractCity(F, s);
        printf("\n\n%s\n\n", s);
        extractHotel(F,hotelname, price, rooms);
        printf("\nworks\n%s%lf",hotelname,*price);
       /* int j = 0;
        while ((c = fgetc(F)) != '|')
        {
            str[j++] = c;
        }
        printf("%s", str);
        j = 0;
        while ((c = fgetc(F)) != '|')
        {
            str[j++] = c;
        }
        double r = strtod(str, &_);
        printf("\n%lf\n", r);*/
        count = 1;
    }
    // printf("%s\n",str);
    // printf("%c",fgetc(F));
    fclose(F);
    return 0;
}