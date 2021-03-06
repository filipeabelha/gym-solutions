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

int ans[20];

int n;

int main () {
    scanf("%d", &n);
    for (int i = 0; i < 18; i++) {
        if (n) ans[i]++, n--;
    }
    for (int i = 0; i < 18; i++) {
        if (n) ans[i]++, n--;
    }
    if (n) printf("-1"); else
    for (int i = 0; i < 18; i++) {
        printf("%d", ans[i] == 2 ? 8 : ans[i] == 1 ? 9 : 7);
    }
    printf("\n");
    return 0;
}
