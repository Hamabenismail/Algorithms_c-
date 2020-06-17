#include <iostream>

using namespace std;
int a[10][10];

int zTravelsal(int n , int x ,int y) {
if (n == 0)
    return 1;
if (x <= 1<<(n-1)){
    if (y<= 1<<(n-1))
        return zTravelsal(n-1,x,y);
  return (1<<(2*n-2) + zTravelsal(n-1,x,(y - 1<<(n-1))));
}
if (y <= 1<<(n-1)){
    return (  1<<(2*n-1) + zTravelsal(n-1,x - 1<<(n-1) ,y));
}
return ( (3 * 1<<(2*n-2))  + zTravelsal(n-1,x - 1<<(n-1),y - 1<<(n-1)));

}
int main()
{
    int n , x , y ;
    cin >> n >> x >> y;
    cout << zTravelsal(n,x,y);
    return 0;
}
