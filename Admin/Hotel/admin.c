/*
  @AUTHORS : 
    MUZAMMIL : https://github.com/DarthMuzammil 
*/
#include "hotel.h"
#include <sys/ioctl.h> 
#include <unistd.h> 
int rowsize(){
struct winsize size;
ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
return size.ws_row;
}
int colsize(){
    struct winsize size;
    ioctl(STDOUT_FILENO,TIOCGWINSZ, &size);
    return size.ws_col;
}
void dashes(){
    printf("\n");
    for(int i = 0; i < colsize(); i++){
        printf("-");
    }
    printf("\n");
}
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
    writeToFile(head);
    head_2 = readStruct(head_2);
    display(head_2);
    return 0;
}