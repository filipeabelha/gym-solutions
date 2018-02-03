#include <bits/stdc++.h>
using namespace std;

#define vi vector <int>
#define ii pair <int, int>
#define vii vector <ii>
#define vvi vector <vi>
#define st first
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " << 
#define nd second
#define all(x) begin(x), end(x)
#define eb emplace_back
#define ll long long
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

ll n, v[20];
int m, lol;
vector <ll> ans;
map <ll, bool> ok;

int main() {
    scanf("%lld%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%lld", &v[i]);
        if (v[i] != 1) lol = 1;
        if (v[i] == 1) v[i] = n+1;
    }
    ans.pb(n);
    ok[n] = true;
    for (int i = 0; i < m; i++) {
        int sz = ans.size();
        for (int j = 0; j < sz; j++) {
            ll r = ans[j];
            while (r) {
                if (!ok[r]) {
                    ok[r] = true;
                    ans.pb(r);
                }
                r /= v[i];
            }
        }
    }
    printf("%d\n", (int)ans.size()+lol);

    return 0;
}
