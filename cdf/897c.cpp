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

int q, n;
ll s[N], k;
string f = " What are you doing at the end of the world? Are you busy? Will you save us?";
string p = " What are you doing while sending \"\"? Are you busy? Will you send \"";

void query (int n, ll k) {
    if (n > 53 and k > 34) {query(n-1, k-34); return;}
    if (n > 0 and k <= 34) {printf("%c", p[k]); return;}
    if (k > s[n]) {printf("."); return;}
    if (n == 0) {printf("%c", f[k]); return;}

    ll l2 = 34+s[n-1];
    ll l3 = 34+s[n-1]+32;
    ll l4 = 34+s[n-1]+32+s[n-1];

    if (k == s[n]) {printf("?"); return;}
    if (k == s[n]-1) {printf("\""); return;}
    if (k <= l2) {query(n-1, k-34); return;}
    if (k <= l3) {printf("%c", p[k-s[n-1]]); return;}
    if (k <= l4) {query(n-1, k-66-s[n-1]); return;}
}

int main () {
    s[0] = 75;
    for (int i = 1; i <= 53; i++) s[i] = 2*s[i-1] + 68;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%lld", &n, &k);
        query(n, k);
    }
    printf("\n");
    return 0;
}
