#include <bits/stdc++.h>
using namespace std;

int n;
int na, nb, nc;
int a, b, c;
int ans, cur;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;

    for (auto ch : s) {
        na += (ch == 'A');
        nb += (ch == 'B');
        nc += (ch == 'C');
    }

    a = 0;
    b = a+na;
    c = b+nb;

    for (int i = a; i < a+na; i++) if (s[i] != 'A') cur++;
    for (int i = b; i < b+nb; i++) if (s[i] != 'B') cur++;
    for (int i = c; i < c+nc; i++) if (s[i] != 'C') cur++;

    ans = cur;

    while (1) {
        cur -= (s[a] != 'A');
        cur += (s[a] != 'C');

        cur -= (s[b] != 'B');
        cur += (s[b] != 'A');

        cur -= (s[c] != 'C');
        cur += (s[c] != 'B');

        ans = min(ans, cur);

        if (a+1 == n) break;
        a = (a+1)%n;
        b = (b+1)%n;
        c = (c+1)%n;
    }

    cur = 0;

    a = 0;
    c = a+na;
    b = c+nc;

    for (int i = a; i < a+na; i++) if (s[i] != 'A') cur++;
    for (int i = c; i < c+nc; i++) if (s[i] != 'C') cur++;
    for (int i = b; i < b+nb; i++) if (s[i] != 'B') cur++;

    ans = min(ans, cur);

    while (1) {
        cur -= (s[a] != 'A');
        cur += (s[a] != 'B');

        cur -= (s[c] != 'C');
        cur += (s[c] != 'A');

        cur -= (s[b] != 'B');
        cur += (s[b] != 'C');

        ans = min(ans, cur);

        if (a+1 == n) break;
        a = (a+1)%n;
        c = (c+1)%n;
        b = (b+1)%n;
    }

    cout << ans << endl;

}
