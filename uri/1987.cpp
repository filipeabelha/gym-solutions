#include <bits/stdc++.h>
using namespace std;

int n, m, sum;

int main () {
    while (~scanf("%d%d", &n, &m)) {
        sum = 0;
        while (m > 0) sum += m % 10, m /= 10;
        printf("%d %s\n", sum, !(sum%3) ? "sim" : "nao");
    }
    return 0;
}
