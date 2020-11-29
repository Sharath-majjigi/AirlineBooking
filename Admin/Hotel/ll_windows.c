#include "imports.h"
/*
This function searches city name that if it is available is the list.
*/
struct city *choose_city(struct city *head, char city_name[50])
{
    struct city *city_ptr = head;
    while (city_ptr->next_city != NULL)
    {
        if (city_ptr->name == city_name)
            return city_ptr;
        city_ptr = city_ptr->next_city;
    }
    return NULL;
}

char choose[2]; //Global variable for Y/N input

/*
Function to ask whether user wants to continue

Takes string input str and displays :
" Do you want to add a (prinit str) "

*/
void ask(char str[])
{
    printf("\nDo you want to add a %s\n(Y/N)", str);
    scanf("%s", choose);
}

//Driver code
int main()
{
    City_Head = NULL;
    ask("city");
    while (choose[0] == 'Y')
    {
        addcity();
        ask("city");
    }
    displaycities();
    return 0;
}
