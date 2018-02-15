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
const int N = 2e5+5;

int n;
pii a[N], b[N];

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i].st);
    for (int i = 0; i < n; i++) scanf("%d", &b[i].st);
    for (int i = 0; i < n; i++) b[i].st *= -1, b[i].nd = i;
    sort(a, a+n);
    sort(b, b+n);
    for (int i = 0; i < n; i++) a[i].nd = b[i].nd;
    for (int i = 0; i < n; i++) swap(a[i].st, a[i].nd);
    sort(a, a+n);
    for (int i = 0; i < n; i++) printf("%d ", a[i].nd);
    printf("\n");
    return 0;
}
