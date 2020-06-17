#include <iostream>
#include<stack>
using namespace std;

int typeOf(char c) {
if (c == '(' || c == ')') return 0;
if (c == '{' || c == '}') return 1;
return 2;
}

bool isValidString(string s ) {
    stack<char> st ;
    for (int i = 0 ; i<s.size(); i++) {
        if (s[i] == '(' || s[i] == '{'|| s[i] == '[') {
            st.push(s[i]);
        }
        else {
            if (!st.empty() && typeOf(st.top()) == typeOf(s[i]))
                st.pop();
                else
                    return 0;
        }
    }
    return st.empty();
}
int main()
{
 string s ;
 cin >> s;
 cout << isValidString(s);

    return 0;
}
