#include <iostream>

using namespace std;
int s[10][10];
void buildPartialSumMatrix(int  a[][10] ,int n, int m) {
    s[0][0] = a[0][0];
for (int i = 1 ; i <n ; i++) {
s[i][0] = s[i-1][0] + a[i][0];
}
for (int i = 1 ; i < m ; i++) {
    s[0][i] = s[0][i - 1] + a[0][i];
}
for (int i = 1 ; i < n ;i ++ ){
    for (int j = 1 ; j < m ; j++){
        s[i][j] = s[i-1][j] + s[i][j-1] + a[i][j] - s[i-1][j-1];
    }
}
}
long long sum (int l1,int c1, int l2, int c2){
    return (s[l2][c2] - s[l1-1][c2] - s[l2][c1-1] + s[l1-1][c1-1]);
}

int main()
{
    int a[10][10], n , m;
    cin >> n;
    cin >> m;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++) {
            cin >> a[i][j];
        }
    }
buildPartialSumMatrix(a,n,m);
  for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++) {
            cout<< s[i][j];
        }
    }

    return 0;
}
