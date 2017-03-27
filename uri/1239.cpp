#include <bits/stdc++.h>

using namespace std;

int main () {
    while (1) {
        vector <int> word;
        char chr;
        int italic = 1, bold = 1, noloop = 1;
        while (1) {
            scanf("%c", &chr);
            if (chr == 10) break;
            if (chr == 95) {
                word.push_back(60);
                if (italic) italic = 0;
                else word.push_back(47), italic = 1;
                word.push_back(105);
                word.push_back(62);
            } else if (chr == 42) {
                word.push_back(60);
                if (bold) bold = 0;
                else word.push_back(47), bold = 1;
                word.push_back(98);
                word.push_back(62);
            } else
                word.push_back(chr);
        }
        for (int i = 0; i < word.size(); i++) {
            printf("%c", word[i]);
            noloop = 0;
        }
        if (noloop) break;
        printf("\n");
    }
    return 0;
}
