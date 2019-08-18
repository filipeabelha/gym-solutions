#include <bits/stdc++.h>
using namespace std;
 
string conv (char c) {
    string r = "";
    int x = c;
    while (x) {
        r.push_back(!(x&1)+'0');
        x >>= 1;
    }
    while (r.size() < 7) r.push_back('1');
    return r;
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    string s, ans = "";
 
    getline(cin, s);
    for (auto c : s) ans += conv(c);
 
    cout << ans << endl;
 
    return 0;
}
