#include <climits>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long int calculateFactorial(int variable)
{
    long long int fact;

    switch (variable)
    {
    case 0:fact = 1; break;
    case 1:fact = 1; break;
    case 2:fact = 2; break;
    case 3:fact = 6; break;
    case 4:fact = 24; break;
    case 5:fact = 120; break;
    case 6:fact = 720; break;
    case 7:fact = 5040; break;
    case 8:fact = 40320; break;
    case 9:fact = 362880; break;
    case 10:fact = 3628800; break;
    case 11:fact = 39916800; break;
    case 12:fact = 479001600; break;
    case 13:fact = 6227020800; break;
    case 14:fact = 87178291200; break;
    case 15:fact = 1307674368000; break;
    case 16:fact = 20922789888000; break;
    case 17:fact = 355687428096000; break;
    case 18:fact = 6402373705728000; break;
    case 19:fact = 121645100408832000; break;
    case 20:fact = 2432902008176640000; break;
    }
    return fact;
}

//smqta kombinacii bez povtoreniq
long long int calculateCombinations(long long int n, long long int k, long long int n_k)
{
    return n / (k * n_k);
}

int main() {
 
    int T;//broj testove
    cin >> T;

    int P;//broj pokupki
    int B;//broj podaru4ni hartii

    int X;//razli4ni vidove pokupki
    int Y;//razli4ni vidove hartii

    long long int n1, k1, n1_k1, result1, n2, k2, n2_k2, result2, answer;

    while (T--)
    {
        
        cin >> P >> B >> X >> Y;
        n1 = calculateFactorial(X);
        k1 = calculateFactorial(P);
        n1_k1 = calculateFactorial(X - P);
        result1 = calculateCombinations(n1, k1, n1_k1);
        
        n2 = calculateFactorial(Y);
        k2 = calculateFactorial(B);
        n2_k2 = calculateFactorial(Y - B);
        result2 = calculateCombinations(n2, k2, n2_k2);

        answer = result1 * result2;
        cout << answer << endl;

        
    }
    return 0;
}