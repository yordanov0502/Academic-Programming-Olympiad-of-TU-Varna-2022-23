#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iomanip>
#include<cstdlib>
using namespace std;

int main() {
    int i, j, k;
    int a;//nachalo na interval
    int b;//kraj na interval
    long long prime[1000001], sum[1000001], lp[1000001], primesCounter, s, mxd;
    cin >> a >> b;

    for (i = 2; i <= b; i++) 
    {
        if (lp[i] == 0) 
        {
            prime[++primesCounter] = i;
            sum[primesCounter] = sum[primesCounter - 1] + i;
            for (j = 2 * i; j <= b; j += i) 
            { 
                lp[j] = 1; 
            }
            if (sum[primesCounter] <= b) { mxd = primesCounter; }
        }
    }
    
    for (i = mxd; i >= 1; i--) 
    {
        for (j = 0; j <= primesCounter - i; j++) 
        {
            s = sum[j + i] - sum[j]; 
            if (s > b) { break; }
            
            if (lp[s] == 0 && s >= a && s <= b) 
            {
                cout << s << " " << i << endl;
                for (k = j + 1; k <= j + i; k++)
                {
                    cout << prime[k] << " ";
                } 
                cout << endl; 
                exit(0);
            }
        }
    }
    cout << "no prime" << endl;
    return 0;
}