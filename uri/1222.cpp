#include <bits/stdc++.h>

int main () {
    int n, l, c;
    char chr;
    while (1) { // loop do caso
        scanf("%d %d %d%c", &n, &l, &c, &chr);
        int totalLines = 1;
        int currentLineChr = 0;
        int noloop = 1;
        while (1) { // loop da palavra
            int currentWordChr = 0;
            int end = 0;
            while (1) {
                scanf("%c", &chr);
                if (chr == 10) {
                    end = 1;
                    break;
                }
                if (chr == 32) break;
                currentWordChr++;
                noloop = 0;
            }
            if (currentLineChr == 0)
                currentLineChr += currentWordChr;
            else if (currentLineChr + 1 + currentWordChr <= c)
                currentLineChr += 1 + currentWordChr;
            else {
                totalLines += 1;
                currentLineChr = currentWordChr;
            }
            if (end) break;
        }
        if (noloop) break;
        int res = totalLines / l;
        if (totalLines % l != 0) res++;
        printf("%d\n", res);
    }
    return 0;
}
