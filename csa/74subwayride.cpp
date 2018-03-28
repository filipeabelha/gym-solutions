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
const int N = 1e3+5;

int n, a[N][N], e[N], s[N];

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < 2*n; i++) {
        for (int k = 0; k < n; k++)
            e[i] += a[i%n][k];
    }

    for (int i = 0; i < 2*n; i++) {
        for (int k = 0; k < i; k++)
            s[i] += a[k][i%n];
    }

    int people_now = 0;
    int max_people = 0;
    for (int i = 0; i < 2*n; i++) {
        people_now -= s[i];
        people_now += e[i];
        max_people = max(max_people, people_now);
    }
    printf("%d\n", max_people);

    return 0;
}
