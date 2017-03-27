#include <bits/stdc++.h>
using namespace std;

int m[1005][1005], len1, len2;
string s1, s2;

int main () {
    while (getline(cin,s1)) {
        getline(cin,s2);
        len1 = s1.size();
        len2 = s2.size();
        if (!len1 or !len2) printf("0\n"); else {
            for (int i = 1; i <= len1; i++)
                for (int j = 1; j <= len2; j++)
                    if (s1[i-1] == s2[j-1])
                        m[i][j] = 1 + m[i-1][j-1];
                    else
                        m[i][j] = max(m[i][j-1], m[i-1][j]);
            printf("%d\n", m[len1][len2]);
        }
    }
    return 0;
}
