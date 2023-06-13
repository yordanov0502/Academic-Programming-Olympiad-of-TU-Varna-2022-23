#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long calc(int n) 
{
    long long result = 1;
    for (int i = 2; i <= n; i++) 
    {
        result *= i;
    }
    return result;
}


int main() {
    int T,S;
    long long X;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> S >> X;

        vector<char> vChars(S);
        for (int j = 0; j < S; j++) 
        {
            vChars[j] = 'a' + j;
        }

        string answer(S, 'a');
        for (int j = 0; j < S; j++) 
        {
            int index = (X - 1) / calc(S - j - 1);
            answer[j] = vChars[index];
            vChars.erase(vChars.begin() + index);
            X -= index * calc(S - j - 1);
        }
        cout << answer << endl;
    }
    return 0;
}