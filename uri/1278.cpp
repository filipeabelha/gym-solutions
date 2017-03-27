#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    int first = 1;
    char chr;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%c", &chr);
        vector <vector <int> > obj;
        vector <int> linesizes;
        int maxlinesize = 0;
        for (int j = 0; j < n; j++) {
            vector <int> line;
            while (1) {
                scanf("%c", &chr);
                if (chr == 10) break;
                line.push_back(chr);
            }

            /*---Tirando no começo e no fim---*/
            while (line[0] == 32) line.erase(line.begin(), line.begin()+1);
            int last = line.size() - 1;
            while (line[last] == 32)
                line.erase(line.begin()+last, line.begin()+last+1),
                    last = line.size() - 1;
            /*---Tirando no meio--------------*/
            for (int i = 0; i < line.size(); i++) {
                if (line[i] == 32 and line[i+1] == 32) {
                    line.erase(line.begin()+i+1, line.begin()+i+2);
                    i = -1;
                }
            }
            /*--------------------------------*/

            linesizes.push_back(line.size());
            if (linesizes[j] > maxlinesize) maxlinesize = linesizes[j];

            obj.push_back(line);
        }
        if (!first) printf("\n");
        first = 0;
        for (int j = 0; j < obj.size(); j++) {
            for (int i = 0; i < maxlinesize - linesizes[j]; i++)
                printf(" ");
            for (int i = 0; i < linesizes[j]; i++)
                printf("%c", obj[j][i]);
            printf("\n");
        }
    }
    return 0;
}
