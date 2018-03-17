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
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

multiset <int> l, u;

void adjust () {
    while (l.size() and l.size() < u.size()) {
        l.insert(*u.begin());
        u.erase(u.begin());
    }
    while (l.size() > u.size()+1) {
        u.insert(*l.rbegin());
        l.erase(--l.end());
    }
}

void add (int x) {
    if (l.empty() or x <= *l.rbegin()) l.insert(x);
    else u.insert(x);

    adjust();
}

int qry () {
    int v = *l.rbegin();
    if (!u.size()) return v;
    int w = *u.begin();
    return (l.size() == u.size()) ? (v+w)/2 : v;
}

int k;

int main () {
    while (~scanf("%d", &k)) {
        add(k);
        printf("%d\n", qry());
    }
    return 0;
}
