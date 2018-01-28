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

char s[N];
int sz;

int main () {
    while (~scanf("%s", s)) {
        sz = strlen(s);
        for (int i = 0; i < sz; i++) {
            int ok = 1;
            int u = 0;
            int v = 0;
            for (; u < sz; u++) {
                if (s[u] != s[v]) ok = 0;
                v++;
                if (v > i) v -= (i+1);
            }
            if (!ok) continue;
            for (int k = 0; k <= i; k++) printf("%c", s[k]);
            printf("\n");
            break;
        }
    }
    return 0;
}
