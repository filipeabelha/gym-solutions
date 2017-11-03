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
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

string s;
int ok = 0;
int never = 0;

int main () {
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s.substr(i, 5) == "Danil") {
            if (ok) never = 1;
            ok = 1;
        }
        if (s.substr(i, 4) == "Olya") {
            if (ok) never = 1;
            ok = 1;
        }
        if (s.substr(i, 5) == "Slava") {
            if (ok) never = 1;
            ok = 1;
        }
        if (s.substr(i, 3) == "Ann") {
            if (ok) never = 1;
            ok = 1;
        }
        if (s.substr(i, 6) == "Nikita") {
            if (ok) never = 1;
            ok = 1;
        }
    }
    printf("%s\n", (ok and !never) ? "YES" : "NO");
    return 0;
}
