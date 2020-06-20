#include <iostream>
#include<stack>

int a[11], ans[10];
using namespace std;

void first_greater_element(int n) {
stack<int> st ;
for (int i = 1 ;i <= n ; i++) {
    while (!st.empty() && a[st.top()] < a[i]) {
        ans[st.top()] = i;
        st.pop();
    }
    st.push(i);


}
}
int main()
{
    int n ;
    cin >> n ;
    for (int i = 1 ; i <= n ; i++ ) {
        cin >> a[i] ;
    }
    first_greater_element(n);
    for (int i = 1 ; i <= n ; i++) {
        cout << ans[i];
    }

    return 0;
}
