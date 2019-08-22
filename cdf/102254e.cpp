#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 8e6+5;

int trie[N][27], n, sz = 1;
bool ok[N];
vector <string> ans;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    while (n--) {
        cin >> s;
        if (s.length() < 4) continue;
        int u = 0;
        for (auto c : s){
            if (!trie[u][c]) trie[u][c] = sz++;
            u = trie[u][c];
        }
        if (ok[u]) ans.pb(s);
        ok[u] = 1;
    }
    if (!ans.size()) cout << "SAFO\n";
    else {
        cout << ans.size() << "\n";
        for (auto s : ans)
            cout << s << "\n";
    }
    return 0;
}
