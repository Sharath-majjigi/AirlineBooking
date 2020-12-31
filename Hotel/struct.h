/*
  @AUTHORS : 
    MUZAMMIL : https://github.com/DarthMuzammil 
*/
#ifndef STRUCT_H
#define STRUCT_H
struct hotel
{
    char name[30];
    double price;
    int rooms;
    struct hotel *next_hotel;
};

struct city
{
    char name[30];
    struct hotel *HOTELS;
    struct city *next_city;
};
struct city *City_Head;
#endif