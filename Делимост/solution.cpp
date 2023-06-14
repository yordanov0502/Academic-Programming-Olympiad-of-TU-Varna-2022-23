#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char chisl[104], chastno[104];
int delitel, ostatuk;
bool flag;

bool divide() 
{
    ostatuk = 0;
    for (int i = 0; i < strlen(chisl); ++i) 
    {
        ostatuk *= 10; 
        ostatuk += chisl[i] - '0';
        chastno[i] = ostatuk / delitel + '0';
        ostatuk = ostatuk % delitel;
    }
    chastno[strlen(chisl)] = '\0';
    return ostatuk == 0;
}

int main() 
{
    cin >> chisl;

    for (delitel = 2; delitel < 2001; ++delitel)
    {
        for (int i = 0; i < 104; ++i) 
        { 
            chastno[i] = 0; 
        }

        ostatuk = 0;

        if (divide()) 
        {
            cout << delitel << " ";
            flag = 0;

            for (int i = 0; i < strlen(chastno); ++i) 
            {
                if (chastno[i] != '0') { flag = 1; }
                if (flag) { cout << chastno[i]; }
            }
            cout << "\n";
        }
    }
    return 0;
}