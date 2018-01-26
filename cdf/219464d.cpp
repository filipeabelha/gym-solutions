#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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
const int N = 5e2+5;

typedef
tree<
    pll,
    null_type,
    less<pll>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;


ll n, k, cnt, id, rel;
string s;
map <string, pll> m;
map <ll, string> code;
ordered_set x;

int main () {

    scanf("%lld ", &n);
    while (n--) {
        cin >> s;
        if (s == "ISSUE") {
            cin >> s;
            if (m[s].nd) printf("EXISTS %lld %lld\n", m[s].nd-1, -m[s].st);
            else {
                printf("CREATED %lld 0\n", cnt++);
                m[s].st = 0;
                m[s].nd = cnt;
                code[cnt] = s;
                x.insert(m[s]);
            }

        } else if (s == "DELETE") {
            cin >> s;
            if (m[s].nd) {
                printf("OK %lld %lld\n", m[s].nd-1, -m[s].st);
                x.erase(m[s]);
                m[s].st = 0;
                m[s].nd = 0;
            } else printf("BAD REQUEST\n");

        } else if (s == "RELIABILITY") {
            cin >> s >> k;
            if (m[s].nd) {
                x.erase(m[s]);
                m[s].st -= k;
                x.insert(m[s]);
                printf("OK %lld %lld\n", m[s].nd-1, -m[s].st);
            } else printf("BAD REQUEST\n");

        } else if (s == "FIND") {
            cin >> k;
            if (!x.size()) printf("EMPTY\n");
            else {
                if (k >= x.size()) k = x.size()-1;
                rel = -(x.find_by_order(k)->st);
                id = x.find_by_order(k)->nd;
                printf("OK %s %lld %lld\n", code[id].c_str(), id-1, rel);
            }
        }
    }

    return 0;
}
