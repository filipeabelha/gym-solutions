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
const int N = 1e6+10;

int cmp[N];

int a, b, k;

void primes() {
    for (ll i = 2; i < N; i++) if (!cmp[i]) {
        for (ll j = i*i; j < N; j+=i) cmp[j]=1;
    }
}

bool ok (int l) {
    int ok = 1;
    int cnt = 0;
    for (int i = a; i < a+l; i++) {
        cnt += !cmp[i];
    }
    if (cnt < k) ok = 0;
    for (int i = a+l; i <= b; i++) {
        cnt -= !cmp[i-l];
        cnt += !cmp[i];
        if (cnt < k) ok = 0;
    }
    return ok;
}

int main () {
    primes();
    cmp[1] = 1;
    scanf("%d%d%d", &a, &b, &k);
    int l = 1, m, r = b-a+1;
    while (l < r) {
        m = (l+r)/2;
        if (!ok(m)) l = m+1;
        else r = m;
    }
    printf("%d\n", ok(l) ? l : -1);

    return 0;
}

