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
#define gcd(x, y) __gcd((x), (y))

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
int m;
deque <string> d;

void add (int k) {
    if (d.empty() or m) d.push_back(t);
    else d.push_front(t);
    m = k;
    t = "";
}

int main () {
    while (getline(cin, s)) {
        for (int i = 0; i < s.size(); i++) {
            if      (s[i] == '[') add(0);
            else if (s[i] == ']') add(1);
            else    t = t + s[i];
        }
        add(0);
        while (d.size()) {
            printf("%s", d.front().c_str());
            d.pop_front();
        }
        printf("\n");
    }
    return 0;
}
