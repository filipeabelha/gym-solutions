#include <bits/stdc++.h>
using namespace std;

string s, prnt, ans = "";

int main () {
    while (getline(cin, s)) {
        string su = s;
        transform(su.begin(), su.end(), su.begin(), ::toupper);
        if (su.compare(ans) > 0) {
            ans = su;
            prnt = s;
        }
    }
    cout << prnt << endl;
}
