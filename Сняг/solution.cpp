#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;//broj krastovishta
int m;//broj ulici
int component[2000];

int findComponent(int node) 
{
    if (node == component[node]) { return node; }

    else { return component[node] = findComponent(component[node]); }
}

int main() {

    int T; //broj testove
    int remaining;//ostavashti ulici za pochistvane
    int answer;
    int A;//nomer na krustovishte
    int B;//nomer na krustovishte
    int value1;
    int value2;
    cin >> T;

    while(T--)
    {
        cin >> n >> m;
        answer = 0, remaining = n;

        for (int i = 0; i < n; i++)
        {
            component[i] = i;
        }    

        for (int i = 0; i < m; i++) 
        {
            cin >> A >> B;

            if (remaining > 1) 
            {
                value1 = findComponent(A - 1);
                value2 = findComponent(B - 1);
                if (value1 != value2) 
                {
                    component[value2] = value1;
                    remaining--;
                }
                answer++;
            }
        }
        if (remaining > 1) { cout <<-1<<endl; }
        else { cout << answer; }
    }
    return 0;
}