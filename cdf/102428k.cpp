#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 1e5+5;
typedef long double ld;
typedef long long ll;
typedef vector <ll> vll;

vll roots;

string s;
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int degree = 0;
    cin >> s;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i-1]) {
            degree++;
            roots.pb(2*i+1);
        }
    }
 
    cout << degree << "\n";

    vll ans;
    if (roots.size()) {
        ans.pb(-roots[0]);
        ans.pb(1);
    }
    for (int i = 1; i < roots.size(); i++) {
        ans.pb(ans.back());
        for (int j = ans.size()-2; j >= 0; j--) {
            ans[j] = -roots[i]*ans[j];
            if (j) ans[j] += ans[j-1];
        }
    }

    reverse(ans.begin(), ans.end());

    if (ans.empty()) ans.pb(1);

    if (s.back() == 'H' and ans.size() and ans[0] < 0)
        for (auto& x : ans) x = -x;

    if (s.back() == 'A' and ans.size() and ans[0] > 0)
        for (auto& x : ans) x = -x;

    for (int i = 0; i < ans.size(); i++) 
        cout << ans[i] << " \n"[i+1==ans.size()];
 
    return 0;
 
}
