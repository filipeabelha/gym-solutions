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

int n, x, y;
int aa, bb, cc;
stack <int> a;
queue <int> b;
priority_queue <int> c;


int main () {
    while (~scanf("%d", &n)) {
        aa = bb = cc = 1;
        while (a.size()) a.pop();
        while (b.size()) b.pop();
        while (c.size()) c.pop();

        while (n--) {
            scanf("%d%d", &x, &y);
            if (x == 1) {
                a.push(y);
                b.push(y);
                c.push(y);
            }
            if (x == 2) {
                if (a.empty() or a.top()   != y) aa = 0;
                if (b.empty() or b.front() != y) bb = 0;
                if (c.empty() or c.top()   != y) cc = 0;
                if (a.size()) a.pop();
                if (b.size()) b.pop();
                if (c.size()) c.pop();
            }
        }
        if (aa + bb + cc > 1) printf("not sure\n");
        else if (aa) printf("stack\n");
        else if (bb) printf("queue\n");
        else if (cc) printf("priority queue\n");
        else         printf("impossible\n");
    }
    return 0;
}
