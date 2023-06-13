#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<algorithm>

using namespace std;

string sentence, word;
int arr[150][150], length, used[150],  n, answer;
queue<int> q;


void BFS()
{
    q.push(0);
    used[0] = -2;

    for (; !q.empty();)
    {
        int x = q.front();
        q.pop();

        if (x == length) break;

        for (int i = x + 1; i <= length; i++)
        {
            if (arr[x][i] == 1 && used[i] == -1)
            {
                used[i] = x;
                q.push(i);
            }
        }
    }
}

int main()
{
    cin >> sentence; //input of string (sentece)
    length = sentence.size(); //length of whole string a.k.a sentence

    for (int i = 0; i <= length; i++)
    {
        used[i] = -1;
    }
    
        cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> word;
        int k = word.size(); //length of word

        for (int j = 0; j <= length - k; j++)
        {
            if (sentence.substr(j, k) == word)
                arr[j][j + k] = 1;
        }
    }

    BFS();

    int x = length;
    while (used[x] != 0)
    {
        x = used[x];
        sentence.insert(x, " ");
        answer++;
    }
    cout << answer + 1 << endl;
    cout << sentence << endl;

    return 0;
}