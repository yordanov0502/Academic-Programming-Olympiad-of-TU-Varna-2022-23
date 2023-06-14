#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
   
    int T;
    cin >> T;

    while (T--)
    {
        unsigned int cars[1001];
        unsigned int visited[1001];
        memset(visited, 0, sizeof(visited));
        long long int minutes = 0;
        unsigned int carsQuantity;
        unsigned int i;

        cin >> carsQuantity;
        
        for (i = 0; i < carsQuantity; i++)
        {
            cin >> cars[i];
        }
            
        for (i = 0; i < carsQuantity; i++)
        {
            if (cars[i] != i && visited[i]==false)
            {
                int size = 0;
                int index = i;

                while (visited[index]==false)
                {
                    visited[index] = 1;
                    index = cars[index];
                    size++;
                }

                minutes=minutes+(size+1);
            }
        }
        
        //10 minuti sa nujni na Eli za premestvane na 1 kola
        if (cars[0] == 0) {cout << minutes * 10 << endl; }
        else {cout << (minutes-2) * 10 << endl;}
    }
    return 0;
}