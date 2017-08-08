#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, tc;

int main () {
    while (~scanf("%d", &n) and n and ++tc) {
        if (tc > 1) printf("\n");
        int cntinue = 1;
        while (1) {
            stack <int> st;
            int cnt = n;
            vi v;
            for (int x, i = 0; i < n; i++) {
                scanf("%d", &x);
                if (!x) {cntinue = 0; break;}
                v.pb(x);
            }
            if (!cntinue) break;
            reverse(v.begin(), v.end());
            for (auto x : v) {
                st.push(x);
                while (!st.empty() and st.top() == cnt) cnt--, st.pop();
            }
            if (cntinue) printf("%s\n", st.empty() ? "Yes" : "No");
        }
    }
    printf("\n");
    return 0;
}
