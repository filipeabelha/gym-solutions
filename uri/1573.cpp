#include <bits/stdc++.h>
using namespace std;

int a, b, c, ans;

int main () {
    while (1) {
        scanf("%d%d%d", &a, &b, &c);
        if (!a and !b and !c) break;
        for (ans = 0; ans*ans*ans <= a*b*c; ans++);
        printf("%d\n", ans-1);
    }
    return 0;
}
