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
const int N = 1e3+5;

int n, a, b, x, v[N];

int main () {
    while (~scanf("%d", &n) and n) {
        int sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            scanf(" %d.%d", &a, &b);
            x = b + 100*a;
            sum += v[i] = x;
        }
        int m = sum%n;
        sum = sum/n;
        for (int i = 0; i < n; i++)
            if (v[i]-sum > 0) {
                ans += v[i]-sum-(m>0);
                m--;
            }
        printf("$%d.%02d\n", ans/100, ans%100);
    }
    return 0;
}
