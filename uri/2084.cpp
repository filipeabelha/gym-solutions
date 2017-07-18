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
const int N = 1e1+5;

int n, v[N], sum, ok;

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        sum += v[i];
    }
    sort(v, v+n);
    int fst = v[n-1];
    int snd = v[n-2];
    if (100*fst >= 45*sum) ok = 1;
    if (100*fst >= 40*sum and 100*(fst-snd) >= 10*sum) ok = 1;
    printf("%d\n", ok ? 1 : 2);
    return 0;
}
