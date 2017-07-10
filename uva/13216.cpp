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

int tc;
char c;
string s;

int main () {
    scanf("%d%c", &tc, &c);
    while (tc--) {
        getline(cin, s);
        if (s.size() == 1 and s[0] == '0')      printf("1\n");
        else if (s.size() == 1 and s[0] == '1') printf("66\n");
        else if ((s[s.size()-1]-'0')%5 == 0)    printf("76\n");
        else if ((s[s.size()-1]-'0')%5 == 1)    printf("16\n");
        else if ((s[s.size()-1]-'0')%5 == 2)    printf("56\n");
        else if ((s[s.size()-1]-'0')%5 == 3)    printf("96\n");
        else if ((s[s.size()-1]-'0')%5 == 4)    printf("36\n");
    }
    return 0;
}
