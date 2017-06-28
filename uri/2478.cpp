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

int n;
string s, ss;

int main () {
    getline(cin, s);
    while (1) {
        sscanf(s.c_str(), "%d", &n);
        map <string, set<string> > m;
        for (int i = 0; i < n; i++) {
            cin >> s;
            for (int j = 0; j < 3; j++) {
                cin >> ss;
                m[s].insert(ss);
            }
        }
        while (cin >> s) {
            if (s[0] > '0' and s[0] < '9') break;
            cin >> ss;
            cout << (m[s].count(ss) ? "Uhul! Seu amigo secreto vai adorar o/" : "Tente Novamente!") << endl;
        }
        if (!(s[0] > '0' and s[0] < '9')) break;
    }
    return 0;
}
