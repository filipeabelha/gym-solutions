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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

char c;
string a, b;
set <string> killed;
map <string, int> killers;

int main () {
    while (cin >> a) {
        cin >> b;
        scanf("%c", &c);
        killed.insert(b);
        killers[a]++;
    }
    printf("HALL OF MURDERERS\n");
    for (auto x : killers)
        if (!killed.count(x.st)) printf("%s %d\n", x.st.c_str(), x.nd);
    return 0;
}
