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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

map <int, int> ind;

struct Node {
    Node* ch[2];
    Node () {
        memset(ch, 0, sizeof ch);
    }
};

Node* root;

void add (int x) {
    Node* cur = root;
    for (int j = 31; j >= 0; j--) {
        int b = (((1 << j)&x) > 0);
        if (!cur->ch[b]) {
            cur->ch[b] = new Node();
        }
        cur = cur->ch[b];
    }
}

int query (int x) {
    Node* cur = root;
    int ans = 0;
    for (int j = 31; j >= 0; j--) {
        int b = (((1ll << j)&x) > 0);
        if (cur->ch[!b]) {
            cur = cur->ch[!b];
            if (!b) ans += ((1 << j));
        } else {
            cur = cur->ch[b];
            if (b) ans += ((1 << j));
        }
    }
    return ans;
}

int main () {
    int t;
    scanf("%d", &t);
    while (t--) {
        vector <int> num;
        int n, q;
        scanf("%d%d", &n, &q);

        root = new Node();

        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            add(x);
            num.pb(x);
        }
        for (int i = n-1; i >= 0; i--) {
            ind[num[i]] = i+1;
        }
        while (q--) {
            int x;
            scanf("%d", &x);
            printf("%d\n", ind[query(x)]);
        }
        ind.clear();
        delete root;
        printf("\n");
    }

    return 0;
}
