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

int n, v[N], ans;

int main () {
    scanf("%d", &n);
    for (int t, i = 0; i < n; i++) {
        scanf("%d", &t);
        for (int j = t; j < t+10; j++) v[j] = 1;
    }
    for (int i = 0; i < N; i++) if (v[i]) ans++;
    printf("%d\n", ans);
    return 0;
}
