#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*

struct definition for Hotel

This will be a node and a link pointing to
to N of these nodes will be stored in city

*/
struct hotel{
    char name[30];
    double price;
    int rooms;
    struct hotel* next_hotel;
};

/* 

This is the definition for city node
next_city is a link to the next city node

HOTELS is a link to the first of the N hotels
for a particular city

*/
struct city{
    char name[30];
    struct hotel* HOTELS; //This of this as first for the hotels linked list
    struct city* next_city;
};
struct city* City_Head; //Think of this as first for our linked list 

/*

This functions adds a hotel node for a particular city

A struct city* type formal parameter is passed to it.

Taking this city node it gets the link for the HOTELS 
And appends a hotel type node in a FILO fashion 

*/
void addhotel(struct city* C){

    //Variable Declarations
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

/*
Function to display the hotels
*/
void displayhotels(struct city* C,int city_name_length){
    //Variable Declarations
    struct hotel* Head = (struct hotel*)malloc(sizeof(struct hotel));
    struct hotel* temp = (struct hotel*)malloc(sizeof(struct hotel));
    Head = C->HOTELS;
    temp = Head;

    //Display 
    /*
    To Do : Shreya
    - Display data and style the output
    */
    printf("%s %s %s\n","HOTEL NAME","PRICE","ROOMS");
    while(temp != NULL){
        printf("%s %lf %d\n",temp->name,temp->price,temp->rooms);
        temp = temp->next_hotel;
    }
}

/*
Function to display cities
*/
void displaycities(){
    //Variable Declarations
    struct city* temp = (struct city*)malloc(sizeof(struct city));
    temp = City_Head;

    //Display 
    /*
    To Do : Shreya
    - Display data and style the output
    */
    while(temp != NULL){
        printf("%s\n\n",temp->name);
        printf("\n");
        displayhotels(temp,formatting(strlen(temp->name),getwidth()) - strlen(temp->name));
        temp = temp->next_city;
    }
}

char choose[2]; //Global variable for Y/N input

/*
Function to ask whether user wants to continue

Takes string input str and displays :
" Do you want to add a (prinit str) "

*/
void ask(char str[]){
    printf("\nDo you want to add a %s\n(Y/N)",str);
    scanf("%s",choose);
}

//Driver code
int main()
{
    City_Head = NULL;
    ask("city");
    while (choose[0] == 'Y')
    {
        addcity();
        ask("city");
    }
    displaycities();
    return 0;
}
