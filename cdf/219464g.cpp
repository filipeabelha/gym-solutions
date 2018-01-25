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
typedef pair<ll ,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n;
vector <pll> pts;
set <pll> s;
pll p;

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &p.st, &p.nd);
        pts.pb(p);
    }
    if (n < 4) {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < pts.size(); i++) {
        for (int j = i+1; j < pts.size(); j++) {
            pll p = mp(pts[i].st+pts[j].st, pts[i].nd+pts[j].nd);
            if (s.count(p)) {
                printf("1\n");
                return 0;
            }
            s.insert(p);        
        }
    }
    printf("2\n");
    return 0;
}
