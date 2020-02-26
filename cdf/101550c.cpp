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

int id (char c) {
    if (c >= '2' and c <= '9') return c-'0';
    if (c == 'T') return 10;
    if (c == 'J') return 11;
    if (c == 'Q') return 12;
    if (c == 'K') return 13;
    if (c == 'A') return 14;

    if (c == 's') return 0;
    if (c == 'h') return 1;
    if (c == 'd') return 2;
    if (c == 'c') return 3;
}

int n;
vector <pii> s, t;

int lis () {
    vector <pii> v;
    for (int i = 0; i < n; i++) {
        pii x = s[i];
        if (v.empty() or x > v.back()) v.pb(x);
        else {
            int pos = lower_bound(v.begin(), v.end(), x) - v.begin();
            v[pos] = x;
        }
    }
    return v.size();
}

int main () {
    scanf("%d%*c", &n);
    t.resize(n);
    for (int i = 0; i < n; i++) {
        char card, suit;
        scanf("%c%c%*c", &card, &suit);
        t[i] = {id(suit), id(card)};
    }

    vi cur = {0, 1, 2, 3};

    int ans = INF;
    do {
        for (int i = 0; i < (1 << 4); i++) {
            s.clear();
            for (auto p : t) {
                int suit = p.st;
                int card = p.nd;
                int mask = ((i&(1 << suit)) > 0);
                if (mask) card *= -1;
                s.pb({cur[suit], card});
            }
            ans = min(ans, n-lis());
        }

    } while (next_permutation(cur.begin(), cur.end()));

    printf("%d\n", ans);

    return 0;
}
