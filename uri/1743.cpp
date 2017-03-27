#include <bits/stdc++.h>

using namespace std;

int main () {
    vector <int> a;
    vector <int> b;
    int res = 1; 
    for (int i = 0; i < 5; i++) {
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }
    for (int i = 0; i < 5; i++) {
        int x;
        scanf("%d", &x);
        b.push_back(x);
    }
    for (int i = 0; i < 5; i++) {
        if (a[i] == b[i]) res = 0;
    }
    if (res) printf("Y\n"); else printf("N\n");
    return 0;
}
