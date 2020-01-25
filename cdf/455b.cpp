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

int n, k;
string s;

struct Node {
    Node* ch[26];
    pii val;

    Node () : val({0, 0}) {
        memset(ch, 0, sizeof ch);
    }
};

Node* root;

void add (string s) {
    Node* cur = root;
    for (auto c : s) {
        if (!cur->ch[c-'a']) cur->ch[c-'a'] = new Node();
        cur = cur->ch[c-'a'];
    }
}

void eval (Node* cur) {
    set <int> s, t;
    for (int i = 0; i < 26; i++) {
        if (cur->ch[i]) {
            eval(cur->ch[i]);
            s.insert(cur->ch[i]->val.st);
            t.insert(cur->ch[i]->val.nd);
        }
    }

    if (s.size()) {
        for (int i = 0; ; i++) {
            if (!s.count(i)) {
                cur->val.st = i;
                break;
            }
        }
    } else cur->val.st = 0;

    if (t.size()) {
        for (int i = 0; ; i++) {
            if (!t.count(i)) {
                cur->val.nd = i;
                break;
            }
        }
    } else cur->val.nd = 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    k &= 1;

    root = new Node();

    while (n--) {
        cin >> s;
        add(s);
    }

    eval(root);

    bool winv = root->val.st;
    bool losev = root->val.nd;

    bool fst = false;
    if (winv and losev) fst = true;
    if (winv and !losev) fst = k;

    cout << (fst ? "First" : "Second") << "\n";

    return 0;
}
