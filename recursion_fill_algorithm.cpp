#include <iostream>

using namespace std;

int dx[4] = {1,0 , -1 , 0 } ,  dy[4] = {0,-1,0,1} ;
char a[10][10];
bool fr[10][10];


bool checkCell(int line , int column, int n , int m) {
    if (line < 1 || line > n || column < 1 || column > m) {
        return false ;
    }
    if (a[line][column] == '#' || fr[line][column]) {
        return false ;
    }
    return true ;
}
void fill (int line , int column ,int n , int m ,int& counter) {
fr[line][column] = true ;
counter ++ ;
for (int direct = 0 ; direct < 4 ; direct ++) {
    if (checkCell(dx[direct] + line , dy[direct] + column , n , m)) {
        fill (dx[direct] + line , dy[direct] + column, n ,m , counter ) ;
    }
}
}
int main()
{
    //we need counter of islands,
    // we need counter on line in the islands
    int n,m, islandsCounter = 0 , maxLineInIslands = 0;
    cin >> n >> m ;
    for (int i =1 ; i<=n ; i++) {
        for (int j=1 ; j<=m ; j++) {
            cin >> a[i][j];
        }
    }
     for (int i =1 ; i<=n ; i++) {
        for (int j=1 ; j<=m ; j++) {
            if (checkCell(i,j,n,m)) {
                islandsCounter++;
                int lineInIslands = 0 ;
                fill(i,j,n,m,lineInIslands);
                maxLineInIslands = max(maxLineInIslands,lineInIslands);
            }
        }
    }
    cout << islandsCounter << " " << maxLineInIslands;
    return 0;
}
