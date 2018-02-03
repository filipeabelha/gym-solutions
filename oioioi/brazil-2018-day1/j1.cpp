#include <bits/stdc++.h>
using namespace std;

string s;
map <char, int> m;

int main () {
    cin >> s;
    for (auto x : s) m[x]++;
    if (m['K'] == m['P'] and m['K'] == m['N']) printf("1\n");
    else printf("0\n");
    return 0;
}
