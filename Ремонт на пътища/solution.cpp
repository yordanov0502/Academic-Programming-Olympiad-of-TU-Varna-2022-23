#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#define time temp

using namespace std;

const int SIZE = 2048;

vector < int > v[SIZE];
bool used[SIZE];
int parent[SIZE];
int low[SIZE], current_time, time[SIZE];
vector < pair < int, int > > answer;

void dfs(int node) 
{
    used[node] = true;
    time[node] = ++current_time;
    low[node] = current_time;
    int i;

    for (i = 0; i < (int)(v[node].size()); i++) 
    {
        if (!used[v[node][i]]) 
        {
            parent[v[node][i]] = node;
            dfs(v[node][i]);
            low[node] = min(low[node], low[v[node][i]]);

            if (low[v[node][i]] > time[node]) 
            {
                answer.push_back(make_pair(min(node, v[node][i]), max(node, v[node][i])));
            }
        }
        else if (v[node][i] != parent[node]) 
        {
            low[node] = min(low[node], time[v[node][i]]);
        }
    }
}

int main() {
  
    int T;//broj testove
    cin>>T;

    int N; //broj krastovishta
    int M; //broj ulici

    int  from; 
    int to;

    for (int i = 0; i < T; i++) 
    {
       
        cin >> N >> M;
        for (int j = 1; j <= N; j++)
        {
            v[j].clear();
        }

        for (int j = 1; j <= M ; j++) 
        {
            cin >> from >> to;
            v[from].push_back(to);
            v[to].push_back(from);
        }

        memset(used, 0, sizeof(used));
        memset(parent, 0, sizeof(parent));
        current_time = 0;
        answer.clear();
        dfs(1);
        sort(answer.begin(), answer.end());

        for (int j = 0; j < (int)(answer.size()); j++)
        {
            cout << answer[j].first << " " << answer[j].second << endl;
        }
    }
    return 0;
}