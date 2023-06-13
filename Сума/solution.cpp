#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int>& vec, int M)
{

    // Sort the array
    sort(vec.begin(), vec.end());

    // To store the closest sum
  //not using INT_MAX to avoid overflowing condition
    int closestSum = 1000000000;

    // Fix the smallest number among
    // the three integers
    for (int i = 0; i < vec.size() - 2; i++) {

        // Two pointers initially pointing at
        // the last and the element
        // next to the fixed element
        int ptr1 = i + 1, ptr2 = vec.size() - 1;

        // While there could be more pairs to check
        while (ptr1 < ptr2) {

            // Calculate the sum of the current triplet
            int sum = vec[i] + vec[ptr1] + vec[ptr2];

            // if sum is equal to M, return sum as
            if (sum == M)
                return sum;
            // If the sum is more closer than
            // the current closest sum
            if (abs(M - sum) < abs(M - closestSum) && sum<=M) {
                closestSum = sum;
            }

            // If sum is greater than M then decrement
            // the second pointer to get a smaller sum
            if (sum > M) {
                ptr2--;
            }

            // Else increment the first pointer
            // to get a larger sum
            else {
                ptr1++;
            }
        }
    }

    // Return the closest sum found
    return closestSum;
}

int main() {
    
    int N;//broj 4isla v redica
    int M;//grani4no 4islo
    int currNumber;
    vector<int> vec;
    

    while (true)
    {
        cin >> N >> M;

        if (N <= 3 || N >= 101) break;

        else
        {
            for (int i = 0; i < N; i++)
            {
                cin >> currNumber;
                vec.push_back(currNumber);
            }
            cout << solution(vec, M) << endl;
        }
        vec.clear();
    }
    return 0;
}