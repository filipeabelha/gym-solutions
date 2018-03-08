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
const int N = 5e5+5;

int n, v[N], u[N], ans;
int l, r;

void apply () {
    if (!l) return;
    if (!r) r = l;
    int cnt = 0;
    int a = v[l-1];
    int b = v[r+1];
    while (l <= r) {
        u[l] = a;
        u[r] = b;
        l++;
        r--;
        cnt++;
    }
    l = 0;
    r = 0;
    ans = max(ans, cnt);
}

void go() {
    u[1] = v[1];
    u[n] = v[n];
    l = 0;
    r = 0;
    for (int i = 2; i < n; i++) {
        if (v[i-1] != v[i] and v[i] != v[i+1]) {
            if (!l) l = i;
            else    r = i;
        } else {
            u[i] = v[i];
            apply();
        }
    }
    apply();
    for (int i = 1; i <= n; i++) v[i] = u[i];
}

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    go();
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
        printf("%d%c", v[i], " \n"[i==n]);
    }
    return 0;
}
