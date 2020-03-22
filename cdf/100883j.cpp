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
const int N = 1e6+10;

int cmp[N];
vl pr;

void primes() {
    for (ll i = 2; i < N; i++) if (!cmp[i]) {
        for (ll j = i*i; j < N; j += i) cmp[j] = 1;
        pr.pb(i);
    }
}

bool isPrime (ll x) {
    if (x < 3) return false;
    for (int i = 0; pr[i]*pr[i] <= x; i++) {
        if (x % pr[i] == 0) return false;
    }
    return true;
}


string b (int x) {
    string ans = "";
    while (x) {
        ans.pb((x&1) + '0');
        x >>= 1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int d (string s) {
    reverse(s.begin(), s.end());
    int ans = 0;
    while (s.size()) {
        ans <<= 1;
        ans += s.back()-'0';
        s.pop_back();
    }
    return ans;
}

int pal (int x, int k) {
    string s = b(x);
    string t = s;
    reverse(t.begin(), t.end());
    char c = k + '0';
    if (k == 2) s = s+t;
    else s = s + c + t;

    return d(s);
}

vi v;
char sc[N];
string s;

int main () {
    primes();
    for (int i = 0; i < (1 << 11); i++) {
        for (int k = 0; k < 3; k++) {
            int x = pal(i, k);
            if (isPrime(x)) v.pb(x);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    while (~scanf("%s", sc)) {
        s = sc;
        printf("%s\n", b(*lower_bound(v.begin(), v.end(), d(s))).c_str());
    }

    return 0;
}
