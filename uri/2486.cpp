#include <bits/stdc++.h>
using namespace std;

int n, qtd, ans;
char chr;

string s;

int main () {
    while (1) {
        scanf("%d", &n);
        if (!n) break;
        ans = 0;
        while (n--) {
            scanf("%d%c", &qtd, &chr);
            getline(cin, s);
            if (s[0] == 's') ans += 120*qtd;
            else if (s[0] == 'g') ans += 70*qtd;
            else if (s[0] == 'l') ans += 50*qtd;
            else if (s[0] == 'b') ans += 34*qtd;
            else if (s[2] == 'n') ans += 56*qtd;
            else if (s[0] == 'm') ans += 85*qtd;
        }
        if (ans > 130) printf("Menos %d mg\n", ans-130);
        else if (ans < 110) printf("Mais %d mg\n", 110-ans);
        else printf("%d mg\n", ans);
    }
    return 0;
}
