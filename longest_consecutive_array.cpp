#include <iostream>

using namespace std;
const int Nmax = 100001;
int longestConsecutiveArray(int a[], int n) {
bool frequencyArray[Nmax]; int maximum,minimum, result =0 ;

for (int i = 0 ; i < n ; i ++ ){

    for (int r = 0 ; r < n ; r++) {

        frequencyArray[a[r]] = false ;
    }
    minimum = a[i];
    maximum = a[i] ;

    for (int j = i ; j < n ; j++){

        if (frequencyArray[a[j]] == true) {
            break ;
        }
        frequencyArray[a[j]] = true ;

        minimum = min(minimum,a[j]);
        maximum = max(maximum,a[j]);
        if ( maximum - minimum  == j - i ) {
                cout << j,i ;
            result = max(result, j-i + 1 );
        }
    }
}
return result ;
}
int main()
{
   int a[Nmax], n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << longestConsecutiveArray(a,n);
    return 0;
}
