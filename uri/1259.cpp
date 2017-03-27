#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef vector <int> vi;

int n;
vi v;

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        v.pb(x);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        if (v[i] % 2 == 0)
            printf("%d\n", v[i]);
    for (int i = v.size()-1; i >= 0; i--)
        if (v[i] % 2 == 1)
            printf("%d\n", v[i]);
    return 0;
}
