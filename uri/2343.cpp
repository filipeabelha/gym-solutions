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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;

int n, x, y, ok;
set <pii> s;

int main () {
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &x, &y);
        if (!s.count(mp(x,y))) s.insert(mp(x,y));
        else ok = 1;
    }
    printf("%d\n", ok);
    return 0;
}
