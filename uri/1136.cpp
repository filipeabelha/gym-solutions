#include <bits/stdc++.h>
using namespace std;

set <int> s;
int n, b, v[100];

int main () {
    while (1) {
        scanf("%d%d", &n, &b);
        if (!n and !b) break;
        for (int i = 0; i < b; i++) scanf("%d", &v[i]);
        for (int i = 0; i < b; i++) for (int j = 0; j < b; j++)
            s.insert(abs(v[i]-v[j]));
        printf("%s\n", s.size()-1 == n ? "Y" : "N");
        s.clear();
    }
    return 0;
}
