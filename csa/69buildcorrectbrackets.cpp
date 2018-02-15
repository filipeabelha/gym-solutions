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
const int N = 3e3+5;

string z;

ll minways[N][N], mincost[N][N];

int main () {
    cin >> z;
    int n = z.size();

    cl(minways, 63);
    cl(mincost, 63);
    minways[0][1] = 1;
    mincost[0][1] = 0;

    for (int I = 0; I < n; I++) {
        int i = I+1;
        for (int s = 1; s <= n+1; s++) {
            if (z[I] == '(') {
                if (mincost[i][s] == mincost[i-1][s-1] and mincost[i][s] < INF) {
                    minways[i][s] += minways[i-1][s-1];
                    minways[i][s] %= MOD;
                }
                if (mincost[i][s] > mincost[i-1][s-1]) {
                    mincost[i][s] = mincost[i-1][s-1];
                    minways[i][s] = minways[i-1][s-1];
                    mincost[i][s] %= MOD;
                    minways[i][s] %= MOD;
                }
                if (mincost[i][s] == mincost[i-1][s+1]+1 and mincost[i][s] < INF) {
                    minways[i][s] += minways[i-1][s+1];
                    minways[i][s] %= MOD;
                }
                if (mincost[i][s] > mincost[i-1][s+1]+1) {
                    mincost[i][s] = mincost[i-1][s+1]+1;
                    minways[i][s] = minways[i-1][s+1];
                    mincost[i][s] %= MOD;
                    minways[i][s] %= MOD;
                }
            } else if (z[I] == ')') {
                if (mincost[i][s] == mincost[i-1][s+1] and mincost[i][s] < INF) {
                    minways[i][s] += minways[i-1][s+1];
                    minways[i][s] %= MOD;
                }
                if (mincost[i][s] > mincost[i-1][s+1]) {
                    mincost[i][s] = mincost[i-1][s+1];
                    minways[i][s] = minways[i-1][s+1];
                    mincost[i][s] %= MOD;
                    minways[i][s] %= MOD;
                }
                if (mincost[i][s] == mincost[i-1][s-1]+1 and mincost[i][s] < INF) {
                    minways[i][s] += minways[i-1][s-1];
                    minways[i][s] %= MOD;
                }
                if (mincost[i][s] > mincost[i-1][s-1]+1) {
                    mincost[i][s] = mincost[i-1][s-1]+1;
                    minways[i][s] = minways[i-1][s-1];
                    mincost[i][s] %= MOD;
                    minways[i][s] %= MOD;
                }
            }
        }
    }
    printf("%lld %lld\n", mincost[n][1], minways[n][1]);
    return 0;
}
