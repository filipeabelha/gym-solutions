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
    int cnt = 0;
    Node* ch[27];
    Node () : cnt(0) {
        memset(ch, 0, sizeof ch);
    }
};

Node* root;

void add (string s) {
    Node* cur = root;
    cur->cnt++;
    for (auto c : s) {
        if (!cur->ch[c-'a']) cur->ch[c-'a'] = new Node();
        cur = cur->ch[c-'a'];
        cur->cnt++;
    }
    if (!cur->ch[26]) cur->ch[26] = new Node();
    cur = cur->ch[26];
    cur->cnt++;
}

int match (string s) {
    Node* cur = root;
    for (auto c : s) {
        if (!cur->ch[c-'a']) return false;
        cur = cur->ch[c-'a'];
    }
    return cur->cnt;
}

int n, q;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    root = new Node();

    while (n--) {
        cin >> s;
        add(s);
    }

    while (q--) {
        cin >> s;
        cout << match(s) << "\n";
    }

    return 0;
}
