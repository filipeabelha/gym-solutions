#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    char chr;
    scanf("%c", &chr);
    for (int i = 0; i < n; i++) {
        int freq[130];
        memset(freq, 0, sizeof(freq));
        while (1) {
            scanf("%c", &chr);
            if (chr == 10) break;
            freq[chr]++;
        }
        for (int j = 97; j <= 122; j++)
            freq[j] += freq[j-32];
        int elaborometro = 0;
        for (int j = 97; j <= 122; j++)
            if (freq[j] > 0)
                elaborometro++;
        if (elaborometro == 26)
            printf("frase completa\n");
        else if (elaborometro >= 13)
            printf("frase quase completa\n");
        else
            printf("frase mal elaborada\n");
    }
    return 0;
}
