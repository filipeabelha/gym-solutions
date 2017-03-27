#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+5;

int quad[N];

int main () {
    for (int i = 0; i <= 10000; i++) for (int j = 0; i*i+j*j <= 10000; j++) {
        int z = i*i + j*j;
        quad[z] = 1;
    }
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n >= 0 and quad[n]) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
