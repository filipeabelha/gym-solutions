#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

string s, t, u, v;
set <char> yea;
int n, sym;

int main () {
    cin >> s;
    for (auto c : s) yea.insert(c);
    cin >> s;
    for (auto c : s) if (c == '*') sym = 1;
    if (sym) {
        int i;
        for (i = 0; i < s.size(); i++) {
            if (s[i] == '*') break;
            u.pb(s[i]);
        }
        i++;
        for (; i < s.size(); i++) v.pb(s[i]);
    }

    scanf("%d", &n);
    while (n--) {
        cin >> t;

        int ok = 1;
        if (!sym) {
            if (s.size() != t.size()) ok = 0;
            else for (int i = 0; i < t.size(); i++) {
                if (s[i] == t[i]) continue;
                if (s[i] == '?' and yea.count(t[i])) continue;
                ok = 0;
            }
        } else {
            if (t.size() < u.size() + v.size()) ok = 0;
            else {
                string x, y, m;
                for (int i = 0; i < u.size(); i++) x.pb(t[i]);
                for (int i = t.size()-v.size(); i < t.size(); i++)
                    y.pb(t[i]);
                for (int i = u.size(); i < t.size()-v.size(); i++)
                    m.pb(t[i]);


                for (int i = 0; i < u.size(); i++) {
                    if (u[i] == x[i]) continue;
                    if (u[i] == '?' and yea.count(x[i])) continue;
                    ok = 0;
                }
                for (int i = 0; i < v.size(); i++) {
                    if (v[i] == y[i]) continue;
                    if (v[i] == '?' and yea.count(y[i])) continue;
                    ok = 0;
                }
                for (auto c : m) if (yea.count(c)) ok = 0;
            }
        }
        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}
