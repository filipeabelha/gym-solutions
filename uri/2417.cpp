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

int cv, ce, cs, fv, fe, fs, cp, fp;

int main () {
    scanf("%d%d%d%d%d%d", &cv, &ce, &cs, &fv, &fe, &fs);
    cp = 3*cv + ce;
    fp = 3*fv + fe;
    printf("%s\n", fp>cp or (fp==cp and fs>cs)?"F":cp>fp or (cp==fp and cs>fs)?"C":"=");
    return 0;
}
