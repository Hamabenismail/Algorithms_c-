#include <iostream>
#include <stack>
using namespace std;

const int n = 4;
const int m = 4;

int maxHist(int row[], int m){
stack<int> st ;
int max_area = 0, area = 0, i = 0, top_val;
while (i < m) {
    if (st.empty() || row[st.top()] <= row[i]){
        st.push(i++);
    } else {
        top_val = row[st.top()];
        area = i * top_val;
        st.pop();
        if (!st.empty()) {
            area = top_val * (i - st.top() - 1);
        }
        max_area = max (area,max_area);
    }
}
while (!st.empty()) {
        top_val = row[st.top()];
        area = i * top_val;
        st.pop();
        if (!st.empty()) {
            area = top_val * (i - st.top() - 1);
        }
        max_area = max (area,max_area);
}
return max_area;
}

int maxRectangle(int a[][m], int m , int n) {

int result = maxHist(a[0],m);
for (int i = 1 ; i < n ; i++ ) {
    for (int j = 0 ; j < m ; j++) {
        if (a[i][j]) {
            a[i][j] += a[i - 1][j];
        }
    }
    result = max(result, maxHist(a[i],m));
}
return result ;
}
int main()
{

    int a[][m] = {
        { 0, 1, 1, 0 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 0, 0 },
    };

    cout << "Area of maximum rectangle is "
         << maxRectangle(a,m,n);

        return 0;
}
