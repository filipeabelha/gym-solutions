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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;

int c[5], p[5];

int main () {
    for (int i = 0; i < 3; i++) scanf("%d", &c[i]);
    for (int i = 0; i < 2; i++) scanf("%d", &p[i]);
    sort(c, c+3);
    sort(p, p+2);
    printf("%s\n", c[0] > p[0] or c[1] > p[1] ? "N" : "S");
    return 0;
}
