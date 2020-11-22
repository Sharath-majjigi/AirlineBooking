#include<stdio.h>
#include<stdlib.h>
#include<sys/ioctl.h>
#include<unistd.h>
#include<string.h>
struct flight{
    char source[30],dest[30];
    double price;
    int duration;
    struct flight* next_flight;
};

struct city{
    char name[30];
    struct flight* flightS;
    struct city* next_city;
};
struct city* City_Head;


int getwidth(){
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return(w.ws_col);
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

void addflight(struct city* C){
    struct flight* flight_Head = (struct flight*)malloc(sizeof(struct flight));
    flight_Head = C->flightS;
    char flightsource[30];
    char flightdest[30];
    double flightprice;
    int flightduration;
    printf("\nEnter the flight source\n");
    scanf("%s",flightsource);
    printf("\nEnter the flight destination\n");
    scanf("%s",flightdest);
    printf("\nEnter the flight price\n");
    scanf("%lf",&flightprice);
    printf("\nEnter the number of duration\n");
    scanf("%d",&flightduration);
    struct flight* temp = (struct flight*)malloc(sizeof(struct flight));
    strcpy(temp->source,flightsource);
     strcpy(temp->dest,flightdest);
    temp->duration = flightduration;
    temp->price = flightprice;
    if(flight_Head == NULL){
        temp->next_flight = NULL;
        flight_Head = temp;
    }
    else{
        temp->next_flight = flight_Head;
        flight_Head = temp;
    }
    C->flightS = flight_Head;
}

void addNflights(struct city* C,int n){
    for(int i = 0; i < n; i++){
        addflight(C);
    }
}
void addcity(){
    char cityname[30];
    int number_of_flights;
    printf("\nEnter city name\n");
    scanf("%s",cityname);
    printf("\nHow many flights in %s\n",cityname);
    scanf("%d",&number_of_flights);
    struct city* temp = (struct city*)malloc(sizeof(struct city));
    strcpy(temp->name,cityname);
    temp->flightS = NULL;
    if(City_Head == NULL){
        temp->next_city = NULL;
        City_Head = temp;
        addNflights(temp, number_of_flights);
    }
    else{
        temp->next_city = City_Head;
        City_Head = temp;
        addNflights(temp, number_of_flights);
    }
}

void displayflights(struct city* C,int city_name_length){
    char source_destination[90];
    struct flight* Head = (struct flight*)malloc(sizeof(struct flight));
    Head = C->flightS;
    struct flight* temp = (struct flight*)malloc(sizeof(struct flight));
    temp = Head;
    int space = -city_name_length;
    int space2 = getwidth() + space;
    space2 /= -2;
    int space3 = space -(space2) + strlen("FLIGHT NAME");
    space += -(space3);
    int linepsace = space + strlen("flight NAME");
    linepsace /= 2;
    linepsace -= 1;
    //int newline = space3 + space - linepsace;
    int linespace2 = (space2 + strlen("duration"))/2;
    //int newline2 = linepsace + space2 - linespace2;
    printf("%*s%*s%*s%*s%*s%*s\n",space3," ",space - linepsace,"FLIGHT NAME",linepsace,"|",space2 - linespace2,"duration",linespace2,"|", space2,"PRICE");
    printlongline();
    //printf("%*s%*s%s%s",-(newline - 1),"|",newline2 + 1, " ","|","\n");
    while(temp != NULL){
    strcat(source_destination,temp->source);
    strcat(source_destination ," to ");
    strcat(source_destination,temp->dest);
        printf("%*s%*s%*s%*d%*s%*.3lf\n",space3," ",space - linepsace,source_destination,linepsace,"|", space2 - linespace2, temp->duration,linespace2,"|", space2, temp->price);
        // printf("%*s%*s%s%s",-(newline - 1),"|",newline2 + 1, " ","|","\n");
         printlongline();
        temp = temp->next_flight;
    strcpy(source_destination,"");
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
        displayflights(temp,formatting(strlen(temp->name),getwidth()) - strlen(temp->name));
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
