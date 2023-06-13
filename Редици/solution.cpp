#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int main() {
    
    int T;//broj testove
    cin >> T;

    int X, N, Y;

    long long int arr[21][31];
    long long int temp;
    long long int answer;

    while (T--)
    {
        cin >> X >> N >> Y;

        for (int i = 1; i <= N; i++)
        {
            arr[i][0] = 1;
        }

        for (int j = 0; j < Y; j++)
        {  
            if (j < X) arr[1][j] = 1;
            else arr[1][j] = 0;
        }

        for (int i = 2; i <= N; i++)
        {
            for (int j = 1; j < Y; j++)
            {
                temp = 0;
                for (int k = 0; k < X; k++)
                {
                    if (j - k >= 0) { temp += arr[i - 1][j - k]; }
                }
                arr[i][j] = temp;
            }
        }

        answer = 0;
        for (int j = 0; j < Y; j++)
        {
            answer += arr[N][j];
        }
        cout << answer << endl;
        memset(arr, 0, sizeof(arr[0][0]) * 21 * 31); //po4istvane na masiv arr
    }
    return 0;
}