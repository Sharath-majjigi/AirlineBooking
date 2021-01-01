/*
  @AUTHORS : 
    MUZAMMIL : https://github.com/DarthMuzammil 
*/
#include "hotel.h"
#include "display.h"
int main()
{
    struct city *head = (struct city *)malloc(sizeof(struct city));
    struct city *head_2 = (struct city *)malloc(sizeof(struct city));
    head_2 = NULL;
    head = NULL;
    dashes();
    printf("%*s",(int)(colsize()/2 + strlen("ADMIN PANEL")/2),"ADMIN PANEL");
    dashes();
    head = addcity(head);
    writeToFile(head,0);
    head_2 = readStruct(head_2);
    display(head_2);
    return 0;
}