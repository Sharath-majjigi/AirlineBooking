#ifndef ADMIN
#define ADMIN
#include"imports.h"
/*

This functions adds a hotel node for a particular city

A struct city* type formal parameter is passed to it.

Taking this city node it gets the link for the HOTELS 
And appends a hotel type node in a FILO fashion 

*/
void addhotel(struct city* C){
    struct hotel* Hotel_Head = (struct hotel*)malloc(sizeof(struct hotel));
    Hotel_Head = C->HOTELS;
    char hotelname[30];
    double hotelprice;
    int hotelrooms;

    //Reading the input
    printf("\nEnter the Hotel name\n");
    scanf("%s",hotelname);
    printf("\nEnter the hotel price\n");
    scanf("%lf",&hotelprice);
    printf("\nEnter the number of rooms\n");
    scanf("%d",&hotelrooms);

    //A temporary node of type hotel
    struct hotel* temp = (struct hotel*)malloc(sizeof(struct hotel));

    //Copy the input data into the temporary node
    strcpy(temp->name,hotelname);
    temp->rooms = hotelrooms;
    temp->price = hotelprice;

    //Check if list is empty
    if(Hotel_Head == NULL){
        temp->next_hotel = NULL;
        Hotel_Head = temp;
    }
    else{
        temp->next_hotel = Hotel_Head;
        Hotel_Head = temp;
    }

    /*
    Put the updated reference back into the city node that was passed to this function
    */
    C->HOTELS = Hotel_Head;
}

/*
This function adds N hotels
*/
void addNhotels(struct city* C,int n){
    for(int i = 0; i < n; i++){
        addhotel(C);
    }
}



/* 
This is simpler and analogus to the addhotel() function
*/
void addcity(){
    //Variable Declarations
    char cityname[30];
    int number_of_hotels;
    struct city* temp = (struct city*)malloc(sizeof(struct city));

    //Read input
    printf("\nEnter city name\n");
    scanf("%s",cityname);
    printf("\nHow many hotels in %s\n",cityname);
    scanf("%d",&number_of_hotels);

    //Copy the data into node
    strcpy(temp->name,cityname);

    //Manage dangling pointer
    temp->HOTELS = NULL;

    //Check if list is empty
    if(City_Head == NULL){
        temp->next_city = NULL;
        City_Head = temp;
        addNhotels(temp, number_of_hotels); //Call function for adding hotels to this city
    }
    else{
        temp->next_city = City_Head;
        City_Head = temp;
        addNhotels(temp, number_of_hotels);
    }
}
#endif