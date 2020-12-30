#ifndef DISPLAY
#define DISPLAY
#include<stdio.h>
#include<string.h>
#include <sys/ioctl.h>
#include <unistd.h>
int rowsize()
{
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    return size.ws_row;
}
int colsize()
{
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    return size.ws_col;
}
void dashes()
{
    printf("\n");
    for (int i = 0; i < colsize(); i++)
    {
        printf("-");
    }
    printf("\n");
}
void print(char string[]){
     printf("%*s", (int)(colsize() / 2 + strlen(string) / 2), string);
}
#endif