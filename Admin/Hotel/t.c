#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
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
int main()
{
    FILE *F;
    F = fopen("text.txt", "r");
    char c;
    char str[100];
    char hotelname[40];
    double *price = (double *)malloc(sizeof(double));
    int *rooms = (int *)malloc(sizeof(int));
    while ((c = fgetc(F)) != EOF)
    {
        ungetc(c,F);
        char s[90];
        extractCity(F, s);
        printf("\n\n%s\n", s);
        while ((c = fgetc(F)) != '#')
        {
            ungetc(c,F);
            extractHotel(F, hotelname, price, rooms);
            printf("\n%s %lf %d", hotelname, *price, *rooms);
        }
    }
    fclose(F);
    return 0;
}