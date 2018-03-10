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

int n;
set <int> a, b;
int ans;

int main () {
    scanf("%d", &n);
    while (n >= 4) {
        a.insert(n);
        b.insert(n-1);
        b.insert(n-2);
        a.insert(n-3);
        n -= 4;
    }
    if (n == 3) a.insert(1), a.insert(2), b.insert(3);
    if (n == 2) a.insert(1), b.insert(2), ans--;
    if (n == 1) a.insert(1), ans++;
    printf("%d\n", abs(ans));
    printf("%d ", (int) a.size());
    for (auto x : a) printf("%d ", x);
    printf("\n");
    return 0;
}
