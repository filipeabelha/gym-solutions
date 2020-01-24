#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n) {
        int ans = 0;
        int t = 0;
        int m = 0;
        int b = 0;
        while (n--) {
            cin >> s;

            string r = "";
            for (auto c : s) if (c == 'D' or c == 'R') r += c;

            for (int i = 1; i < r.size(); i++) {
                if (r[i] == 'R' and r[i-1] == 'D') ans++;
            }

            if (r.empty()) continue;

            if (r[0] == 'R' and r.back() == 'D') m++;
            else if (r[0] == 'R') b++;
            else if (r.back() == 'D') t++;
        }

        if (t > 0 and b > 0) {
            ans += m+1;
            t--;
            b--;
            m = 0;
            ans += min(t, b);
        } else if (t > 0 or b > 0) ans += m;
        else if (m) ans += m-1;

        cout << ans << "\n";
    }

}
