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

int n1, n2, d1, d2, v1, v2;

int main () {
    scanf("%d%d%d%d%d%d", &n1, &d1, &v1, &n2, &d2, &v2);
    printf("%d\n", (double) d1/v1 < (double) d2/v2 ? n1 : n2);
    return 0;
}
