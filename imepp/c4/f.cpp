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

string s;
int v[N], ans;

int main () {
    cin >> s;
    if (s.size() >= 4) {
        for (int i = 1; i <= s.size()-3; i++)
            if (s[i-1] == 'b' and s[i] == 'e' and
                s[i+1] == 'a' and s[i+2] == 'r') v[i]++;

        for (int i = 1; i < N; i++) v[i] += v[i-1];

        for (int i = 1; i <= s.size()-3; i++)
            for (int j = i+3; j <= s.size(); j++)
                ans += (v[j-3] - v[i-1] > 0);
    }
    printf("%d\n", ans);
    return 0;
}
