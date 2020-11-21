#include<stdio.h>
#include<stdlib.h>
//#include<sys/ioctl.h>
//#include<unistd.h>
#include<string.h>
struct hotel{
    char name[30];
    double price;
    int rooms;
    struct hotel* next_hotel;
};

struct city{
    char name[30];
    struct hotel* HOTELS;
    struct city* next_city;
};
struct city* City_Head;


int getwidth(){
    //struct winsize w;
    //ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return(200);
}

int formatting(int stringlenght, int width){
    stringlenght = stringlenght/2;
    width = width/2;
    return(width + stringlenght);
}

void printlongline(){
    for(int i = 0; i < getwidth(); i++){
            printf("-");
        }
        printf("\n");
}

void addhotel(struct city* C){
    struct hotel* Hotel_Head = (struct hotel*)malloc(sizeof(struct hotel));
    Hotel_Head = C->HOTELS;
    char hotelname[30];
    double hotelprice;
    int hotelrooms;
    printf("\nEnter the Hotel name\n");
    scanf("%s",hotelname);
    printf("\nEnter the hotel price\n");
    scanf("%lf",&hotelprice);
    printf("\nEnter the number of rooms\n");
    scanf("%d",&hotelrooms);
    struct hotel* temp = (struct hotel*)malloc(sizeof(struct hotel));
    strcpy(temp->name,hotelname);
    temp->rooms = hotelrooms;
    temp->price = hotelprice;
    if(Hotel_Head == NULL){
        temp->next_hotel = NULL;
        Hotel_Head = temp;
    }
    else{
        temp->next_hotel = Hotel_Head;
        Hotel_Head = temp;
    }
    C->HOTELS = Hotel_Head;
}

void addNhotels(struct city* C,int n){
    for(int i = 0; i < n; i++){
        addhotel(C);
    }
}
void addcity(){
    char cityname[30];
    int number_of_hotels;
    printf("\nEnter city name\n");
    scanf("%s",cityname);
    printf("\nHow many hotels in %s\n",cityname);
    scanf("%d",&number_of_hotels);
    struct city* temp = (struct city*)malloc(sizeof(struct city));
    strcpy(temp->name,cityname);
    temp->HOTELS = NULL;
    if(City_Head == NULL){
        temp->next_city = NULL;
        City_Head = temp;
        addNhotels(temp, number_of_hotels);
    }
    else{
        temp->next_city = City_Head;
        City_Head = temp;
        addNhotels(temp, number_of_hotels);
    }
}

void displayhotels(struct city* C,int city_name_length){
    struct hotel* Head = (struct hotel*)malloc(sizeof(struct hotel));
    Head = C->HOTELS;
    struct hotel* temp = (struct hotel*)malloc(sizeof(struct hotel));
    temp = Head;
    int space = -city_name_length;
    int space2 = getwidth() + space;
    space2 /= -2;
    int space3 = space -(space2) + strlen("HOTEL NAME");
    space += -(space3);
    int linepsace = space + strlen("HOTEL NAME");
    linepsace /= 2;
    linepsace -= 1;
    //int newline = space3 + space - linepsace;
    int linespace2 = (space2 + strlen("ROOMS"))/2;
    //int newline2 = linepsace + space2 - linespace2;
    printf("%*s%*s%*s%*s%*s%*s\n",space3," ",space - linepsace,"HOTEL NAME",linepsace,"|",space2 - linespace2,"ROOMS",linespace2,"|", space2,"PRICE");
    printlongline();
    //printf("%*s%*s%s%s",-(newline - 1),"|",newline2 + 1, " ","|","\n");
    while(temp != NULL){
        printf("%*s%*s%*s%*d%*s%*.3lf\n",space3," ",space - linepsace,temp->name,linepsace,"|", space2 - linespace2, temp->rooms,linespace2,"|", space2, temp->price);
        // printf("%*s%*s%s%s",-(newline - 1),"|",newline2 + 1, " ","|","\n");
         printlongline();
        temp = temp->next_hotel;
    }
}

void displaycities(){
    struct city* temp = (struct city*)malloc(sizeof(struct city));
    temp = City_Head;
    int spaces = 0;
    while(temp != NULL){
        spaces = formatting(strlen(temp->name),getwidth());
        spaces = spaces;
        printf("\n");
        printlongline();
        printf("\n\n");
        printf("%*s\n\n",spaces,temp->name);
        printlongline();
        printf("\n");
        displayhotels(temp,formatting(strlen(temp->name),getwidth()) - strlen(temp->name));
        temp = temp->next_city;
        printf("\n\n");
    }
}
char choose[2];
void ask(char str[]){
    printf("\nDo you want to add a %s\n(Y/N)",str);
    scanf("%s",choose);
}


int main()
{
   
    City_Head = NULL;
    int n_;
    ask("city");
    while (choose[0] == 'Y')
    {
        addcity();
        ask("city");
    }
    displaycities();
    return 0;
}
