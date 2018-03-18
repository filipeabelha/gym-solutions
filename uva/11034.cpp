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

int t, l, m, k, ans;
queue <int> q[2];
char ch[N];

void go (int i) {
    int s = 0;
    while (q[i].size() and s + q[i].front() <= l) {
        s += q[i].front();
        q[i].pop();
    }
    ans++;
}

int main () {
    scanf("%d", &t);
    while (t--) {
        ans = 0;
        scanf(" %d %d", &l, &m);
        l *= 100;
        while (m--) {
            scanf(" %d %s", &k, ch);
            if (ch[0] == 'l') q[0].push(k);
            else              q[1].push(k);
        }
        while (1) {
            if (q[0].size() or q[1].size()) go(0); else break;
            if (q[0].size() or q[1].size()) go(1); else break;
        }
        printf("%d\n", ans);
    }
    return 0;
}
