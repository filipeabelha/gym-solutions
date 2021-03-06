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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e3+10;

int n, m, x, sum, v[N];

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    for (int i = 2; i <= n; i++) {
        while (v[i-1] > m) v[i-1]--, v[i]--, sum++;
        while (v[i-1] < m) v[i-1]++, v[i]++, sum++;
    }
    printf("%d\n", sum);
    return 0;
}
