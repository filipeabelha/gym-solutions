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
#define gcd(x, y) __gcd((x), (y))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5+5;

ll n, m, k, x, ans;
vector <plll> v;
vector <ll> u;

int main () {
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &x);
        v.pb({{-x, i}, 0});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < m*k; i++) {
        ans -= v[i].st.st;
        v[i].nd = 1;
        swap(v[i].st.st, v[i].st.nd);
    }
    for (int i = m*k; i < n; i++) swap(v[i].st.st, v[i].st.nd);
    printf("%lld\n", ans);
    sort(v.begin(), v.end());
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        //printf("[%lld %lld %lld]\n", v[i].st.st, v[i].st.nd, v[i].nd);
        if (v[i].nd) cnt++;
        if (cnt == m) {
            cnt = 0;
            u.pb(v[i].st.st+1);
        }
    }
    u.pop_back();
    for (auto x : u) printf("%lld ", x);
    printf("\n");
    return 0;
}
