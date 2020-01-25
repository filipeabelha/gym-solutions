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

struct Node {
    Node* ch[2];
    Node () {
        ch[0] = ch[1] = nullptr;
    }
};

// Returns max xor
ll query (ll x, Node* root) {
    Node* cur = root;
    ll ans = 0;
    for (ll j = 31; j >= 0; j--) {
        ll b = (((1ll << j)&x) > 0);
        if (cur->ch[!b]) {
            cur = cur->ch[!b];
            ans += (1ll << j);
        } else {
            if (!cur->ch[b]) cur->ch[b] = new Node();
            cur = cur->ch[b];
        }
    }
    return ans;
}

// Add new number to trie
void add (ll x, Node* root) {
    Node* cur = root;
    for (ll j = 31; j >= 0; j--) {
        ll b = (((1ll << j)&x) > 0);
        if (!cur->ch[b]) cur->ch[b] = new Node();
        cur = cur->ch[b];
    }
}

ll t, n, x;

int main () {
    while (~scanf("%lld", &t)) {
        while (t--) {
            scanf("%lld", &n);

            ll sum = 0;
            ll ans = 0;

            Node* root = new Node();

            add(0, root);

            for (int i = 1; i <= n; i++) {
                scanf("%lld", &x);
                sum = sum^x;
                ans = max(ans, query(sum, root));
                add(sum, root);
            }

            delete root;

            ans = max(ans, query(0, root));
            printf("%lld\n", ans);
        }
    }

    return 0;
}
