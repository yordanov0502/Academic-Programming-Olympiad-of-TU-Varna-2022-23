#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;//broj otse4ki
    cin >> n;

    int x1, y1, x2, y2;

    vector<double> nakloni;

    double currNaklon;

    for (int i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        if (y1 == y2) { currNaklon = 0; }
        if (isinf((double)(y2 - y1) / (double)(x2 - x1))) { currNaklon = -73.73737373; }
        else { currNaklon = (double)(y2 - y1) / (double)(x2 - x1); }
        
        if (currNaklon >= -90 && currNaklon <= 90)
        {
            if (count(nakloni.begin(), nakloni.end(), currNaklon)) {}
            else { nakloni.push_back(currNaklon); }
        }

    }
    cout << nakloni.size() << endl;

    return 0;
}
