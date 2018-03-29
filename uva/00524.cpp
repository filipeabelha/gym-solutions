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
const int N = 40;

bool isPrime (int x) {
    for (int i = 2; i < x; i++)
        if (x % i == 0) return false;
    return true;
}

set <int> p, used;
int n, cnt, ans[N];

void bk (int i) {
    if (i == n) {
        if (!isPrime(ans[1] + ans[n])) return;
        for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i==n]);
        return;
    }
    for (int j = 1; j <= n; j++) {
        if (used.count(j)) continue;
        if (!isPrime(j + ans[i])) continue;
        used.insert(j);
        ans[i+1] = j;
        bk(i+1);
        used.erase(j);
    }
}

int ok;

int main () {
    for (int i = 2; i < N; i++) if (isPrime(i)) p.insert(i);
    while (~scanf("%d", &n) and n and ++cnt) {
        if (ok) printf("\n");
        ok = 1;
        printf("Case %d:\n", cnt);
        used.insert(1);
        ans[1] = 1;
        bk(1);
    }
    return 0;
}
