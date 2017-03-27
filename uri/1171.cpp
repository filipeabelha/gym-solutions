#include <bits/stdc++.h>

const int N = 2050;

int freq[N];

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        freq[x]++;
    }
    for (int i = 0; i < 2050; i++)
        if (freq[i] > 0)
            printf("%d aparece %d vez(es)\n", i, freq[i]);
    return 0;
}
