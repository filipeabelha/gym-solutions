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

string l;
int v[100];

int main () {
    cin >> l; for (int i = 0; i < l.size(); i++) v[i] += (l[i]-'0')*1000;
    cin >> l; for (int i = 0; i < l.size(); i++) v[i] += (l[i]-'0')*100;
    cin >> l; for (int i = 0; i < l.size(); i++) v[i] += (l[i]-'0')*10;
    cin >> l; for (int i = 0; i < l.size(); i++) v[i] += (l[i]-'0')*1;
    for (int i = 1; i < l.size()-1; i++) printf("%c", (v[i]*v[0]+v[l.size()-1])%257);
    printf("\n");
    return 0;
}
