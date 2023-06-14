#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {

    int N;//broj stranici
    cin >> N;

    int C;//cifra
    cin >> C;
    string DIGIT = to_string(C);

    vector<int>v;
    int leftPage;

    while (cin >> leftPage)
    {
        v.push_back(leftPage);
    }

    string str_page;
    int counter = 0;
    for (int i = 1; i <= N; i++)
    {
        if (find(v.begin(), v.end(), i) != v.end()) continue;

        str_page = to_string(i);

        if (str_page.find(DIGIT) != string::npos && i == N && N % 2 != 0) { counter++; }

        else if (str_page.find(DIGIT) != string::npos && i == N && N % 2 == 0) { counter+=2; }

        else if (str_page.find(DIGIT) != string::npos && i == N-1 && find(v.begin(), v.end(), i+1) != v.end()) { counter++; }

        else if (str_page.find(DIGIT) != string::npos && i%2!=0) { i++; counter+=2; }

        else if (str_page.find(DIGIT) != string::npos && i%2==0) {  counter+=2; }
    }

    cout << counter << endl; 

    return 0;
}