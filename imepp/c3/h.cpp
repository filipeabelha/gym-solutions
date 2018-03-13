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

string s, t;
stack <string> q;
int n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> s;
        if (s == "Sleep") {
            cin >> t;
            q.push(t);
        }
        if (s == "Test")
            cout << (q.size() ? q.top() : "Not in a dream") << endl;

        if (s == "Kick" and q.size())
            q.pop();
    }
    return 0;
}
