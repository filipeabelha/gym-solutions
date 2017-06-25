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

string s;
int tot, cnt;

int main () {
    getline(cin, s);
    for (int i = s.size()-1; i >= 0; i--) {
        if (s[i] == '0') tot += 10, i--;
        else tot += s[i]-'0';
        cnt++;
    }
    printf("%.2f\n", (double) tot/cnt);
    return 0;
}
