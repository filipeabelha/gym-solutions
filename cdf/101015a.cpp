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

long long d[6];
int v, i;

int main () {
    
    for(i = 0 ; i < 5 ; i++)  scanf("%I64d" , &d[i]);
    for(i = 0 ; i < 4 ; i++){
        if(d[i] >  d[i+1]){
            v = 1;
            break;
        }
    }

    if(v == 1) printf("NAO\n");
    else printf("SIM\n");

    return 0;
}
