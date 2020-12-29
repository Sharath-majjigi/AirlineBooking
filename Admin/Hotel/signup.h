#ifndef SIGNUP
#define SIGNUP
#include <stdio.h>
#include <string.h>
int signup(int whoareyou)
{
    FILE *f;
    char username[30], password[30];
    if ((fopen("signup.txt", "r")))
    {
        if (whoareyou == 1)
        {
            f = fopen("admin_db.txt", "a+");
            if (f != NULL)
            {
                printf("\nEnter your username\n");
                scanf("%s", username);
                fprintf(f, "%s\n", username);
                printf("\nEnter your password\n");
                scanf("%s", password);
                fprintf(f, "%s\n", password);
                fclose(f);
                return 1;
            }
            else
            {
                fclose(f);
                return 0;
            }
        }
        else if (whoareyou == 2)
        {
            f = fopen("user_db.txt", "a+");
            if (f != NULL)
            {
                printf("\nEnter your username\n");
                scanf("%s", username);
                fprintf(f, "%s\n", username);
                printf("\nEnter your password\n");
                scanf("%s", password);
                fprintf(f, "%s\n", password);
                fclose(f);
                return 1;
            }
            else
            {
                fclose(f);
                return 0;
            }
        }
    }
    else
    {

        if (whoareyou == 1)
        {
            f = fopen("admin_db.txt", "a+");
            if (f != NULL)
            {
                printf("\nEnter your username\n");
                scanf("%s", username);
                fprintf(f, "%s\n", username);
                printf("\nEnter your password\n");
                scanf("%s", password);
                fprintf(f, "%s\n", password);
                fclose(f);
                return 1;
            }
            else
            {
                fclose(f);
                return 0;
            }
        }
        else if (whoareyou == 2)
        {
            f = fopen("user_db.txt", "a+");
            if (f != NULL)
            {
                printf("\nEnter your username\n");
                scanf("%s", username);
                fprintf(f, "%s\n", username);
                printf("\nEnter your password\n");
                scanf("%s", password);
                fprintf(f, "%s\n", password);
                fclose(f);
                return 1;
            }
            else
            {
                fclose(f);
                return 0;
            }
        }
    }

    fclose(f);
    return 0;
}
#endif