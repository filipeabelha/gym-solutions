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

vector<int> suffix_array(string &s){
    int n = s.size(), alph = 256;
    vector<int> cnt(max(n, alph)), p(n), c(n);

    for(auto c : s) cnt[c]++;
    for(int i = 1; i < alph; i++) cnt[i] += cnt[i - 1];
    for(int i = 0; i < n; i++) p[--cnt[s[i]]] = i;
    for(int i = 1; i < n; i++) 
        c[p[i]] = c[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);

    vector<int> c2(n), p2(n);

    for(int k = 0; (1 << k) < n; k++){
        int classes = c[p[n - 1]] + 1;
        fill(cnt.begin(), cnt.begin() + classes, 0);

        for(int i = 0; i < n; i++) p2[i] = (p[i] - (1 << k) + n)%n;
        for(int i = 0; i < n; i++) cnt[c[i]]++;
        for(int i = 1; i < classes; i++) cnt[i] += cnt[i - 1];
        for(int i = n - 1; i >= 0; i--) p[--cnt[c[p2[i]]]] = p2[i];

        c2[p[0]] = 0;
        for(int i = 1; i < n; i++){
            pair<int, int> b1 = {c[p[i]], c[(p[i] + (1 << k))%n]};
            pair<int, int> b2 = {c[p[i - 1]], c[(p[i - 1] + (1 << k))%n]};
            c2[p[i]] = c2[p[i - 1]] + (b1 != b2);
        }

        c.swap(c2);
    }
    return p;
}

string s, t;
vi sa;
int n;

// s = text
// sa = suffix array of text s
// t = pattern to be found

bool match (string& s, vi& sa, string& t, int k, int acc) {
    int l = 0, m, r = sa.size()-1;

    while (l < r) {
        m = (l+r)/2;

        int res = strncmp(t.c_str()+acc, s.c_str()+sa[m], k);
        if (res == 0) return true;
        if (res < 0) r = m-1;
        else         l = m+1;
    }

    int res = strncmp(t.c_str()+acc, s.c_str()+sa[l], k);
    return (res == 0);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> n;
    //s.pb('$');
    sa = suffix_array(s);

    while (n--) {
        cin >> t;
        bool possible = true;
        int ans = 0;
        int acc = 0;

        while (possible) {
            int l = 0, m, r = t.size()-acc;
            while (l < r) {
                m = (l+r+1)/2;
                if (!match(s, sa, t, m, acc)) r = m-1;
                else                          l = m;
            }
            ans++;
            acc += l;
            if (!l) possible = false;
            if (acc == t.size()) break;
        }

        if (!possible) ans = -1;
        cout << ans << "\n";
    }

    return 0;
}
