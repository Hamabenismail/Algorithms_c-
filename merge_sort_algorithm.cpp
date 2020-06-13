#include <iostream>

using namespace std;
int a[10], s[20];



void mergeArrays(int left , int mid , int right) {
int i = left , j = mid +1  , p = 1;
while(i<=mid && j<=right  ) {
    if (a[i] <= a[j]) {
        s[p++] = a[i++];
    }
    else {
        s[p++] = a[j++];
    }
}
while (i <=mid) {
    s[p++] = a[i++];
}
while (j<= right) {
    s[p++] = a[j++];
}
for (int k = left ; k <=  right ; k++) {
        cout << k ;
 a[k] = s[k-left + 1];
}
cout << "\n";
}

void mergeSort(int left , int right) {
if (left == right)
    return ;
int mid = (left + right) /2 ;
mergeSort(left,mid);
mergeSort(mid+1, right);
mergeArrays(left,mid,right);
}


int main()
{
    int n ;
    cin >> n ;
    for (int i = 1 ; i<=n ; i++) {
        cin>> a[i] ;
    }
    mergeSort(1,n);
       for (int i = 1 ; i<=n ; i++) {
        cout << a[i] ;
    }
    return 0;
}
