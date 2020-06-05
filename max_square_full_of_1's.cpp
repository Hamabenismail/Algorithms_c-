#include <iostream>

using namespace std;
const int Nmax = 1001;

bool a[Nmax][Nmax];
int n, m, maxLen[Nmax][Nmax];
int maxSizeSquare(bool a[][Nmax], int n, int m) {
    int ans = 0 ;
  for (int i = 1; i <=n ; i++) {
    for (int j = 1 ; j <=m ; j++) {
        if (a[i][j] == false ) {
            maxLen[i][j] = 0;
        } else {
            maxLen[i][j] = 1 + min(maxLen[i - 1][j], min(maxLen[i][j-1],maxLen[i-1][j-1]));
        }
        ans = max(ans,maxLen[i][j]);
    }
  }
  return ans ;
}


int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    cout << maxSizeSquare(a, n, m);
    return 0;
}
