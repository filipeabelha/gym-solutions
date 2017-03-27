#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    char chr;
    scanf("%d", &n);
    scanf("%c", &chr);
    for (int i = 0; i < n; i++) {
        vector <int> word;
        while(1) {
            scanf("%c", &chr);
            if (chr == 10) break;
            word.push_back(chr);
        }
        for (int j = 0; j < word.size(); j++) {
            if ((word[j] >= 65 and word[j] <= 90)
            or (word[j] >= 97 and word[j] <= 122))
                word[j] += 3;
        }
        vector <int> newword;
        for (int j = word.size() - 1; j >= 0; j--) newword.push_back(word[j]);
        for (int j = newword.size()/2; j < newword.size(); j++) newword[j] -= 1;
        for (int j = 0; j < newword.size(); j++) printf("%c", newword[j]);
        printf("\n");
    }
    return 0;
}
