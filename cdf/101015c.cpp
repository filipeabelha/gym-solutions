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
 
const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;

vector<string> rel;

int main () {
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = 0; i <= a; i++) {
        char re[50];
        gets(re);
        rel.pb(re);
    }
    for (int i = 0; i < b; i++) {
        char re[50];
        gets(re);
        int achou = 0;
        for (int j = 0; j < rel.size(); j++) {
            if (strcmp(rel[j].c_str(), re) == 0) {
                printf("Nao e a mamae\n");
                achou = 1;
            }
        }
        if (!achou) printf("nao e o Nao e a mamae\n");
    }
    return 0;
}
