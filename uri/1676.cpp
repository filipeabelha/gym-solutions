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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e5+10;

int cmp[N], n;
vi p;

int main () {
    for (ll i = 2; i <= N; ++i) if (!cmp[i]) {
        int buf = 0;
        for (ll j = i+1; j <= N; j++) {
            if (!cmp[j]) buf++;
            if (buf == i) cmp[j] = 1, buf = 0;
        }
        p.pb(i);
    }
    while (1) {
        scanf("%d", &n); if (!n) break;
        printf("%d\n", p[n-1]);
    }
    return 0;
}
