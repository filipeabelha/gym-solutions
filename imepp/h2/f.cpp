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

int k, ok, p, q;
string s, t;

int main () {
    scanf("%d", &k);
    while (k--) {
        cin >> s >> t;

        t = t+t;
        ok = 0;
        p = q = 0;

        if (t.size() < s.size()) {
            printf("N\n");
            continue;
        }

        for (int z = 0; z < t.size(); z++) {
            if (t.size()-z < s.size()) break;
            int gd = 1;
            for (int i = z; i < z+s.size(); i++)
                if (s[i-z] != t[i]) gd = 0;
            if (gd) ok = 1;
        }

        reverse(t.begin(), t.end());

        for (int z = 0; z < t.size(); z++) {
            if (t.size()-z < s.size()) break;
            int gd = 1;
            for (int i = z; i < z+s.size(); i++)
                if (s[i-z] != t[i]) gd = 0;
            if (gd) ok = 1;
        }

        printf("%c\n", ok ? 'S' : 'N');

    }
    return 0;
}
