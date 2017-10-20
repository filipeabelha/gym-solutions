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
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int cmp[N];

int chk (int n) {
    if (cmp[n] or n == 1) return 0;
    while (n > 0) {
        if (cmp[n%10] or n%10 == 0 or n%10 == 1) return -1;
        n /= 10;
    }
    return 1;
}

int x;

int main () {
    for (ll i = 2; i < N; i++) if (!cmp[i]) for (ll j = i*i; j < N; j += i) cmp[j] = 1;
    while (~scanf("%d", &x)) printf("%s\n", chk(x) == 1 ? "Super" : chk(x) == -1 ? "Primo" : "Nada");
    return 0;
}
