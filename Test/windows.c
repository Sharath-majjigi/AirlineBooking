#include <windows.h>
int main(int argc, char *argv[]) {
    /*
    csbi would give us info about the console screen
    */
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi); //Store console data into variable

    //Right pixel vs Left pixel would give us width
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1; 

    //Bottom pixel co ordinate - top pixel co ordinate would give us the height
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    printf("columns: %d\n", columns);
    printf("rows: %d\n", rows);
    return 0;
}