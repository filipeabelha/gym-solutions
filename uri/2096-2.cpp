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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5;

int n, a, b, k;
int cmp[N], sum[N], ord[N], bit[20][N];

void add (int p, int k) {
    for (p+=1; p < N; p+=p&-p) bit[k][p]++;
}

int queryy (int p, int k) {
    int ret = 0;
    for (p+=1; p > 0; p-=p&-p) ret += bit[k][p];
    return ret;
}

void buildd () {
    for (int i = 2; i < N; i++)
        if (!cmp[i]) for (int j = i; j < N; j += i) cmp[j] = 1, sum[j] += i;
    for (int i = 2; i < N; i++) {
        ord[i] = ord[sum[i]]+1;
        add(i, ord[i]);
    }
}

int main () {
    buildd();
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d%d", &a, &b, &k);
        printf("%d\n", k > 12 ? 0 : queryy(b, k)-queryy(a-1, k));
    }
    return 0;
}
