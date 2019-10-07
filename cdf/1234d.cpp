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
const int N = 1e5+5;

int bit[N][26];

void add (int p, int v, int k) {
    for (p+=2; p<N; p += p&-p) bit[p][k] += v;
}

int query (int p, int k) {
    int r = 0;
    for (p+=2; p; p -= p&-p) r += bit[p][k];
    return r;
}

int rangesum (int a, int b) {
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        int r = query(b, i)-(a ? query(a-1, i) : 0);
        if (r) ans++;
    }
    return ans;
}

string s;
int q, o, a, b;
char c;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> q;

    for (int i = 1; i <= s.size(); i++) {
        add(i, 1, s[i-1]-'a');
    }

    while (q--) {
        cin >> o >> a;
        if (o == 2) {
            cin >> b;
            cout << rangesum(a, b) << endl;
        }
        else {
            cin >> c;
            add(a, -1, s[a-1]-'a');
            s[a-1] = c;
            add(a, +1, s[a-1]-'a');
        }
    }

    return 0;
}
