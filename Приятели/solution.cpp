#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 10000
int N;//broj jiteli
int M;//dvojki priqteli
int from, to;
int counter = 0;

void dfs(int startV, vector < vector < int > >& Graph, vector<bool>& viz) {

    viz[startV] = true;// markirame tekushtiq vruh kato obhoden
    counter++;

    // razglejdame vsi4ki negovi susedi
    for (long unsigned int i = 0; i < Graph[startV].size(); i++)
    {
        int toVisit = Graph[startV][i];

        if (!viz[toVisit])  // ako poredniq sused ne e bil poseshtavan
        {
            dfs(toVisit,Graph,viz); // recursion
        }
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;//broj testove
    cin >> T;

    int maxCitizens;

    while (T--)
    {
        vector < vector < int > > Graph(MAXN);
        vector<bool> viz;

        //n-broj vurhove, m - broj rebra
        cin >> N >> M;

        for (int i = 0; i < M; i++)
        {
            cin >> from;
            cin >> to;
            from--, to--;
            Graph[from].push_back(to);
            Graph[to].push_back(from); //if the graph is b-directional
        }

        viz.resize(N, false);
        maxCitizens = 0;
        for (int i = 0; i < N; i++)
        {
            if (!viz[i])
            {
                dfs(i, Graph,viz);
                if (maxCitizens < counter) { maxCitizens = counter; }
            }
            counter = 0;
        }
        cout << maxCitizens << endl;
    }
    return 0;
}