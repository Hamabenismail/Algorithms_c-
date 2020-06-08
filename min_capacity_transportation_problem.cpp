#include <iostream>

using namespace std;


long long sumOfMyArray(int a[],int n) {
long long sum = 0;
for (int i = 1 ; i <= n ; i++) {
    sum += a[i];
}
return sum ;

}

int maxValOfMyArray(int a[], int n) {
int maxVal = a[1];
for (int i=2 ; i<=n ;i++) {
    maxVal = max(maxVal,a[i]);
}
return maxVal ;

}

long long numOfRides(int a[],int n ,long long capacity) {
int rides = 1;
long long sum = 0 ;
for (int i = 1 ; i<= n ; i++) {
    if ((sum + a[i])<= capacity){
        sum+= a[i];
    } else {
        sum = a[i];
        rides++;
    }
}
return rides ;
}

long long bestCapacityWithBsearch(int a[],int n ,int k) {
long long left = maxValOfMyArray(a, n) , right = sumOfMyArray(a,n), ans;

while (left <= right){
    long long mid = ((left + right) / 2) ;
    if (numOfRides(a,n,mid) > k){
        left = mid + 1;
    } else {
        ans = mid ;
        right = mid - 1 ;
    }
}
return ans ;

}

int main()
{
    int a[10],n,k ;
    cin >> n >> k;
    for (int i = 1 ; i<=n ; i++) {
        cin >> a[i];
    }
    cout << bestCapacityWithBsearch(a,n,k);
    return 0;
}
