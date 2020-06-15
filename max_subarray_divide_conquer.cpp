#include <iostream>
#include <climits>
using namespace std;

int a[10];

int sumRight(int debut , int fin ) {
int sum = 0 ,maxSum = -300 ;
for (int i = debut  ; i<= fin ; i++ ) {
        sum += a[i];
        maxSum = max (maxSum , sum);
}
return maxSum ;
}
int sumLeft(int debut , int fin ) {
int sum = 0 ,maxSum = a[fin] ;
for (int i = fin ; i>=debut  ; i-- ) {
        sum += a[i];
        maxSum = max (maxSum , sum);
}

return maxSum ;
}
int maxSubArray(int left ,int right) {

if (left == right){
    return a[left];
}
int mid = (left + right) / 2;
int ans = max (maxSubArray(left,mid),maxSubArray(mid +1 , right));
return max(ans,(sumLeft(left,mid) + sumRight(mid + 1  , right)));
}
int main()
{
    int n ;
    cin >> n;
    for (int i = 1 ; i<= n ; i++) {
        cin >> a[i] ;
    }
     cout << maxSubArray(1,n);
    return 0;
}
