#include<iostream>
using namespace std;

int main()
{
    int T;//broj testove
    cin >> T;

    int arr[1000000];
    int num;

    while(T--)
    {
        cin >> num;

        int k = 0;

        for (int i = 1; i <= num; i++)
        {
            int v = i + k;
            arr[i] = v % 10;
            k = v / 10;
        }

        int numRev = num;

        for (int i = num + 1; i <= 2 * num - 1; i++)
        {
            numRev--;
            int v = numRev + k;
            arr[i] = v % 10;
            k = v / 10;
        }

        for (int i = 2 * num - 1; i >= 1; i--)
        {
            cout << arr[i];
        }
        cout << endl;
    }
}