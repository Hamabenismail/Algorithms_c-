#include <iostream>

using namespace std;
const int Nmax = 10001;
long long maximumSubArray(int a[], int n ) {

long long result = a[1], sum = a[0];
for (int i = 1 ; i <= n ; i ++ ) {
    if (sum > result) {
        result = sum ;
    }
    if (sum < 0 ) {
        sum = 0 ;
    }
    sum +=a[i] ;
}
return result ;
}
int main()
{
     int n, a[Nmax];
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cout << maximumSubArray(a, n);
    return 0;
}
