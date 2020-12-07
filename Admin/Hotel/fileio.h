#ifndef FILE_H
#define FILE_H
#include <stdlib.h>
#include "struct.h"
/*WRITE TO FILE*/
int isExists(FILE *file)
{
    if ((file = fopen("text.txt", "r")))
    {
        return 1;
    }
    return 0;
}

void writeToFile(FILE *file, struct city *CITY)
{
    if (!isExists(file))
    {
        file = fopen("text.txt", "w");
        fprintf(file, "%s,", CITY->name);
        struct hotel *temp = CITY->HOTELS;
        while (temp != NULL)
        {
           // fprintf(file, "%s %lf %d\n\n", temp->name, temp->price, temp->rooms);
            if ((temp->next_hotel) == NULL)
            {
                fprintf(file, "%s|%lf|%d\n", temp->name, temp->price, temp->rooms);
            }
            else
            {
                fprintf(file, "%s|%lf|%d,", temp->name, temp->price, temp->rooms);
            }
            temp = temp->next_hotel;
        }
    }
    else
    {
        file = fopen("text.txt", "a");
  fprintf(file, "%s,", CITY->name);
        printf("%s", (CITY->HOTELS)->name);
        struct hotel *temp = CITY->HOTELS;
        while (temp != NULL)
        {
              if ((temp->next_hotel) == NULL)
            {
                fprintf(file, "%s|%lf|%d\n", temp->name, temp->price, temp->rooms);
            }
            else
            {
                fprintf(file, "%s|%lf|%d,", temp->name, temp->price, temp->rooms);
            }
            temp = temp->next_hotel;
        }
        
    }
    fclose(file);
}

//READ FROM FILE
void readFromFile(FILE *file)
{
    char str[30];
    double a;
    int b;
    if(isExists(file)){
        file = fopen("text.txt","r");
        fscanf(file,"%s",str);
        printf("\nHERE %s\n",str);
        while (!feof(file))
        {
                  printf("\n%s %d %lf",str, b,a);
        }
        

        fclose(file);
    }
}
#endif