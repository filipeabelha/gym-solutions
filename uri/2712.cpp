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

int n, ok;
string s;

int main () {
    scanf("%d", &n);
    while (n--) {
        ok = 1;
        cin >> s;
        if (s.size() != 8)                 ok = 0;
        else if (s[0] < 'A' or s[0] > 'Z') ok = 0;
        else if (s[1] < 'A' or s[1] > 'Z') ok = 0;
        else if (s[2] < 'A' or s[2] > 'Z') ok = 0;
        else if (s[3] != '-')              ok = 0;
        else if (s[4] < '0' or s[4] > '9') ok = 0;
        else if (s[5] < '0' or s[5] > '9') ok = 0;
        else if (s[6] < '0' or s[6] > '9') ok = 0;
        else if (s[7] < '0' or s[7] > '9') ok = 0;
        if (!ok) {
            printf("FAILURE\n");
            continue;
        }
        if (s[7] == '1' or s[7] == '2') printf("MONDAY\n");
        if (s[7] == '3' or s[7] == '4') printf("TUESDAY\n");
        if (s[7] == '5' or s[7] == '6') printf("WEDNESDAY\n");
        if (s[7] == '7' or s[7] == '8') printf("THURSDAY\n");
        if (s[7] == '9' or s[7] == '0') printf("FRIDAY\n");
    }
    return 0;
}
