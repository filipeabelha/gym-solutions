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

int n;
string s;

int main () {
    cin >> n >> s;
    for (int i = 1; i < n; i++)
        if (s[i] != '?' and s[i] == s[i-1]) return printf("No\n"), 0;

    if (s[0] == '?' or s.back() == '?') return printf("Yes\n"), 0;
    for (int i = 1; i < n; i++)
        if (s[i] == '?') {
            if (s[i-1] == '?' or s[i+1] == '?') return printf("Yes\n"), 0;
            if (s[i-1] == s[i+1]) return printf("Yes\n"), 0;
        }

    printf("No\n");
    return 0;
}
