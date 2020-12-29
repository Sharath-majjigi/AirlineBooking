#include "hotel.h"
#include "signup.h"
#include "login.h"
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
    int didsignup = 0, didlogin = 0;
    char choice, f;
    signup(2);
loginagain:
     dashes();
    printf("%*s",(int)(colsize()/2 + strlen("L O G I N 🔑 ")/2),"L O G I N 🔑 ");
    dashes();
    didlogin = login(2);
    if (didlogin)
    {
        struct city *head_2 = (struct city *)malloc(sizeof(struct city));
        head_2 = NULL;
        head_2 = readStruct(head_2);
        displayCities(head_2);
        displayAcity(choosecity(1), head_2);
    }
    else
    {
        printf("\n\nL O G I N  F A I L E D 😞\n\nDO YOU WANT TO SIGNUP ? 👀 (Y/N)\n\n");
        scanf("%c", &f);
        scanf("%c", &choice);
        if (choice == 'Y')
        {
            didsignup = signup(2);
            if (didsignup)
            {
                printf("\n\nSUCCESSFUL 🥳\n\n");
                goto loginagain;
            }
        }
    }
    return 0;
}