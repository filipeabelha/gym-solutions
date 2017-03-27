#include <bits/stdc++.h>

int main () {
    char chr;
    while (1) {
        int noloop = 1, correct = 1, balance = 0;
        while (1) {
            scanf("%c", &chr);
            if (chr == 10)                  break;
            if (chr == 40)                  balance++;
            if (chr == 41 and balance > 0)  balance--;
            else if (chr == 41 and balance == 0) correct = 0;
            noloop = 0;
        }
        if (balance > 0) correct = 0;
        if (noloop) break;
        if (correct) printf("correct\n"); else printf("incorrect\n");
    }
    return 0;
} 
