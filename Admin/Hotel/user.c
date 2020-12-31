/*
  @AUTHORS : 
    MUZAMMIL : https://github.com/DarthMuzammil 
*/
#include "hotel.h"
#include "signup.h"
#include "login.h"
#include <time.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "display.h"
int main()
{
    int choice_, _choice, didsignup = 0;
    char *didlogin = (char *)malloc(100 * sizeof(char));
    char choice, f;
    label_4:
    SYSTEM();
    dashes();
    printf("\n");
    print("TRIP PLANNER");
    printf("\n");
    dashes();
    printf("\n");
    print("1 > L O G I N 🔑");
    printf("\n\n");
    print("  2 > S I G N  U P 📃");
    printf("\n\n\n");
    printf("%s", "YOUR CHOICE : ");
    scanf("%d", &_choice);
    if (_choice == 1)
    {
    loginagain:
        SYSTEM();
        dashes();
        printf("\n");
        print("L O G I N 🔑 ");
        printf("\n");
        dashes();
        didlogin = login(2, didlogin);
        if (didlogin)
        {
            SYSTEM();
            char welcome_message[200] = "Welcome ";
            strcat(welcome_message, didlogin);
            dashes();
            printf("\n");
            print(welcome_message);
            printf("\n");
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
            label_exit:
                SYSTEM();
                struct city *head_2 = (struct city *)malloc(sizeof(struct city));
                head_2 = NULL;
                head_2 = readStruct(head_2);
                displayCities(head_2);
                float *bill = (float *)malloc(2 * sizeof(float));
                if (displayAcity(choosecity(1), head_2, bill) != NULL)
                {
                    SYSTEM();
                    dashes();
                    printf("\n");
                    print("     B I L L 💰");
                    printf("\n");
                    dashes();
                    int a = ((int)strlen("STAY DURATION") - colsize() / 2) / 2;
                    int b = ((int)strlen("TOTAL AMOUNT") - colsize() / 2) / 2;
                    int c = ((int)strlen("USERNAME") - colsize() / 2) / 2;
                    int d = ((int)strlen(didlogin) - colsize() / 2) / 2;
                    printf("%*s%*s|", c, " ", -colsize() / 2 - c, "USERNAME");
                    printf("%*s%s", a, " ", didlogin);
                    dashes();
                    printf("%*s%*s|", a, " ", -colsize() / 2 - a, "STAY DURATION");
                    printf("%*s%.0f DAY(S)", a, " ", bill[0]);
                    dashes();
                    printf("%*s%*s|", b, " ", -colsize() / 2 - b, "TOTAL AMOUNT");
                    printf("%*s%.0f₹", a, " ", bill[1]);
                    dashes();
                }
                else
                {
                    SYSTEM();
                    dashes();
                    print("C I T Y   N O T   F O U N D ⛔️");
                    dashes();
                    printf("\n");
                    char response;
                    print("DO YOU WANT TO GO BACK (Y/N)");
                    printf("\n");
                    scanf("%c", &response);
                    scanf("%c", &response);
                    if (response == 'Y' || response == 'y')
                    {
                        goto label_exit;
                    }
                    else
                    {
                        exit(0);
                    }
                }
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
                    SYSTEM();
                    goto label2;
                }
            }
        }
        else
        {
            SYSTEM();
            dashes();
            print("L O G I N  F A I L E D 😞");
            dashes();
            printf("\nDO YOU WANT TO SIGNUP ? 👀 (Y/N)\n\n");
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
    }
    else if(_choice == 2){
        SYSTEM();
          dashes();
        printf("\n");
        print("S I G N  U P  📃");
        printf("\n");
        dashes();
        signup(2);
    }
    else{
        SYSTEM();
         dashes();
        printf("\n");
        print("I N V A L I D  O P E R A T I O N ⛔️");
        printf("\n");
        dashes();
        print("GO BACK HOME ?");
        printf("\n");
        printf("(Y/N) : ");
        scanf("%c", &f);
        scanf("%c", &choice);
        if(choice == 'y' || choice == 'Y')
            goto label_4;
        else
        {
                exit(0);
        }
        
    }
    return 0;
}