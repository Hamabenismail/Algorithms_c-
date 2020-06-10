#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid (vector <pair <int , int > > points, int dist) {
int numberOfPairs = points.size() ;
int p = -1 , minY = 1000000, maxY = -1000000 ;

for (int j = 0; j<numberOfPairs ; j++) {
while (p + 1 < j && points[p].first - points[p+1].first >= dist){
    p++;
    minY = min(minY,points[p].second);
    maxY = max(maxY,points[p].second);
}
if (p!= -1 && abs(minY - points[j].second) >= dist) {
    return true ;
}
if (p!= -1 && abs(maxY - points[j].second) >= dist) {
    return true ;
}
}
return false ;
}

int bSearch(vector < pair <int ,int>> points){
int left = 0 , right = 1000000 , ans ;
sort(points.begin(), points.end());
while (left <= right) {
  int   mid = (left + right) /2 ;
    if (isValid(points,mid)) {
        ans = mid ;
        left = mid + 1;
    } else {
        right = mid -1 ;
    }
}
return ans ;
}

int main()
{
    int n ;
    vector <pair <int , int > > points;
    cin >> n ;
    for (int i =0 ; i< n; i++ ) {
        int x,y ;
        cin >> x >> y;
        points.push_back(make_pair(x,y));
    }
    cout << bSearch(points);
    return 0;
}
