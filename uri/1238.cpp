#include <bits/stdc++.h>

using namespace std;

int mini (int x, int y) {
    return (x <= y) ? x : y;
}

int maxi (int x, int y) {
    return (x >= y) ? x : y;
}

int main () {
    int n;
    scanf("%d", &n);
    char chr;
    scanf("%c", &chr);
    for (int i = 0; i < n; i++) {
        vector <int> word1;
        vector <int> word2;
        vector <int> word;
        while (1) {
            char chrr;
            scanf("%c", &chrr);
            if (chrr == 32)
                break;
            else {
                chr = chrr;
                word1.push_back(chr);
            }
        }
        while (1) {
            char chrr;
            scanf("%c", &chrr);
            if (chrr == 10)
                break;
            else {
                chr = chrr;
                word2.push_back(chr);
            }
        }
        while (word1.size() > 0 or word2.size() > 0) {
            if (word1.size() > 0) {
                word.push_back(word1[0]);
                word1.erase(word1.begin());
            }
            if (word2.size() > 0) {
                word.push_back(word2[0]);
                word2.erase(word2.begin());
            }
        }
        for (int j = 0; j < word.size(); j++)
            printf("%c", word[j]);
        printf("\n");
    }
    return 0;
}
