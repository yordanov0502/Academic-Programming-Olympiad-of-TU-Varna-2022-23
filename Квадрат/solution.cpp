#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


int main() {
   
    int T;//broj testove
    cin >> T;
    int N;//razmer na mreja
    unsigned long long paths;//broj vuzmojni putishta
    for (int i = 0; i < T; i++)
    {
        paths = 1;
        cin >> N;

        for (int j = 0; j < N; j++)
        {
            paths *= ((2 * N) - j);
            paths /= (j + 1);
        }
        cout << paths << endl;
    }

    return 0;
}