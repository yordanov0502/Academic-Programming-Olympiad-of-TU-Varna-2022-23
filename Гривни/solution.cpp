#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int calculate(int balls[]) {

    map<int, double> map =
    {
        {1,((double)balls[0] / 7) + ((double)balls[1] / 6) + ((double)balls[2] / 1)},
        {2,((double)balls[0] / 7) + ((double)balls[1] / 5) + ((double)balls[2] / 2)},
        {3,((double)balls[0] / 7) + ((double)balls[1] / 4) + ((double)balls[2] / 3)},
        {4,((double)balls[0] / 6) + ((double)balls[1] / 6) + ((double)balls[2] / 2)},
        {5,((double)balls[0] / 6) + ((double)balls[1] / 5) + ((double)balls[2] / 3)},
        {6,((double)balls[0] / 6) + ((double)balls[1] / 4) + ((double)balls[2] / 4)},
        {7,((double)balls[0] / 5) + ((double)balls[1] / 5) + ((double)balls[2] / 4)}
    };

    auto pr = std::max_element(map.begin(), map.end(), [](const auto& x, const auto& y) {
        return x.second < y.second;
        });


    //cout << "pt->second=" << pr->second;

    return pr->first;


}


int main() {

    int reds, yellows, blues, counter = 0;
    cin >> reds;
    cin >> yellows;
    cin >> blues;

    int balls[] = { reds,yellows,blues };
    int n;

    while (true)
    {
        if ((balls[0] + balls[1] + balls[2] < 14) || (balls[0] <= 0 || balls[1] <= 0 || balls[2] <= 0)) { break; }

        n = sizeof(balls) / sizeof(balls[0]);
        sort(balls, balls + n, greater<int>());



        int choice = calculate(balls);
        switch (choice)
        {
        case 1: {balls[0] -= 7; balls[1] -= 6; balls[2] -= 1; counter++; break; }
        case 2: {balls[0] -= 7; balls[1] -= 5; balls[2] -= 2; counter++; break; }
        case 3: {balls[0] -= 7; balls[1] -= 4; balls[2] -= 3; counter++; break; }
        case 4: {balls[0] -= 6; balls[1] -= 6; balls[2] -= 2; counter++; break; }
        case 5: {balls[0] -= 6; balls[1] -= 5; balls[2] -= 3; counter++; break; }
        case 6: {balls[0] -= 6; balls[1] -= 4; balls[2] -= 4; counter++; break; }
        case 7: {balls[0] -= 5; balls[1] -= 5; balls[2] -= 4; counter++; break; }

        default:
            break;
        }

    }



    cout << counter;
    return 0;
}