#include <iostream>
#include <queue>
using namespace std;
int dist[10][10],a[10][10], dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1} ;

int leesAlgo(pair<int,int> src, pair<int,int>dst) {
queue <pair<int,int>> q ;
dist[src.first][src.second] = 1;
q.push(src);
while (!q.empty()) {
    pair<int,int> cell;
    cell = q.front();
    if (cell == dst)
        return dist[cell.first][cell.second] - 1;
    q.pop();
    for (int i = 0 ; i< 4 ; i++) {
        if (a[cell.first + dx[i]][cell.second + dy[i]] == 1
            && dist[cell.first + dx[i]][cell.second + dy[i]] == 0
            ) {
                dist[cell.first + dx[i]][cell.second + dy[i]] = dist[cell.first][cell.second]++;
                q.push(make_pair(cell.first + dx[i],cell.second + dy[i]));
            }
    }
}
return -1;
}

int main()
{


    return 0;
}
