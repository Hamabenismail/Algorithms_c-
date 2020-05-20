#include <iostream>

using namespace std;

int fastModularExpo(int a , long long n , int mod ) {
    if (n == 0) {
        return  1 ;
    }

    if (n % 2 ==0) {
        return fastModularExpo( (1LL * a * a) % mod, n/2, mod) ;
    }

    return (1LL * a * fastModularExpo(a,n-1,mod))% mod ;

}

int main()
{
  cout << fastModularExpo(2,10,100000007);
    return 0;
}
