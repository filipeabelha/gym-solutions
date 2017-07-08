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
const int N = 1e4+5;

int n, cnt, v[N], maxi;

int main () {
    while (~scanf("%d", &n) and n and ++cnt) {
        cl(v, 0);
        maxi = -INF;
        for (int a, b, i = 1; i <= n; i++) {
            scanf("%d%d", &a, &b);
            v[i] = a-b;
        }
        int sum, ans, xsum, ysum, xans, yans;
        sum = ysum = xans = yans = 0;
        ans = -1;
        xsum = 1;
        for (int i = 1; i <= n; i++) {
            if (sum+v[i] >= 0) {
                sum += v[i];
                ysum = i;
            } else {
                sum = 0;
                xsum = i+1;
            }
            if (sum >= ans) {
                ans = sum;
                xans = xsum;
                yans = ysum;
            }
        }
        printf("Teste %d\n", cnt);
        (ans > 0 ? printf("%d %d\n\n", xans, yans) : printf("nenhum\n\n"));
    }
    return 0;
}
