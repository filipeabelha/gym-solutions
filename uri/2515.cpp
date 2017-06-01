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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e5+10;

int n, x, p, v[N];

int main () {
    while (~scanf("%d", &n)) {
        p = 0;
        for (int i = 1; i <= n; i++) scanf("%d", &x), v[i] = v[i-1]+x;
        while (abs((double)v[n]/2-v[p+1]) < abs((double)v[n]/2-v[p])) p++;
        printf("%d %d\n", min(v[p],v[n]-v[p]), max(v[p],v[n]-v[p]));
    }
    return 0;
}
