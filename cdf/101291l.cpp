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

int m[5][5], a, l, perf, cond1, cond2 = 1, cond3 = 2;
int p, l2;
int main () {
    for (int i = 1; i <= 3; i++) {
        int rea = 1;
        for (int j = 1; j <= 2; j++) {
            scanf("%d", &m[i][j]);
            rea *= m[i][j];
        }
        a += rea;
    }

    for (int i = 1; i <= 174; i++)
        if (i*i == a) perf = 1, l = i;

    if (!perf) printf("NO\n");
    else {
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 2; j++) {
                if (m[i][j] == l) cond1++, p=i, l2 = m[i][j%2+1];
                if (m[i][j] > l) cond2 = 0;
            }
        }
        if (cond1 == 1) {
            cond3 = 0;
            for (int i = 1; i <= 3; i++) {
                if (i == p) continue;
                for (int j = 1; j <= 2; j++) {
                    if (m[i][j] == l-l2) {
                        cond3++;
                        break;
                    }
                }
            }
        }
        printf("%s\n", ((cond1 % 2 == 1) and cond2 and cond3 == 2) ? "YES" : "NO");
    }
    return 0;
}
