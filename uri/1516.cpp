#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m;
    char chr;
    while (1) {
        scanf("%d%d%c", &n, &m, &chr);
        if (m == 0 and n == 0) break;
        vector <vector <int> > obj;
        for (int i = 0; i < n; i++) {
            vector <int> line;
            for (int j = 0; j < m; j++) {
                scanf("%c", &chr);
                line.push_back(chr);
            }
            scanf("%c", &chr);
            obj.push_back(line);
        }

        int n2, m2, fn, fm;
        scanf("%d%d%c", &n2, &m2, &chr);
        vector <vector <int> > newobj;
        if (m2 >= m)  fm = m2 / m;
        else          fm = -m / m2;
        if (n2 >= n)  fn = n2 / n;
        else          fn = -n / n2;

        for (int i = 0; i < n2; i++) {
            vector <int> line;
            for (int j = 0; j < m2; j++) {
                int oldi, oldj;
                if (fn >= 1) oldi = i/fn; else oldi = -fn*i;
                if (fm >= 1) oldj = j/fm; else oldj = -fm*j;
                line.push_back(obj[oldi][oldj]);
            }
            newobj.push_back(line);
        }

        for (int i = 0; i < n2; i++) {
            for (int j = 0; j < m2; j++) {
                printf("%c", newobj[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
