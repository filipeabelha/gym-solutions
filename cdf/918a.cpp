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

int n;
ll f[N];
set <ll> nums;

int main () {
    f[2] = f[1] = 1;
    for (int i = 3; i < 20; i++) f[i] = f[i-1] + f[i-2];
    for (int i = 1; i < 20; i++) nums.insert(f[i]);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        printf("%c", nums.count(i) ? 'O' : 'o');
    printf("\n");
    return 0;
}
