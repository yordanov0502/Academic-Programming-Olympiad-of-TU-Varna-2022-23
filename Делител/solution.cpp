#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int T;//broj testove
    cin >> T;

    string N;//chislo
    int zeroCounter;//broqch na nuli
    while (T--) 
    {   
        zeroCounter = 0;
        cin >> N;
        for (int i = N.size() - 1; i >= 0; i--)
        {
            if (N[i] == '0') zeroCounter++;
            else break;
        }
        cout << "1";
        if (zeroCounter > 0)
        {
            for (int i = 0; i < zeroCounter; i++)
                cout << "0";
        }
        cout << endl;
    }
    return 0;
}