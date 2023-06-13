#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

char cell[500][500];//matrica ot kletki sus simvoli
bool visited[500][500];//buleva matrica ot kletki za poseshtaemost
int X[4] = { 1, -1,  0, 0 }, Y[4] = { 0,  0, -1, 1 };//vsi4ki vuzmokni kombinacii ot koordinati za kvadrat

int N;//broj redove
int M;//broj stulbove
int startX;//koordinati na plo4kata koqto iskame da premestim(X)
int startY;//koordinati na plo4kata koqto iskame da premestim(Y)
int endX;//koordinati na "prazen" kvadrat(X)
int endY;//koordinati na "prazen" kvadrat(Y)

int beginX;//koordinati po X na kvadrata v kojto se namira plo4kata koqto shte mestim
int beginY;//koordinati po Y na kvadrata v kojto se namira plo4kata koqto shte mestim
int currentX, currentY; //koordinati na razglejdanata v momenta plo4ka

bool possible_movement;

bool INSIDE(int tempX , int tempY)//proverqva dali koordinatite na premestvane na plo4ka sa vuv matricata
{
    return tempX < N && tempY < M && tempX >= 0 && tempY >= 0;
}

void BFS(queue< pair < int, int> >& queue)
{
    while (!queue.empty())
    {
        pair < int, int > pair = queue.front();
        queue.pop();
        beginX = pair.first;
        beginY = pair.second;

        for (int i = 0; i < 4; i++)
        {
            currentX = beginX + X[i];
            currentY = beginY + Y[i];

            if (!INSIDE(currentX, currentY)) { continue; }//proverka dali koordinatite na premestvane shte budat vuv matricata

            if (visited[currentX][currentY]) { continue; }//proverka za ve4e poseten kvadrat

            visited[currentX][currentY] = true;

            if (cell[currentX][currentY] == '*') { continue; }//proverka za zaet kvadrat

            if (cell[currentX][currentY] == 'E') { possible_movement = true; return; }//proverka za prazen kvadrat

            queue.push(make_pair(currentX, currentY));
        }
    }
    possible_movement = false;
}

int main()
{
    int T;//broj testove
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        memset(cell, 0, sizeof(cell));
        memset(visited, 0, sizeof(visited));

        cin >> N >> M;

        for (int j = 0; j < N; j++)
        {
            cin >> cell[j];
        }

        cin >> startX >> startY >> endX >> endY;
        startX--, startY--, endX--, endY--;

        cell[endX][endY] = 'E';

        queue<pair <int, int > > queue;
        queue.push(make_pair(startX, startY));
        BFS(queue);

        if (possible_movement) { cout << "YES" << endl; }
        else { cout << "NO" << endl; }
    }
    return 0;
}