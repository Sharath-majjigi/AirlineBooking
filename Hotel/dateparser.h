#ifndef DATE
#define DATE
/*
  @AUTHORS : 
    PRITHVIRAJ : @githubusername 
    SHREYA : @githubusername 
    MUZAMMIL : https://github.com/DarthMuzammil 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  FINDS NUMBER OF DAYS BETWEEN 
  TWO DATES GIVEN INPUT IN INT 
  FORMAT
*/
int M[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int days(int y1, int y2, int m1, int m2, int d1, int d2)
{
    int day = 0, rem = 0;
    if (y1 == y2)
    {
        if (m1 == m2)
        {
            day = d2 - d1;
            return day;
        }
        if (y1 % 4 == 0 || y1 % 400 == 0 && y1 % 100 != 0)
        {
            M[1] = 29;
            return 0;
        }

        if (m2 > m1)
        {
            for (int i = m1; i < m2; i++)
            {
                day += M[i];
            }
            day += d2 - d1;
            return day;
        }
    }
    else if (y2 > y1)
    {
        if (y2 % 4 == 0 || y2 % 400 == 0 && y2 % 100 != 0)
        {
            M[1] = 29;
            return 0;
        }
        for (int i = 1; i < m1; i++)
        {
            rem += M[i];
        }
        rem += d1;
        day = 365 - rem;
        for (int i = 1; i < m2; i++)
        {
            day += M[i];
        }
        day += d2;
        return day;
    }
    return 0;
}

/* 
  PARSER : 
  CONVERTS STRING "DD/MM/YY" TO ARRAY OF STRINGS :
  string_ = ["dd","mm","yy"]
*/
char **parse(char stringp[])
{
  char **string_ = (char **)malloc(3 * sizeof(char *));
  string_[0] = (char *)malloc(4 * sizeof(char));
  string_[1] = (char *)malloc(4 * sizeof(char));
  string_[2] = (char *)malloc(4 * sizeof(char));
  int d = 0;
  int m = 0;
  int y = 0;
  for (int i = 0; stringp[i] != '\0'; i++)
  {
    if (i < 2 && stringp[i] != '/')
    {
      string_[0][i] = stringp[i];
    }
    else if (i >= 3 && i < 5 && stringp[i] != '\0')
    {
      string_[1][i - 3] = stringp[i];
    }
    else if (i >= 6)
    {
      string_[2][i - 6] = stringp[i];
    }
    if (i == 2 || i == 5)
    {
      string_[i % 2][2] = '\0';
    }
    else if (i == 7)
    {
      string_[2][2] = '\0';
    }
  }
  return string_;
}

/* 
    DRIVER FUNCTION FOR NUMBER OF DAYS 
    BETWEEN TWO GIVEN DATES OF STRING 
    TYPE IN FORMAT "DD/MM/YY"
*/
int numberofdays(char start[], char end[])
{
  return (
      days(
          atoi(parse(start)[2]), //atoi converts string to integer
          atoi(parse(end)[2]),
          atoi(parse(start)[1]),
          atoi(parse(end)[1]),
          atoi(parse(start)[0]),
          atoi(parse(end)[0])));
}
#endif