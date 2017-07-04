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
const int N = 1e5+5;

int tc, sz;
string u, v;

int main () {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &sz);
        cin >> u;
        v = u;
        sort(v.begin(), v.end());
        int ch = 0;
        for (int i = 0; i < sz; i++)
            if (u[i] != v[i]) ch++;
        printf("There are%s the chance.\n", ch == 2 ? "" : "n't");
    }
    return 0;
}
