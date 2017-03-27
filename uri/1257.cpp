#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    char chr;
    scanf("%c", &chr);
    for (int i = 0; i < n; i++) {
        int m;
        int sum = 0;
        scanf("%d", &m);
        scanf("%c", &chr);
        for (int j = 0; j < m; j++) {
            int pos = 0;
            while (1) {
                scanf("%c", &chr);
                if (chr == 10) break;
                sum += (chr-65) + pos + j;
                pos++;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
