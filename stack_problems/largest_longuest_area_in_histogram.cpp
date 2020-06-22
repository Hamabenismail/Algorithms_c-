#include <iostream>
#include <stack>
#include <vector>
using namespace std;

long long maxRectArea(vector<int>h) {
int n = h.size();
vector<int> left(n,-1), right(n,n);
stack<int>st;
long long ans = 0;
for (int i = 0 ; i<n ;i++) {
while(!st.empty() && h[i] < h[st.top()]) {
    right[st.top()] = i ;
    st.pop();
}
st.push(i);
}

while(!st.empty())
    st.pop();
for (int i = n - 1 ; i >= 0 ; i --) {
    while(!st.empty() && h[i] < h[st.top()] ) {
        left[st.top()] = i;
        st.pop();
    }
    st.push(i);
}


for (int i = 0 ; i < n ; i++) {
ans = max(ans,h[i] * (right[i] - left[i] -1) * 1LL);
}
return ans ;
}

int main()
{

    vector<int> h  ;
    int input, n ;
    cin >> n;
    while (cin >> input){
        h.push_back(input);
    }
    cout<< maxRectArea(h);
    return 0;
}
