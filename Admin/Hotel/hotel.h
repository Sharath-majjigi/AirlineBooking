#ifndef HOTEL
#define HOTEL
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "dateparser.h"
#include "display.h"
#define textfile "te.txt"

/*

    EXTRACT CITY FROM FILE

*/
void extractCity(FILE *file, char cityname[100])
{
    char character;
    int j = 0;
    while ((character = fgetc(file)) != ',')
    {
        cityname[j++] = character;
    }
    cityname[j] = '\0';
}

/*

    EXTRACT HOTEL FROM FILE

*/
void extractHotel(FILE *file, char str_h[90], double *p, int *r)
{
    char *str = (char *)malloc(200 * sizeof(char));
    char character, *c;
    char temp[50];
    char temp_int[50];
    double price;
    int rooms;
    int j = 0, i = 0;
    while ((character = fgetc(file)) != ',')
    {
        str[j++] = character;
    }
    str[j] = '|';
    str[j + 1] = '\0';
    j = 0;
    while (str[j] != '|')
    {
        str_h[j] = str[j];
        j++;
    }
    str_h[j] = '\0';
    j++;
    while (str[j] != '|')
    {
        temp[i++] = str[j];
        j++;
    }
    temp[i] = '\0';
    j++;
    price = strtod(temp, &c);
    i = 0;
    while (str[j] != '|')
    {
        temp_int[i++] = str[j];
        j++;
    }
    temp_int[i + 1] = '\0';
    rooms = atoi(temp_int);
    *p = price;
    *r = rooms;
    free(str);
}

/*

    FOLLOWING FUNCTIONS ARE FOR 

    1. READING DATA FROM TEXT FILE
    2. MAKING A LINKEDLIST WITH THAT
    3. DISPLAYING THAT INFO TO USER 

*/

/*

    FUNCTION FOR hotel LINKEDLIST

*/
struct hotel *addHotel(struct hotel *Hotel_Head, char hotelname[100], double price, int rooms)
{
    struct hotel *temp = (struct hotel *)malloc(sizeof(struct hotel));
    strcpy(temp->name, hotelname);
    temp->price = price;
    temp->rooms = rooms;
    if (Hotel_Head == NULL)
    {
        temp->next_hotel = NULL;
        Hotel_Head = temp;
    }
    else
    {
        temp->next_hotel = Hotel_Head;
        Hotel_Head = temp;
    }
    return Hotel_Head;
}

/*

    FUNCTION FOR city LINKEDLIST
    NOTE : 
            THIS FUNCTION CAN ONLY BE USED WHILE READING INPUT FROM A  FILE
            NOT WHILE TAKING USER INPUT

*/
struct city *addCity(struct city *Head, struct hotel *Hotel_Head, char cityname[])
{
    struct city *temp = (struct city *)malloc(sizeof(struct city));
    strcpy(temp->name, cityname);
    if (Head == NULL)
    {
        temp->next_city = NULL;
        temp->HOTELS = Hotel_Head;
        Head = temp;
    }
    else
    {
        temp->next_city = Head;
        temp->HOTELS = Hotel_Head;
        Head = temp;
    }
    return Head;
}

/*

    DRIVER FUNCTION FOR READING FROM FILE

*/
struct city *readStruct(struct city *C)
{
    C = NULL;
    FILE *F;
    F = fopen(textfile, "r");
    struct city *city_ptr = (struct city *)malloc(sizeof(struct city));
    char c, city_name[100];
    while ((c = fgetc(F)) != EOF)
    {
        if (c != '\n')
        {
            ungetc(c, F);
            extractCity(F, city_name);
            struct hotel *hotel_head = (struct hotel *)malloc(sizeof(struct hotel));
            hotel_head = NULL;
            while ((c = fgetc(F)) != '#')
            {
                char hotelname[40];
                double *price = (double *)malloc(sizeof(double));
                int *rooms = (int *)malloc(sizeof(int));
                if (c != '\n')
                {
                    ungetc(c, F);
                    extractHotel(F, hotelname, price, rooms);
                    hotel_head = addHotel(hotel_head, hotelname, *price, *rooms);
                }
            }
            C = addCity(C, hotel_head, city_name);
        }
    }
    fclose(F);
    return C;
}

/*

    DISPLAY DATA FROM NEWLY READ (city)LINKEDLIST

*/
void displayCities(struct city *head)
{
    struct city *temp = head;
    printf("\n");
    dashes();
    printf("\n");
    print("A V A I L A B L E   C I T I E S");
    printf("\n");
    dashes();
    while (temp != NULL)
    {
        //printf("\n%s\n", temp->name);
        printf("\n");
        print(temp->name);
        printf("\n");
        temp = temp->next_city;
    }
}
void display(struct city *C)
{
    struct city *temp_c = (struct city *)malloc(sizeof(struct city));
    struct hotel *hotel_head = (struct hotel *)malloc(sizeof(struct hotel));
    hotel_head = NULL;
    temp_c = C;
    while (temp_c != NULL)
    {
        printf("\n\n%s\n", temp_c->name);
        hotel_head = temp_c->HOTELS;
        while (hotel_head != NULL)
        {
            printf("Name : %s \t Rooms: %d \t Price : %f\n\n", hotel_head->name, hotel_head->rooms, hotel_head->price);
            hotel_head = hotel_head->next_hotel;
        }
        temp_c = temp_c->next_city;
    }
}
char *choosecity(int n)
{
    if (n == 1)
    {
        char *city = (char *)malloc(40 * sizeof(char));
        printf("\nCHOOSE A CITY : ");
        scanf("%s", city);
        return city;
    }
    else if (n == 2)
    {
        char *hotel = (char *)malloc(50 * sizeof(char));
        printf("\nCHOOSE A HOTEL : ");
        scanf("%s", hotel);
        return hotel;
    }
    return "A";
}
float *makeBill(struct city *choosencity, char hotelname[], float *prt)
{
    struct hotel *hotelist = choosencity->HOTELS;
    char str[strlen(hotelname)];
    int i;
    int flag = 0;
    char startdate[12];
    char enddate[12];
    float number_of_days;
     for (i = 0; hotelname[i] != '\0'; i++)
    {
        str[i] = tolower(hotelname[i]);
    }
    str[i] = '\0';
    while (hotelist != NULL)
    {
         int j;
        char str_2[strlen(hotelist->name)];
        for (j = 0; hotelist->name[j] != '\0'; j++)
        {
            str_2[j] = tolower(hotelist->name[j]);
        }
        str_2[j] = '\0';
        if (!strcmp(str, str_2))
        {
            flag = 1;
            printf("\n\nEnter Arrival Date (dd/mm/yy) : ");
            scanf("%s", startdate);
            printf("\nEnter Departure Date (dd/mm/yy) : ");
            scanf("%s", enddate);
            number_of_days = numberofdays(startdate, enddate);
            prt[0] = number_of_days;
            prt[1] = ((hotelist->price) * number_of_days);
            return prt;
            // return ((hotelist->price) * number_of_days);
        }
        hotelist = hotelist->next_hotel;
    }
    if(flag != 0)
    { return prt;
    }
    else{
        return NULL;
    }
}

float *displayAcity(char cityname[], struct city *head, float *bill)
{
    struct city *temp = head;
    char str[strlen(cityname)];
    int i;
    int flag = 0;
    for (i = 0; cityname[i] != '\0'; i++)
    {
        str[i] = tolower(cityname[i]);
    }
    str[i] = '\0';
    while (temp != NULL)
    {
        int j;
        char str_2[strlen(temp->name)];
        for (j = 0; temp->name[j] != '\0'; j++)
        {
            str_2[j] = tolower(temp->name[j]);
        }
        str_2[j] = '\0';
        if (!strcmp(str, str_2))
        {
            flag = 1;
            break;
        }
        temp = temp->next_city;
    }
    if (flag == 1)
    {
        struct hotel *hotel_head = temp->HOTELS;
        SYSTEM();
        dashes();
        printf("\n");
        print(temp->name);
        printf("\n");
        dashes();
        int A = colsize() / 3;
        int B = A / 2;
        printf("%*s%*s|%*s%*s|%*s%*s", B, " ", -A + B, "NAME", B - 4, " ", -A + B, "ROOMS", B - 2, " ", -A + (B + 2), "PRICE");
        dashes();
        while (hotel_head != NULL)
        {
            int B_ = A / 2;
            int size_n = strlen(hotel_head->name);
            size_n -= 7;
            if (size_n >= 1)
            {
                B_ -= size_n;
            }
            printf("%*s%*s|%*s%*d|%*s%*.0f", B_, " ", -A + B_, hotel_head->name, B - 2, " ", -A + B + 2, hotel_head->rooms, B - 2, " ", -A + (B + 2), hotel_head->price);
            dashes();
            hotel_head = hotel_head->next_hotel;
        }
        return (makeBill(temp, choosecity(2), bill));
    }
    else{
        return NULL;
    }
}

/*

FOLLOWING FUNCTIONS ARE FOR 

1. READING DATA FROM USER
2. MAKING A LINKEDLIST WITH THAT
3. WRITING THAT INFO INTO A FILE

*/

/*

   WRITE CITY AND HOTEL INFO READ FROM USER
   TO FILE

*/
int isExists(FILE *file)
{
    if ((file = fopen(textfile, "r")))
    {
        return 1;
    }
    return 0;
}
void writeToFile(struct city *CITY)
{
    FILE *file;
    if (!isExists(file))
    {
        file = fopen(textfile, "w");
        fprintf(file, "%s,", CITY->name);
        struct hotel *temp = CITY->HOTELS;
        while (temp != NULL)
        {
            if ((temp->next_hotel) == NULL)
            {
                fprintf(file, "%s|%lf|%d,#", temp->name, temp->price, temp->rooms);
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
        file = fopen(textfile, "a");
        fprintf(file, "\n%s,", CITY->name);
        struct hotel *temp = CITY->HOTELS;
        while (temp != NULL)
        {
            if ((temp->next_hotel) == NULL)
            {
                fprintf(file, "%s|%lf|%d,#", temp->name, temp->price, temp->rooms);
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

/*

    ADD city AND hotel FROM USER TO LINKEDLIST

*/
void addhotel(struct city *C)
{
    struct hotel *Hotel_Head = (struct hotel *)malloc(sizeof(struct hotel));
    Hotel_Head = C->HOTELS;
    char hotelname[30];
    double hotelprice;
    int hotelrooms;
    //Reading the input
    printf("\nEnter the Hotel name\n");
    scanf("%s", hotelname);
    printf("\nEnter the hotel price\n");
    scanf("%lf", &hotelprice);
    printf("\nEnter the number of rooms\n");
    scanf("%d", &hotelrooms);

    struct hotel *temp = (struct hotel *)malloc(sizeof(struct hotel));

    strcpy(temp->name, hotelname);
    temp->rooms = hotelrooms;
    temp->price = hotelprice;

    //Check if list is empty
    if (Hotel_Head == NULL)
    {
        temp->next_hotel = NULL;
        Hotel_Head = temp;
    }
    else
    {
        temp->next_hotel = Hotel_Head;
        Hotel_Head = temp;
    }
    C->HOTELS = Hotel_Head;
}

/*
    ADD n HOTELS
*/
void addNhotels(struct city *C, int n)
{
    for (int i = 0; i < n; i++)
    {
        addhotel(C);
    }
}

struct city *addcity(struct city *City_Head_w)
{
    //Variable Declarations
    char cityname[30];
    int number_of_hotels;
    struct city *temp = (struct city *)malloc(sizeof(struct city));

    //Read input
    printf("\nEnter city name\n");
    scanf("%s", cityname);
    printf("\nHow many hotels in %s\n", cityname);
    scanf("%d", &number_of_hotels);

    strcpy(temp->name, cityname);

    temp->HOTELS = NULL;

    if (City_Head_w == NULL)
    {
        temp->next_city = NULL;
        City_Head_w = temp;
        addNhotels(temp, number_of_hotels);
    }
    else
    {
        temp->next_city = City_Head_w;
        City_Head_w = temp;
        addNhotels(temp, number_of_hotels);
    }
    return City_Head_w;
}
#endif