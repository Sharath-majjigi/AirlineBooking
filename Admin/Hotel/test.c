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

int lenghtList(struct 
{
    /* data */
};
)
int isExists(FILE *file){
    if(file = fopen("text.txt","r")){
        return 1;
    }
    return 0;
}

void writeToFile(FILE *file,struct city* CITY, struct hotel* HOTEL){
    if(!isExists(file)){
        file = fopen("text.txt","w");
        fprintf(file,"%s\n",CITY->name);

    }
}
int main(){
    FILE *fp = fopen("h.txt","a");
    char *s = "hi";
    fprintf(fp,"%s",s);
    fclose(fp);
    return 0;
}
