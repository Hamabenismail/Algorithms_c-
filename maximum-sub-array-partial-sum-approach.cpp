#include <iostream>

using namespace std;
const int Nmax = 10001;
long long maxSubArrayWithPartialSum(int a[] , int n ) {
    if (n == 0)
        return 0 ;
long long s[n]  , result , minS = 0 ;
s[0] = a [0] ;
for (int i = 1 ; i < n ; i++ ) {
    s[i] = s[i-1] + a[i];
}
result = s[0] ;
for (int i = 0 ; i < n ; i ++ ) {
if  ( s[i] - minS > result) {
    result = s[i] - minS;
}
if (s[i] < minS) {
    minS = s[i] ;
}
}
return result ;
}

int main()
{

    int n, a[Nmax];
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << maxSubArrayWithPartialSum(a, n);
    return 0;
}
