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

string t;
int stars[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> t;

    pii cur = {25, 0};

    for (int i = 1;  i <= 10; i++) stars[i] = 5;
    for (int i = 11; i <= 15; i++) stars[i] = 4;
    for (int i = 16; i <= 20; i++) stars[i] = 3;
    for (int i = 21; i <= 25; i++) stars[i] = 2;

    int cons = 0;

    for (auto c : t) {
        int& r = cur.st;
        int& s = cur.nd;

        if (r == 0) continue;

        if (c == 'W') cons++;
        else cons = 0;

        if (c == 'W') s += 1 + ((r >= 6) and (cons >= 3));
        else s -= (r <= 20);

        if (s < 0 and (r == 20 or r == 25)) s = 0;

        if (s < 0) {
            r++;
            s += stars[r];
        }

        if (s > stars[r]) {
            s -= stars[r];
            r--;
        }
    }

    if (cur.st == 0) cout << "Legend\n";
    else cout << cur.st << "\n";

    return 0;
}
