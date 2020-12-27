#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  FINDS NUMBER OF DAYS BETWEEN 
  TWO DATES GIVEN INPUT IN INT 
  FORMAT
*/
int M[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int month(int, int);
int days(int y1, int y2, int m1, int m2, int d1, int d2)
{
  int i, count = 0;
  for (i = y1; i < y2; i++)
  {
    if (i % 4 == 0 || i % 400 == 0 || i % 100 != 0)
    {
      count += 366;
    }
    else
      count += 365;
  }
  count -= month(m1, y1);
  count -= d1;
  count += month(m2, y1);
  count += d2;
  if (count > 0)
    return count;
  return 0;
}

int month(int mn, int yr)
{
  int i, x = 0;
  for (i = 0; i < yr - 1; i++)
  {
    if (i == 1)
    {
      if (i % 4 == 0 || i % 400 == 0 || i % 100 != 0)
        x += 29;
      else
        x += 28;
    }
    else
      x += M[i];
  }
  return (x);
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
int main()
{
  char start[12],end[12];
  printf("\n\nENTER TWO DATES\n\nSTART DATE : ");
  scanf("%s",start);
  printf("\nEND DATE : ");
  scanf("%s",end);
  printf("NUMBER OF DAYS UNTIL %s : %d",end, numberofdays(start, end));
  //printf("\n%d",days(20,21,12,1,30,1));
  return 0;
}