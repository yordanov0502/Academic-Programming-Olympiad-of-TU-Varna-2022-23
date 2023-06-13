#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int charVal(char c)
{
    if (c == 'I')
        return 1;
    if (c == 'V')
        return 5;
    if (c == 'X')
        return 10;
    if (c == 'L')
        return 50;
    if (c == 'C')
        return 100;
    if (c == 'D')
        return 500;
    if (c == 'M')
        return 1000;

    return -1;
}

bool compare(char x, char y)
{
    int val_x = charVal(x);
    int val_y = charVal(y);

    return (val_x < val_y);
}

string DecToRoman(int number)
{
   
    string res = "";

   
    int num[] = { 1, 4, 5, 9, 10, 40, 50,
                  90, 100, 400, 500, 900, 1000 };

    string sym[] = { "I", "IV", "V", "IX", "X", "XL", "L","XC", "C", "CD", "D", "CM", "M" };

    int i = 12;

  
    while (number > 0) 
    {
        int div = number / num[i];
        number = number % num[i];
        while (div--)
        {
            res += sym[i];
        }
        i--;
    }

    return res;
}

int main() {
   
    string r[3999];
    for (int i = 0; i < 3999; i++)
    {
        r[i] = DecToRoman(i);
    }

    string romanNumber;
    string r_temp;
    string romanNumber_temp;

    while (cin >> romanNumber)
    {
        
        romanNumber_temp = romanNumber;
        sort(romanNumber_temp.begin(), romanNumber_temp.end(), compare);

        for (int i = 0; i < 3999; i++)
        {
            r_temp = r[i];
            sort(r_temp.begin(), r_temp.end(), compare);

            if (romanNumber_temp == r_temp)
            {
                cout<<r[i]<<endl;
                break;
            }
        }
    }
    return 0;
}