#include <bits/stdc++.h>

char convert(int digit, int p) {
        switch (digit / p) {
                case 0: return '0';
                case 1: return '1';
                case 2: return '2';
                case 3: return '3';
                case 4: return '4';
                case 5: return '5';
                case 6: return '6';
                case 7: return '7';
                case 8: return '8';
                case 9: return '9';
                case 10: return 'A';
                case 11: return 'B';
                case 12: return 'C';
                case 13: return 'D';
                case 14: return 'E';
                case 15: return 'F';
        }
}


int main () {
        long long n;
        scanf("%lld", &n);
        char result[50];
        int i = 1;
        while (n > 0) {
                int powe = pow(16, i);
                int p = pow(16, i-1);
                int digitdeci = n % powe;
                n -= digitdeci;
                char digithexa = convert(digitdeci, p);
                result[i] = digithexa;
                i++;
        }
        for (int j = i-1; j >= 1; j--) printf("%c", result[j]);
        printf("\n");
        return 0;
}
