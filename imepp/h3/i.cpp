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

int n, cnt, fst, ans[20];

set <int> p;

void go (int num, int pos) {
    if (!p.count(ans[pos-1]+num)) return;
    for (int i = 1; i < pos; i++) if (ans[i] == num) return;
    ans[pos] = num;
    if (pos == n) {
        if (!p.count(ans[1]+ans[n])) return;
        for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i==n]);
        return;
    }
    for (int k = 1; k <= n; k++) go(k, pos+1);
}

int main () {
    p.insert(2);
    p.insert(3);
    p.insert(5);
    p.insert(7);
    p.insert(11);
    p.insert(13);
    p.insert(17);
    p.insert(19);
    p.insert(23);
    p.insert(29);
    p.insert(31);

    while (~scanf("%d", &n) and ++cnt) {
        if (fst) printf("\n");
        fst = 1;
        printf("Case %d:\n", cnt);

        if (n == 1) printf("1\n");
        else for (int k = 2; k <= n; k++) {
            cl(ans, 0);
            ans[1] = 1;
            go(k, 2);
        }
    }
    return 0;
}
