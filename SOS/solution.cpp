#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



struct shipStruct //structura na veski rescue ship
{
    string name;
    int x;
    int y;
    int speed;
    double mintime;
} ;



double distance(int x1, int y1, int x2, int y2)
{
    // Calculating distance
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}



int main() {



   int T;//broj testove
    cin >> T;



   int wreckX, wreckY;//koordinati na razbitiq korab
    int rescueShips;



   double mintime;



   for (int i = 0; i < T; i++)
    {
        cin >> wreckX >> wreckY;



       cin >> rescueShips;
        shipStruct* ships = new shipStruct[rescueShips];



       for (int j = 0; j < rescueShips; j++)
        {
            cin >> ships[j].name >> ships[j].x >> ships[j].y >> ships[j].speed;



          ships[j].mintime=distance(wreckX,wreckY, ships[j].x, ships[j].y)/ ships[j].speed;



       }



       string name = ships[0].name;
        mintime = ships[0].mintime;
        for (int j = 1; j < rescueShips; j++)
        {
            if (ships[j].mintime < mintime)
            {
                mintime = ships[j].mintime;
                name = ships[j].name;
            }
        }
        cout << name<<endl;




        delete[] ships;
    }

}