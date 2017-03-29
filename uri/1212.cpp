#include <bits/stdc++.h>
using namespace std;

int a, b, ans;

int carry (int x, int y, int added) {
    int add = (x%10 + y%10 + added)/10;
    if (!x and !y) return 0;
    return add + carry(x/10, y/10, add);
}

int main () {
    while (1) {
        scanf("%d%d", &a, &b);
        if (!a and !b) break;
        ans = carry(a, b, 0);
        if (!ans) printf("No carry operation.\n");
        else printf("%d carry operation%s.\n", ans, (ans==1)?"":"s");
    }
    return 0;
}
