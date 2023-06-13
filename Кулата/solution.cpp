#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int c[100004];//ceni na predmeti
int p[120000][4];//promocii

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;//broj predmeti
    int m;//broj promocii

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> p[i][0] >> p[i][1] >> p[i][2];
        c[p[i][0]] = min(c[p[i][0]], c[p[i][2]] + c[p[i][1]]);
    }

    for (int j = 0; j <= 10; j++) 
    {
        for (int i = 0; i < m; i++)
        {
            c[p[i][0]] = min(c[p[i][0]], c[p[i][2]] + c[p[i][1]]);
        }
    }
    
    cout << c[1] << endl;

    return 0;
}