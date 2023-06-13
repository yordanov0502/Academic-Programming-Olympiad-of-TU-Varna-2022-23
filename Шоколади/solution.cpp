#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int T; cin >> T;//broj testove

    int P; //cena za 1 shokolad
    int K; //broj stanioli za 1 shokolad
    int N; //moite pari

    int chocolates;
    int moiteStanioli;

    int noviStanioli;

    for (int i = 0; i < T; i++) 
    {
        chocolates = 0;
        moiteStanioli = 0;
        noviStanioli = 0;
        cin >> P >> K >> N;



        while (true)
        {
            

            if (N < P)
            {
                if (moiteStanioli < K) { break; }

     else if (moiteStanioli % K == 0) { noviStanioli = moiteStanioli / K; chocolates += noviStanioli;  moiteStanioli = 0; moiteStanioli += noviStanioli; }

     else if (moiteStanioli % K != 0 && moiteStanioli > K) { moiteStanioli = moiteStanioli - K; chocolates++; moiteStanioli++; }

            }

            else if (N % P == 0) { chocolates += N / P;  moiteStanioli += chocolates; N = 0; }

            else if (N % P != 0) { chocolates += N / P; moiteStanioli += chocolates; N -= P*(N / P); }
            

        }

        cout << chocolates  << endl;
    }

    return 0;
}