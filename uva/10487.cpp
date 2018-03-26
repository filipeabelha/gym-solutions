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
#define gcd(x, y) __gcd((x), (y))

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
const int N = 1e5+5;

int n, q, x, cnt;

int main () {
    while (~scanf("%d", &n) and n and ++cnt) {
        printf("Case %d:\n", cnt);
        vi v(n);
        vi w;
        for (auto& x : v) scanf("%d", &x);
        for (int i = 0; i < v.size(); i++)
            for (int j = i+1; j < v.size(); j++)
                w.pb(v[i]+v[j]);

        scanf("%d", &q);
        while (q--) {
            scanf("%d", &x);
            int ans = INF;
            int num = 0;
            for (auto c : w) {
                if (ans > abs(x-c)) {
                    ans = abs(x-c);
                    num = c;
                }
            }
            printf("Closest sum to %d is %d.\n", x, num);
        }
    }
    return 0;
}
