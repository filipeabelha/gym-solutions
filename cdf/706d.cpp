#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand(random_device{}());

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
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;
const int K = 40;

ll q, x;
char c;
multiset <ll> m[K];

/*void printbit (ll k) {
    string ans = "";
    printf("%3lld = ", k);
    while (k) {
        if (k&1) ans.pb('1');
        else ans.pb('0');
        k >>= 1;
    }
    while (ans.size() < 32) ans.pb('0');
    reverse(ans.begin(), ans.end());
    printf("%s\n", ans.c_str());
}*/

int main () {
    for (int i = 0; i < K; i++) {
        m[i].insert(0LL);
    }

    scanf("%lld", &q);
    while (q--) {
        scanf(" %c %lld", &c, &x);
        if (c == '+') {
            for (int i = 0; i < K; i++) {
                m[i].insert(x);
                x >>= 1;
            }
        }
        if (c == '-') {
            for (int i = 0; i < K; i++) {
                m[i].erase(m[i].find(x));
                x >>= 1;
            }
        }
        if (c == '?') {
            ll ans = 0;
            for (int i = K-1; i >= 0; i--) {
                ll b = ((x&(1ll << i)) > 0)^1;
                ans <<= 1;
                if (m[i].count(ans+b)) {
                    ans += b;
                } else ans += b^1;
            }
            printf("%lld\n", x^ans);
        }
    }
    return 0;
}
