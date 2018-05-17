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
#define gcd(x, y) __gcd((x), (y))

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
const int N = 2e5+5;

ll n;
pll w[N];
char c;

priority_queue <pll> pq;

int main () {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &w[i].st);
        w[i].nd = i;
    }

    sort(w+1, w+1+n);
    int intro = 0;

    for (int i = 1; i <= 2*n; i++) {
        scanf(" %c", &c);
        if (c == '0') {
            intro++;
            pq.push(w[intro]);
            printf("%lld", w[intro].nd);
        } else {
            pll p = pq.top(); pq.pop();
            printf("%lld", p.nd);
        }
        printf("%c", " \n"[i==2*n]);
    }

    return 0;
}
