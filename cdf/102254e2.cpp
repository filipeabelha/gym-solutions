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

int n;
string s;
vector <string> ans;

struct Node {
    Node* children[27];
};

bool check (Node* root, string& s) {
    for (auto c : s) {
        if (c == '$') {
            if (root->children[26]) root = root->children[26];
            else return false;
        } else {
            if (root->children[c-'a']) root = root->children[c-'a'];
            else return false;
        }
    }
    return true;
}

void add (Node* root, string& s) {
    for (auto c : s) {
        if (c == '$') {
            if (!root->children[26]) root->children[26] = new Node();
            root = root->children[26];
        } else {
            if (!root->children[c-'a']) root->children[c-'a'] = new Node();
            root = root->children[c-'a'];
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    Node* root = new Node();

    while (n--) {
        cin >> s;
        if (s.size() < 4) continue;
        s.pb('$');
        if (check(root, s)) ans.pb(s);
        else add(root, s);
    }

    if (ans.size()) {
        cout << ans.size() << "\n";
        for (auto x : ans) {
            x.pop_back();
            cout << x << "\n";
        }
    } else cout << "SAFO\n";
    return 0;
}
