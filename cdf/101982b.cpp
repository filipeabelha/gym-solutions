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
typedef vector<ll> vl;
typedef vector<vl> vll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e7+10;

int mobius[N], notPrime[N];

void eval () {
    for (int i = 0; i < N; i++) mobius[i] = 1;
    for (int i = 2; i < N; i++) {
        if (!notPrime[i]) {
            mobius[i] = -mobius[i];
            for (int j = i+i; j < N; j += i){
                if (j % ((ll)i*i) == 0)
                    mobius[j] = 0;
                mobius[j] = -mobius[j];
                notPrime[j] = 1;
            }
        }
    }
}

ll upto (int a, int b) {
    ll ans = 0;
    for (int d = 1; d < N; d++) {
        ans += (ll) mobius[d]*(a/d)*(b/d);
    }
    return ans;
}

int main () {
    eval();

    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    ll ans = 0;
    ans = upto(b, d) - upto(b, c-1) - upto(a-1, d) + upto(a-1, c-1);
    printf("%lld\n", ans);



    return 0;
}
