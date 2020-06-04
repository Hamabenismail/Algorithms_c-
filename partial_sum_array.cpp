#include <iostream>

using namespace std;
int s[100];
void buildPartialSums(int a[], int n) {
s[0] = a[0];
for (int i = 1 ; i< n ; i++) {
    s[i] = s[i-1] + a[i];
}
}

long long query(int x , int y) {
return s[y] - s[x -1 ];

}
int main()
{
int n , a[100];
cin >> n ;
for (int i = 0 ; i < n ; i++) {
    cin >> a[i];
}
buildPartialSums(a,n);
cout << query(2,5);
return 0;

}
