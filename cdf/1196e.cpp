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
const int N = 2e5+5;

int q, b, w;
set <pii> ba, wa, bq, wq;

int main () {
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &b, &w);
        int minxb = INF, minyb = INF;
        int minxw = INF, minyw = INF;
        wq.insert({1e5, 1e5});
        int ok = 1;
        while ((b or w) and wq.size()+bq.size() > 0) {
            if (w and wq.size()) {
                pii p = *wq.begin(); wq.erase(p);
                if (wa.count(p)) continue;
                int x = p.st;
                int y = p.nd;
                wq.erase({x, y});
                wa.insert({x, y});
                minxw = min(minxw, x);
                minyw = min(minyw, y);
                w--;
                bq.insert({x+1, y});
                bq.insert({x-1, y});
                bq.insert({x, y+1});
                bq.insert({x, y-1});
            }
            if (b and bq.size()) {
                pii p = *bq.begin(); bq.erase(p);
                if (ba.count(p)) continue;
                int x = p.st;
                int y = p.nd;
                ba.insert({x, y});
                minxb = min(minxb, x);
                minyb = min(minyb, y);
                b--;
                wq.insert({x+1, y});
                wq.insert({x-1, y});
                wq.insert({x, y+1});
                wq.insert({x, y-1});
            }
            if (!(w and wq.size()) and !(b and bq.size())) break;
        }
        if (!b and !w) {
            printf("YES\n");
            minxb--, minyb--;
            minxw--, minyw--;
            if (minxb&1) minxb--;
            if (minyb&1) minyb--;
            if (minxw&1) minxw--;
            if (minyw&1) minyw--;
            int minx = min(minxb, minxw);
            int miny = min(minyb, minyw);
            for (auto p : ba) printf("%d %d\n", p.st-minx, p.nd-miny);
            for (auto p : wa) printf("%d %d\n", p.st-minx, p.nd-miny);
        } else {
            printf("NO\n");
        }
        bq.clear();
        ba.clear();
        wq.clear();
        wa.clear();
    }
    return 0;
}
