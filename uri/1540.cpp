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

int tc, a, b;
double aa, bb;
char ans[100];

int main () {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%lf%d%lf", &a, &aa, &b, &bb);
        sprintf(ans, "%.2lf\n", floor(100*(bb-aa)/(b-a))/100);
        for (int i = 0; i < strlen(ans); i++)
            if (ans[i] == '.') ans[i] = ',';
        printf("%s", ans);
    }
    return 0;
}