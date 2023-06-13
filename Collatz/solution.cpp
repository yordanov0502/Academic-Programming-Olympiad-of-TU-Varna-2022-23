#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   
    int T;
    cin >> T;
    int N;

    for (int i = 0; i < T; i++)
    {
        cin >> N;
        if (N == 1) { cout << 1 << endl; }
        else if (N == 2) { cout << 2 << endl; }
        else { cout << 4 << endl; }
    }
    
    return 0;
}