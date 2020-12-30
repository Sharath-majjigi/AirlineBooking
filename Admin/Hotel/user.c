#include "hotel.h"
#include "signup.h"
#include "login.h"
#include <sys/ioctl.h>
#include <unistd.h>
#include "display.h"
int main()
{
    int choice_, didsignup = 0;
    char *didlogin = (char *)malloc(100 * sizeof(char));
    char choice, f;
loginagain:
    system("clear");
    dashes();
    print("L O G I N 🔑 ");
    dashes();
    didlogin = login(2, didlogin);
    if (didlogin)
    {
        system("clear");
        char welcome_message[200] = "Welcome ";
        strcat(welcome_message, didlogin);
        dashes();
        print(welcome_message);
        dashes();
    label2:
        printf("\n");
        print("1 > BOOK A HOTEL 🏨 ");
        printf("\n\n");
        print("2 > BOOK A FLIGHT 🛫");
        printf("\n\n\n");
        printf("%s", "YOUR CHOICE : ");
        scanf("%d", &choice_);
        if (choice_ == 1)
        {
            system("clear");
            struct city *head_2 = (struct city *)malloc(sizeof(struct city));
            head_2 = NULL;
            head_2 = readStruct(head_2);
            displayCities(head_2);
            displayAcity(choosecity(1), head_2);
            system("clear");
        }
        else if (choice_ == 2)
        {
            printf("\n\n W O R K  I N  P R O G R E S S\n\n");
        }
        else
        {
            printf("\n");
            print(" E R R O R ");
            printf("\n");
            char c;
            printf("\nGO BACK (Y/N) : ");
            scanf("%c", &c);
            scanf("%c", &c);
            if (c == 'Y' || c == 'y')
            {
                system("clear");
                goto label2;
            }
        }
    }
    else
    {
        printf("\n\nL O G I N  F A I L E D 😞\n\nDO YOU WANT TO SIGNUP ? 👀 (Y/N)\n\n");
        scanf("%c", &f);
        scanf("%c", &choice);
        if (choice == 'Y' || choice == 'y')
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