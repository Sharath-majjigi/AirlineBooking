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