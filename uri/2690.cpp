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

int n, cnt;
string s;
map <char, char> m;

int main () {

    m['G'] = '0';
    m['Q'] = '0';
    m['a'] = '0';
    m['k'] = '0';
    m['u'] = '0';

    m['I'] = '1';
    m['S'] = '1';
    m['b'] = '1';
    m['l'] = '1';
    m['v'] = '1';

    m['E'] = '2';
    m['O'] = '2';
    m['Y'] = '2';
    m['c'] = '2';
    m['m'] = '2';
    m['w'] = '2';

    m['F'] = '3';
    m['P'] = '3';
    m['Z'] = '3';
    m['d'] = '3';
    m['n'] = '3';
    m['x'] = '3';

    m['J'] = '4';
    m['T'] = '4';
    m['e'] = '4';
    m['o'] = '4';
    m['y'] = '4';

    m['D'] = '5';
    m['N'] = '5';
    m['X'] = '5';
    m['f'] = '5';
    m['p'] = '5';
    m['z'] = '5';

    m['A'] = '6';
    m['K'] = '6';
    m['U'] = '6';
    m['g'] = '6';
    m['q'] = '6';

    m['C'] = '7';
    m['M'] = '7';
    m['W'] = '7';
    m['h'] = '7';
    m['r'] = '7';

    m['B'] = '8';
    m['L'] = '8';
    m['V'] = '8';
    m['i'] = '8';
    m['s'] = '8';

    m['H'] = '9';
    m['R'] = '9';
    m['j'] = '9';
    m['t'] = '9';

    scanf("%d ", &n);
    while (n--) {
        getline(cin, s);
        cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') continue;
            cnt++;
            printf("%c", m[s[i]]);
            if (cnt == 12) break;
        }
        printf("\n");
    }
    return 0;
}
