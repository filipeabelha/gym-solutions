#include <bits/stdc++.h>
using namespace std;
 
#define st first
#define nd second
 
typedef pair <int, pair <int, int> > P;
 
int n, mx;
 
vector <P> v;
 
int main () {
    scanf("%d", &n);
    v.resize(n);
 
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &v[i].st, &v[i].nd.st, &v[i].nd.nd);
        mx = max(mx, v[i].st);
    }
 
    for (int h = 0; h <= 1825*mx; h++) {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            int d = v[i].st;
            int a = v[i].nd.st;
            int b = v[i].nd.nd;
            int lineok = false;
            int hh = h % d;
            if (a < b) {
                if (hh <= a or hh >= b) lineok = true;
            } else if (a > b) {
                if (hh >= b and hh <= a) lineok = true;
            }
            if (!lineok) ok = false;
        }
        if (ok) {
            printf("%d\n", h);
            return 0;
        }
    }
 
    printf("impossible\n");
    return 0;
}
