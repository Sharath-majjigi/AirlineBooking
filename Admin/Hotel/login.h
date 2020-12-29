#ifndef LOGIN
#define LOGIN
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int login(int whoareyou)
{
    int flag = -1;
    FILE *f;
    if (whoareyou == 1)
    {
        if(!(fopen("admin_db.txt","r"))){
            printf("\n\n\nD A T A B A S E  E R R O R =(\n\n");
            flag = -1;
        }
        char username[30], password[30], buffer[40];
        int i, j;
        char str[100][30];
        char u[30], p[30];
        f = fopen("admin_db.txt", "r");
        printf("\nEnter your username\n");
        scanf("%s", u);
        printf("\nEnter your password\n");
        scanf("%s", p);
        if (f != NULL)
        {
            i = 0;
            while (fscanf(f, "%s", buffer) == 1)
            {
                strcpy(str[i], buffer);
                i++;
            }
            while (--i)
            {
                if (!(strcmp(u, str[i - 1])) && !(strcmp(p, str[i])))
                {
                    fclose(f);
                    return 1;
                }
            }
            if (i == 0)
            {
                flag = 0;
            }
        }
        else
        {
            flag = - 1;
        }
    }
    else
    {
        if(!fopen("user_db.txt", "r")){
            printf("\n\n\nD A T A B A S E  E R R O R =(\n\n");
        }
        char username[30], password[30], buffer[40];
        int i, j;
        char str[100][30];
        char u[30], p[30];
        f = fopen("user_db.txt", "r");
        printf("\nEnter your username\n");
        scanf("%s", u);
        printf("\nEnter your password\n");
        scanf("%s", p);
        if (f != NULL)
        {
            i = 0;
            while (fscanf(f, "%s", buffer) == 1)
            {
                strcpy(str[i], buffer);
                i++;
            }
            while (--i)
            {
                if (!(strcmp(u, str[i - 1])) && !((strcmp(p, str[i]))))
                {
                    fclose(f);
                    return 1;

                }
            }
            if (i == 0)
            {
                flag = 0;
            }
        }
        else
        {
            flag = -1;
        }
    }
    fclose(f);
    return flag;
}
#endif
