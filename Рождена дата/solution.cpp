#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct Date {
    int d, m, y;
};


const int monthDays[12]
= { 31, 28, 31, 30, 31, 30,
   31, 31, 30, 31, 30, 31 };


int countLeapYears(Date d)
{
    int years = d.y;

    if (d.m <= 2)
        years--;

    return years / 4
        - years / 100
        + years / 400;
}

int getDifference(Date dt1, Date dt2)
{
    long int n1 = dt1.y * 365 + dt1.d;

    for (int i = 0; i < dt1.m - 1; i++)
        n1 += monthDays[i];

    n1 += countLeapYears(dt1);


    long int n2 = dt2.y * 365 + dt2.d;
    for (int i = 0; i < dt2.m - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);

    return (n2 - n1);
}

bool isLeapYear(int year)
{
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) return true;
    else return false;
}

int main()
{
   
    int day, month, year;
    int currDay, currMonth, currYear;

    cin >> day >> month;
    cin >> currDay >> currMonth >> currYear;


    if (day == 29 && month == 2)
    {// year = currYear + 1; 

        if (currMonth < month) { year = currYear; }
        else if (currMonth == month && currDay < day) { year = currYear; }
        else if (currMonth == month && currDay == day) { year = currYear; }

        while (true)
        {
            if (isLeapYear(year)) break;
            else year++;
        }

    }
    else
    {
        if (currMonth < month) { year = currYear; }
        else if (currMonth == month && currDay < day) { year = currYear; }
        else if (currMonth == month && currDay == day) { year = currYear; }
        else { year = currYear + 1; }
    }
   

    Date dt1 = { currDay, currMonth, currYear };
    Date dt2 = { day,month, year };

    cout << getDifference(dt1, dt2);

    return 0;
}