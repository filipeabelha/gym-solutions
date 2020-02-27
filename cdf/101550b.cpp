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
    int dist;
    Node* ch[26];
    Node* parent;
    Node* jump;
    Node () : dist(INF) {
        parent = jump = nullptr;
        for (int i = 0; i < 26; i++) {
            ch[i] = nullptr;
        }
    }
};

void add (string& s, Node* cur) {
    vector <Node*> path;
    for (auto c : s) {
        if (!cur->ch[c-'a']) {
            cur->ch[c-'a'] = new Node();
            path.pb(cur->ch[c-'a']);
        }
        cur->ch[c-'a']->parent = cur;
        cur = cur->ch[c-'a'];
    }
    if (path.size()) {
        path.pop_back();
        for (auto elem : path) elem->jump = cur;
    }
}

queue <Node*> q;
string s;
int n, m;

void insertQueue (int val, Node* elem) {
    if (elem->dist == INF) {
        elem->dist = val;
        q.push(elem);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;

    Node* root = new Node();

    while (n--) {
        cin >> s;
        add(s, root);
    }

    root->dist = 0;
    q.push(root);

    while (q.size()) {
        Node* cur = q.front();
        q.pop();

        int d = cur->dist;

        if (cur->jump)   insertQueue(d+1, cur->jump);
        if (cur->parent) insertQueue(d+1, cur->parent);
        for (int i = 0; i < 26; i++)
            if (cur->ch[i]) insertQueue(d+1, cur->ch[i]);
    }

    while (m--) {
        cin >> s;
        Node* cur = root;
        int ans = s.size();
        for (auto c : s) {
            if (cur->ch[c-'a']) {
                cur = cur->ch[c-'a'];
                ans--;
            }
            else break;
        }
        ans += cur->dist;
        cout << ans << "\n";
    }


    return 0;
}
