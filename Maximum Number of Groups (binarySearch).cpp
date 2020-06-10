#include <iostream>

using namespace std;
const int Nmax = 100005;

bool isValid(int a[],int n, long long x , int k) {
long long ctn = 0;
for(int i = 1 ; i<=n ;i++) {
    ctn += min(x, 1LL * a[i]);
}
return ctn >= x * 1LL * k ;

}

long long sumOfMyArray(int a[],int n) {
long long sum = 0;
for (int i = 1 ; i<=n ; i++) {
    sum +=a[i];
}
return sum ;
}

int binarySearch(int a[],int n , int k) {
long long left = 0 , right = sumOfMyArray(a,n) , ans ;
while (left <= right ) {
        long long mid = (left + right) / 2;
    if (isValid(a,n,mid,k)){
        ans = mid;
        left = mid + 1;
    }
    else {
        right = mid - 1;
    }
}
return ans ;
}
int main()
{
    int n, k, a[Nmax];
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cout << binarySearch(a, n, k);
    return 0;
}
