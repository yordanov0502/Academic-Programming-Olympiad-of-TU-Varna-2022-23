#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string word;
    int N;
   
    cin >> word;
    cin >> N;

    string front = word.substr(word.length() - N);
    string back = word.substr(0, word.length() - N);
    word = front + back;

    char c;
    for (int i = 0; i < word.length(); i++) 
    {
        c = word[i];
        c = (c - 'A' + N) % 26 + 'A';
        word[i] = c;
    }

    cout << word << endl;
    return 0;
}