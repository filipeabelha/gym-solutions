#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    char chr;
    scanf("%c", &chr);
    for (int i = 1; i <= n; i++) {
        vector <int> answer;
        vector <int> team1;
        vector <int> team2;
        int team1score = 0;
        int team2score = 0;
        int desempate = 0;
        int desempatewinner = 0;
        while (1) {
            scanf("%c", &chr);
            if (chr == 10) break;
            answer.push_back(chr);
        }
        while (1) {
            scanf("%c", &chr);
            if (chr == 10) break;
            team1.push_back(chr);
        }
        while (1) {
            scanf("%c", &chr);
            if (chr == 10) break;
            team2.push_back(chr);
        }
        for (int j = 0; j < answer.size(); j++) {
            if (answer[j] == team1[j]) team1score++;
            if (answer[j] == team2[j]) team2score++;
            if (desempate == 0 and
            ((answer[j] != team1[j] and
            answer[j] == team2[j]) or
            (answer[j] == team1[j] and
            answer[j] != team2[j]))) {
                desempate = 1;
                if (answer[j] != team1[j] and answer[j] == team2[j])
                   desempatewinner = 2;
                if (answer[j] == team1[j] and answer[j] != team2[j])
                   desempatewinner = 1;
            }
        }
        printf("Instancia %d\n", i);
        if (team1score > team2score) printf("time 1\n\n");
        else if (team2score > team1score) printf("time 2\n\n");
        else if (desempatewinner == 1) printf("time 1\n\n");
        else if (desempatewinner == 2) printf("time 2\n\n");
        else printf("empate\n\n");
    }
    return 0;
}
