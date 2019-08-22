#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand(random_device{}());

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
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;

string s1, s2;
int m[N][N], len1, len2;

int main () {
    cin >> s1 >> s2;
    len1 = s1.size();
    len2 = s2.size();
    for (int i = 1; i <= len1; i++)
        for (int j = 1; j <= len2; j++)
            if (s1[i-1] == s2[j-1])
                m[i][j] = 1 + m[i-1][j-1];
            else
                m[i][j] = max(m[i][j-1], m[i-1][j]);

    printf("%d\n", m[len1][len2]);
    return 0;
}
