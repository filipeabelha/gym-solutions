#include <bits/stdc++.h>
using namespace std;

int n, cnt, num;

int main () {
    while (scanf("%d", &n) != EOF) {
        cnt = 1; num = 1;
        while (1) {
            if (num % n == 0) break;
            cnt++;
            num = (num*10+1)%n;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
