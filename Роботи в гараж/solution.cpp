#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long A[101], B[101], C[101], D[101];//sekundi

int main() {
    unsigned long long T, N, M;
    cin >> T;//obshto vreme

    cin >> N;//broj roboti tip 1
    for (int i = 0; i < N; i++) 
    {
        cin >> A[i] >> B[i];
    }

    cin >> M;//broj roboti tip 2
    for (int i = 0; i < M; i++) 
    {
        cin >> C[i] >> D[i];
    }

    unsigned long long answer1 = 0, answer2 = 1;
    unsigned long long currTime = T / 2;
    unsigned long long minBorder = 0;
    unsigned long long maxBorder = T + 1;

    while (answer1 != answer2) 
    {
        answer1 = 0;
        answer2 = 0;
        for (int i = 0; i < N; i++) 
        {
            if (A[i] <= currTime) 
            {
                answer1 += 1 + (currTime - A[i]) / B[i];
            }
        }
        for (int i = 0; i < M; i++) 
        {
            if (C[i] <= (T - currTime)) 
            {
                answer2 += 1 + ((T - currTime) - C[i]) / D[i];
            }
        }
        
        if (answer1 == answer2) 
        {
            if (answer1 == 0) 
            {
                cout << T << endl;
                return 0;
            }
            cout << currTime << endl;
            return 0;
        }
        else 
        {
            if (answer1 < answer2) 
            {
                minBorder = currTime;
            }
            else 
            {
                maxBorder = currTime;
            }
            if (currTime == (maxBorder + minBorder) / 2) 
            {
                cout << currTime << endl;
                return 0;
            }
        }
        currTime = (minBorder + maxBorder) / 2;
    }

    return 0;
}