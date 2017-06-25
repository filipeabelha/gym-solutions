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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 100;

int u[N], v[N], n, m, l;

int main () {
    while (~scanf("%d", &n) and n) {
        m = l = 0;
        for (int i = 0; i < n; i++) scanf("%d", &u[i]), m += u[i];
        for (int i = 0; i < n; i++) scanf("%d", &v[i]), l += v[i];
        for (int i = 2; i < n; i++) {
            int mm, ll;
            mm = ll = 0;
            if (u[i] == u[i-1] and u[i] == u[i-2]) mm += 30;
            if (v[i] == v[i-1] and v[i] == v[i-2]) ll += 30;
            if (mm or ll) {
                if (mm == ll) mm = ll = 0;
                m += mm;
                l += ll;
                break;
            }
        }
        printf("%s\n", m > l ? "M" : l > m ? "L" : "T");
    }
    return 0;
}
