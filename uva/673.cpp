#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int n;
char chr;
string s;

int main () {
    scanf("%d", &n);
    scanf("%c", &chr);
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        stack <int> st;
        int err = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '[') st.push(0);
            if (s[j] == '(') st.push(1);
            if (s[j] == ']') {
                if (st.empty() or st.top() != 0) {
                    err = 1;
                    break;
                }
                if (st.top() == 0)
                    st.pop();
            }
            if (s[j] == ')') {
                if (st.empty() or st.top() != 1) {
                    err = 1;
                    break;
                }
                if (st.top() == 1)
                    st.pop();
            }
        }
        if (!err and st.empty()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
