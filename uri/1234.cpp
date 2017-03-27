#include <bits/stdc++.h>

int main () {
    char word[60];
    while (fgets(word, 60, stdin)) {
        bool capital = true;
        for (int i = 0; i < (int) strlen(word); i++) {
            if (word[i] == 32) continue;
            if (word[i] >= 97) word[i] -= 32;
            if (!capital)      word[i] += 32;
            if (capital) capital = false;
            else capital = true;
        }
        for (int i = 0; i < (int) strlen(word); i++)
            if (word[i] == 32 or word[i] >= 65) printf("%c", word[i]);
        printf("\n");
    }
    return 0;
}
