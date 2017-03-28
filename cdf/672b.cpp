#include <bits/stdc++.h>

int freq[130];

int main () {
    int n;
    scanf("%d", &n);
    char chr;
    scanf("%c", &chr);
    for (int i = 0; i < n; i++) {
        scanf("%c", &chr);
        freq[chr]++;
    }
    if (n > 26) printf("-1\n");
    else {
        int res = 0;
        for (int i = 97; i <= 122; i++) if (freq[i] > 0) res += freq[i]-1;
        printf("%d\n", res);
    }
    return 0;
}


