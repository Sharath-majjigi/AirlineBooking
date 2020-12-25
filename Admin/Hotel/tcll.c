#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"struct.h"

void extractCity(FILE *file, char str[90])
{  
    struct extract *ec=(struct extract *)malloc(sizeof(struct extract*)); 
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
        str[j++] = character;   //one hotel full info hotel|price|rooms  ,hotel..
    }
    str[j] = '|';
    j = 0;
    while (str[j] != '|')
    {
        str_h[j] = str[j]; //one hotel name
        j++;
    }
    j++;
    while (str[j] != '|')
    {
        temp[i++] = str[j];  //price string
        j++;
    }
    j++;
    price = strtod(temp, &c); //read a floating no
    i = 0;
    while (str[j] != '|')
    {
        temp[i++] = str[j];   //room string
        j++;
    }
    rooms = atoi(temp);   //reading int no
    *p = price;
    *r = rooms;
}
int main()
{
    struct city *exc=(struct city*)malloc(sizeof(struct city*));
    struct hotel *exh=(struct hotel*)malloc(sizeof(struct hotel*));
     exh=exc->HOTELS;
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
        strcpy(exc->name,s);
        exc->HOTELS=NULL;
        printf("\n\n%s\n",exc->name);
        while ((c = fgetc(F)) != '#')
        {
            ungetc(c,F);
            extractHotel(F, hotelname, price, rooms);
            strcpy(exh->name,hotelname);
            exh->price=*price;
            exh->rooms=*rooms;
            exh->next_hotel=NULL;
            printf("\n%s %lf %d", exh->name,exh->price, exh->rooms);
        }
    }
    fclose(F);
    return 0;
}