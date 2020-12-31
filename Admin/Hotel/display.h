#ifndef DISPLAY
#define DISPLAY
#include <stdio.h>
#include <string.h>
#if __APPLE__
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
void print(char string[])
{
    printf("%*s", (int)(colsize() / 2 + strlen(string) / 2), string);
}
void SYSTEM(){
    system("clear");
}
#endif
#elif _WIN32
#include <windows.h>
#include<conio.h>
void SYSTEM(){
    clrscr();
}
int rowsize()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    return rows;
}
int colsize()
{
     CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1; 
    return coloumns;
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
void print(char string[])
{
    printf("%*s", (int)(colsize() / 2 + strlen(string) / 2), string);
}
#elif _WIN64
#include <windows.h>
#include<conio.h>
void SYSTEM(){
    clrscr();
}
int rowsize()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    return rows;
}
int colsize()
{
     CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1; 
    return coloumns;
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
void print(char string[])
{
    printf("%*s", (int)(colsize() / 2 + strlen(string) / 2), string);
}
#endif