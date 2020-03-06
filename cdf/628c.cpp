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
typedef vector<ll> vl;
typedef vector<vl> vll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

char sc[N];
string s;
int n, k;

char sum (char c, int x) {
    c += x;
    return c;
}

int main () {
    scanf("%d%d", &n, &k);
    scanf(" %s", sc);
    s = sc;

    for (int i = 0; i < s.size(); i++) {
        if (s[i]-'a' > 'z'-s[i]) {
            if (k >= s[i]-'a') {
                k -= s[i]-'a';
                s[i] = 'a';
            } else {
                s[i] = sum(s[i], -k);
                k = 0;
            }
        } else {
            if (k >= 'z'-s[i]) {
                k -= 'z'-s[i];
                s[i] = 'z';
            } else {
                s[i] = sum(s[i], k);
                k = 0;
            }
        }
    }

    printf("%s\n", k == 0 ? s.c_str() : "-1");

    return 0;
}
