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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;

int n, a;
char c;
string s;

int main () {
    while (~scanf("%d%d%c", &n, &a, &c)) {
        set <string> uniq;
        for (int i = 0; i < n; i++) {
            getline(cin, s);
            string ini;
            while (s[0] == ' ') s.erase(s.begin());
            ini.pb(s[0]);
            for (int i = 0; i < s.size()-1; i++)
                if (s[i] == ' ' and s[i+1] != ' ') ini.pb(s[i+1]);
            uniq.insert(ini);
        }
        printf("%d\n", n-(int)uniq.size());
    }
    return 0;
}
