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

int n, u[N];
set <int> s;

int main () {
    while (~scanf("%d", &n)) {
        s.clear();
        for (int i = 0; i < n; i++) scanf("%d", &u[i]);
        for (int i = 1; i < n; i++) s.insert(abs(u[i]-u[i-1]));
        bool a = (s.size() == n-1);
        bool b = (s.empty() or (*s.begin() == 1));
        bool c = (s.empty() or (*s.rbegin() == n-1));
        printf("%s\n", (a and b and c) ? "Jolly" : "Not jolly");
    }
    return 0;
}