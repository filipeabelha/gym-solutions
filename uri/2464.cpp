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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6, N = 1e4+10;

char chr, s[N], m[N];

int main () {
    scanf("%s%c", s, &chr);
    for (int i = 0; i < 26; i++) m[i+'a'] = s[i];
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++) printf("%c", m[s[i]]); printf("\n");
    return 0;
}
