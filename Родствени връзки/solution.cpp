#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <stdio.h>
#include <climits>
#include <cstring>
using namespace std;

vector <vector<int>> people;
vector <int> topology;
bool visited [10000];

void DFS(int from)
{
    visited[from] = true;//oznachavame vurha kato poseten

    for (unsigned long int i = 0; i < people[from].size(); i++)
    {
        if (!visited[people[from][i]])
        {
            DFS(people[from][i]);//rekursiq v dulbochina
        }
    }

    topology.push_back(from);//zapazvame nachalniq vruh pri izhod ot rekursiq
}


int main()
{
    int N;//chlenove na parlament
    int child;//dete

    while (true)
    {
        cin >> N;
        if (N == INT_MIN) { break; }

        else
        {
            if (N < 1) { break; }

            people.clear();
            people.resize(N);
            topology.clear();
            memset(visited, false, sizeof(visited));

            for (int i = 0; i < N; i++)
            {
                while (cin >> child && child != INT_MIN && child)
                {
                    people[i].push_back(child - 1);
                }
            }

            for (int i = 0; i < N; i++)
            {
                if (visited[i] == false) { DFS(i); }//obhojdame v dulbochina neposetenite vurhove
            }

            //izvejdame vurhovete otzad napred, tuj kato sa topologichno sortirani, no v obraten red (po uslovie)
            cout << topology[topology.size() - 1] + 1;
            for (int i = topology.size() - 2; i >= 0; i--)
            {
                cout << " " << topology[i] + 1;
            }
            cout << endl;
        }
    }
    return 0;
}