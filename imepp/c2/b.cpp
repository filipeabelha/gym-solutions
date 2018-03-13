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

multiset <int> l, u;

void adjust () {
    if (l.size() > u.size() + 1) {
        u.insert(*l.rbegin());
        l.erase(l.find(*l.rbegin()));
    } else if (u.size() > l.size()) {
        l.insert(*u.begin());
        u.erase(u.begin());
    }
}

void add (int x) {
    if (u.empty() or x < *u.begin()) l.insert(x);
    else                             u.insert(x);
    adjust();
}

void del (int x) {
    if      (l.count(x)) l.erase(l.find(x));
    else if (u.count(x)) u.erase(u.find(x));
    adjust();
}

int query () {
    if (u.size() > l.size()) return *u.begin();
    return *l.rbegin();
}


int tc, n;

int main () {
    scanf("%d", &tc);
    while (tc--) {
        l.clear();
        u.clear();
        while (scanf("%d", &n) and n) {
            if (n == -1) {
                printf("%d\n", query());
                del(query());
            } else add(n);
        }
    }
    return 0;
}
