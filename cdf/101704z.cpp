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

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const ll LMOD = 1011112131415161719ll;
const int N = 1e5+5;

string s;
int n;

int valid () {
    int bal = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') bal++;
        if (s[i] == ')') bal--;
        if (bal < 0) return 0;
    }
    return 1;
}

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) s.pb('(');
    for (int i = 0; i < n; i++) s.pb(')');
    do {
        if (valid()) cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
    return 0;
}
