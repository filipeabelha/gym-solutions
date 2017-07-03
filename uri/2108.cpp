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

string maxi;
char s[150], c;

int main () {
    while (1) {
        vi sz;
        while (1) {
            scanf("%s%c", s, &c);
            if (s[0] == '0') break;
            if (strlen(s) >= maxi.size()) maxi = s;
            sz.pb(strlen(s));
            if (c == '\n') break;
        }
        if (s[0] == '0') break;
        for (int i = 0; i < sz.size(); i++)
            printf("%d%s", sz[i], i < sz.size()-1 ? "-" : "\n");
    }
    printf("\nThe biggest word: %s\n", maxi.c_str());
    return 0;
}
