#include <bits/stdc++.h>

int main () {
        int h1, m1, h2, m2, hd, md;
        scanf("%d%d%d%d", &h1, &m1, &h2, &m2);
        if (h2 <= h1 and m2 <= m1) h2 += 24;
        if (m2 < m1) m2 += 60, h2--;
        hd = h2 - h1;
        md = m2 - m1;
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", hd, md);
        return 0;
}
