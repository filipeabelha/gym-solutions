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
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 3e7;
const int N = 3e7+5;

int n, m, q, x;
int v[N], s[N];

int main () {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= m; i++)   scanf("%d", &v[i]),               s[v[i]]++;
    for (int i = m+1; i <= n; i++) v[i] = ((v[i-m]+v[i-m+1]) % MOD), s[v[i]]++;
    for (int i = 1; i <= N; i++) s[i] += s[i-1];

    while (q--) {
        scanf("%d", &x);

        int l, m, r;
        l = 0; r = N;
        while (l < r) {
            m = (l+r)/2;
            if (s[m] < x) l = m+1;
            else r = m;
        }
        m = (l+r)/2;
        printf("%d\n", m);
    }
    return 0;
}
