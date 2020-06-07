#include <iostream>

using namespace std;

int getValPosition(int a[],int n, int val) {
int left = 1 , right = n, index ;

while ( left <= right) {
        index = (left+right)/2 ;
        if (a[index] > val) {
            right = index -1 ;
        }else if (a[index] < val) {

            left = index + 1;
        }
        else {
            return index ;
        }

}

    return -1 ;
 }




int main()
{
    int a[100], n, val;
    cin >> n ;
    for (int i = 1 ; i<=n ; i++) {
     cin >> a[i];
    }
    cin >> val ;
    cout << getValPosition(a,n,val);
    return 0;
}
