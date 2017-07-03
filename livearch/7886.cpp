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

int v[4];

int main () {
    while (~scanf("%d%d%d%d", &v[0], &v[1], &v[2], &v[3])) {
        int a = abs(v[0]+v[1]-v[2]-v[3]);
        int b = abs(v[0]+v[2]-v[1]-v[3]);
        int c = abs(v[0]+v[3]-v[2]-v[1]);
        printf("%d\n", min(min(a, b), c));
    }
    return 0;
}
