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
void extractHotel(FILE *file, char str_h[90], double *p, int *r)
{
    char str[200];
    char character, *c;
    char temp[50];
    double price;
    int rooms;
    int j = 0, i = 0;
    while ((character = fgetc(file)) != ',')
    {
        str[j++] = character;
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
    price = strtod(temp, &c);
    i = 0;
    while (str[j] != '|')
    {
        temp[i++] = str[j];
        j++;
    }
    rooms = atoi(temp);
    *p = price;
    *r = rooms;
}
int check(FILE* file){
    if(fgetc(file) == '#'){
        return 0;
    }
    else{
        fseek(file, -1, 1);
        return 1;
    }
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
    int count, count_;
    count = 0;
    count_ = 0;
    char *_;
    char hotelname[40];
    double *price = (double *)malloc(sizeof(double));
    int *rooms = (int *)malloc(sizeof(int));
    while (count != 2)
    {
        char s[90];
        extractCity(F, s);
        printf("\nPOSITION -> %ld \n",ftell(F));
        printf("\n\n%s\n\n", s);
        count_= 0;
        while (check(F))
        {
            extractHotel(F, hotelname, price, rooms);
            printf("\n%s\t%lf\t%d", hotelname, *price, *rooms);
            count_++;
        }
        count++;
    }
    fclose(F);
    return 0;
}