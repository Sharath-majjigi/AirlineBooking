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
struct hotel* addHotel(struct hotel* Hotel_Head,char hotelname[100], double price, int rooms){
    struct hotel* temp = (struct hotel*)malloc(sizeof(struct hotel));
    strcpy(temp->name,hotelname);
    temp->price = price;
    temp->rooms = rooms;
    if(Hotel_Head == NULL){
        temp->next_hotel = NULL;
        Hotel_Head = temp; 
    }
    else{
        temp->next_hotel = Hotel_Head;
        Hotel_Head = temp;
    }
    return Hotel_Head;
}
struct city* addCity(struct city* Head,struct hotel *Hotel_Head, char cityname[]){
    struct city *temp = (struct city*)malloc(sizeof(struct city));
    strcpy(temp->name,cityname);
    if(Head == NULL){
        temp->next_city = NULL;
        temp->HOTELS = Hotel_Head;
        Head = temp;
    }
    else{
        temp->next_city = Head;
        temp->HOTELS = Hotel_Head;
        Head = temp;
    }
    return Head;
}
void readStruct(){
    City_Head = NULL;
    FILE *F;
    F = fopen("text.txt", "r");
    struct city *city_ptr = (struct city *)malloc(sizeof(struct city));
    char c, city_name[100],hotelname[40];
    double *price = (double *)malloc(sizeof(double));
    int *rooms = (int *)malloc(sizeof(int));
    while((c = fgetc(F)) != EOF){
        ungetc(c,F);
        extractCity(F,city_name);
        struct hotel* hotel_head = (struct hotel*)malloc(sizeof(struct hotel));
        hotel_head = NULL;
        while((c = fgetc(F)) != '#'){
            ungetc(c, F);
            extractHotel(F, hotelname, price, rooms);
            hotel_head = addHotel(hotel_head,hotelname, *price, *rooms);
        }
        City_Head = addCity(City_Head,hotel_head,city_name);
    }
    fclose(F);
}
void display(){
    struct city* temp_c = (struct city*)malloc(sizeof(struct city));
    struct hotel* hotel_head = (struct hotel*)malloc(sizeof(struct hotel));
    hotel_head = NULL;
    temp_c = City_Head;
    while(temp_c != NULL){
        printf("\n\n%s\n",temp_c->name);
        hotel_head = temp_c->HOTELS;
        while(hotel_head != NULL){
            printf("Name : %s \t Rooms: %d \t Price : %f\n\n",hotel_head->name,hotel_head->rooms,hotel_head->price);
            hotel_head = hotel_head->next_hotel;
        }
        temp_c = temp_c->next_city;
    }
}
int main()
{
    readStruct();
    display();
    return 0;
}