#ifndef DISPLAY
#define DISPLAY
#include "imports.h"
/*
Function to display the hotels
*/
void displayhotels(struct city *C)
{
    //Variable Declarations
    struct hotel *Head = C->HOTELS;
    struct hotel *temp = Head;
    //Display
    /*
    To Do : Shreya
    - Display data and style the output
    */
    printf("%s %s %s\n", "HOTEL NAME", "PRICE", "ROOMS");
    while (temp != NULL)
    {
        printf("%s %lf %d\n", temp->name, temp->price, temp->rooms);
        temp = temp->next_hotel;
    }
}

/*
Function to display cities
*/
void displaycities()
{
    //Variable Declarations
    struct city *temp = City_Head;

    FILE *fp;
    //Display
    /*
    To Do : Shreya
    - Display data and style the output
    */
    while (temp != NULL)
    {
        printf("%s\n\n", temp->name);
        printf("\n");
        displayhotels(temp);
        writeToFile(fp, temp);
        temp = temp->next_city;
    }
}
#endif