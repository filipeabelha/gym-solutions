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
const int N = 2e5+5;

string s, t;
int v[N], invld[N];

bool slv (int x) {
    cl(invld, 0);
    for (int i = 1; i <= x; i++) invld[v[i]] = 1;

    int p = 1;
    for (int i = 1; i <= s.size(); i++) {
        if (!invld[i] and s[i-1] == t[p-1]) p++;
        if (p == t.size()+1) return true;
    }
    return false;
}

int main () {
    cin >> s >> t;
    for (int i = 1; i <= s.size(); i++) scanf("%d", &v[i]);

    int l = 0, m, r = s.size();

    while (l < r) {
        m = (l+r+1)/2;
        if (!slv(m)) r = m-1;
        else l = m;
    }
    m = (l+r+1)/2;

    printf("%d\n", m);

    return 0;
}
