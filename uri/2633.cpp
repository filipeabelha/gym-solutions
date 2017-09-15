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
const int N = 1e2+5;

int n, id;
char st[N];
pair <int, string> v[N];

int main () {
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; i++) {
            scanf("%s%d ", st, &id);
            v[i] = mp(id, st);
        }
        sort(v, v+n);
        for (int i = 0; i < n; i++) printf("%s%s", v[i].nd.c_str(), i < n-1 ? " " : "\n");
    }
    return 0;
}
