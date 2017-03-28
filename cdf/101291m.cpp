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
const int N = 60;

int n, s[N], ans = 1, tend;

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    for (int i = 1; i < n; i++) {
        int tend2 = 0;
        if (s[i] < s[i-1]) tend2 = -1;
        if (s[i] > s[i-1]) tend2 = 1;
        //printf("[%d] vs. [%d]: tend %d; tend2 %d\n", s[i], s[i-1], tend, tend2);
        if (tend2 != 0) {
            if (tend2 != tend) ans++;
            tend = tend2;
        }
    }
    printf("%d\n", ans);
    return 0;
}
