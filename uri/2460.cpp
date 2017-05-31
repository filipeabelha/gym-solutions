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

vi v;
set <int> s;
int n, m, x, frst;

int main () {
    scanf("%d", &n); while (n--) scanf("%d", &x), v.pb(x);
    scanf("%d", &m); while (m--) scanf("%d", &x), s.insert(x);
    for (auto i : v) if (!s.count(i)) {
        printf("%s%d", frst ? " " : "", i);
        frst = 1;
    }
    printf("\n");
    return 0;
}
