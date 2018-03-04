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

int a, b;
int y;

int main () {
    scanf("%d%d", &a, &b);
    if (b < a) swap(a, b);
    int aa = a;
    int bb = b;
    for (int i = 1; i < 10000; i++) {
        aa++;
        bb--;
        y += 2*i;
        if (aa > bb) y -= i, aa--;
        if (aa == bb) break;
    }
    printf("%d\n", y);
    return 0;
}
