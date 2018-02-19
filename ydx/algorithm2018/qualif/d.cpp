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
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

ll n, q, x, l, r;
vector <pll> v;

bool isTriangle (ll a, ll b, ll c) {
    if (a >= b+c) return false;
    if (b >= a+c) return false;
    if (c >= a+b) return false;
    return true;
}

int main () {
    scanf("%lld%lld", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &x);
        v.pb(mp(x, i));
    }
    while (q--) {
        scanf("%lld%lld", &l, &r); l--; r--;
        ll k = min(l+90, r);

        sort(v.begin()+l, v.begin()+k+1);

        int ok = 0;
        for (int i = l+2; i <= k; i++)
            if (isTriangle(v[i-2].st, v[i-1].st, v[i].st)) {
                ok = 1;
                ll pr[] = {v[i-2].nd+1, v[i-1].nd+1, v[i].nd+1};
                sort(pr, pr+3);
                printf("%lld %lld %lld\n", pr[0], pr[1], pr[2]);
                break;
            }
        if (!ok) printf("-1\n");

        for (int i = l; i <= k; i++) swap(v[i].st, v[i].nd);
        sort(v.begin()+l, v.begin()+k+1);
        for (int i = l; i <= k; i++) swap(v[i].st, v[i].nd);
    }
    return 0;
}
