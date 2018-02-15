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
const int N = 1e5+5;

int n, a[N];
bool inc = true;

ll sum;
vector <pii> ans;

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    a[0] = a[n+1] = INF;

    ll combo = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] == a[i-1]) {
            combo++;
        } else {
            sum += combo*(combo+1)/2;
            combo = 1;
        }

        if (a[i-1] > a[i]) inc = false;
    }

    sum += combo*(combo+1)/2;

    if (inc) printf("%lld\n1 1\n", sum);
    else {
        int l = 1;
        int r = n;
        for (int i = 2; i <= n; i++) {
            if (a[i] >= a[l]) l = i; else break;
        }
        for (int i = n-1; i >= 1; i--) {
            if (a[i] <= a[r]) r = i; else break;
        }
        while (a[l-1] == a[l]) l--;
        while (a[r+1] == a[r]) r++;
        bool ok = true;
        reverse(a+l, a+r+1);
        for (int i = 2; i <= n; i++) if (a[i-1] > a[i]) ok = false;
        if (ok) printf("1\n%d %d\n", l, r);
        else printf("0\n");
    };

    return 0;
}
