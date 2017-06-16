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

double a;

int main () {
    cin >> a;
    ostringstream out;
    out.precision(4);
    out << scientific << a << endl;
    string s = out.str();
    int i = s.size()-4;
    while (s[i] != 'e') i--;
    s[i] = 'E';
    printf("%s%s", s.c_str()[0] == '-' ? "" : "+", s.c_str());
    return 0;
}
