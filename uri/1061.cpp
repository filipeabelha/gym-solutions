#include <bits/stdc++.h>

int main () {
        int du, hu, mu, su;
        int dd, hd, md, sd;

        scanf("Dia %d", &du);
        scanf("%d : %d : %d ", &hu, &mu, &su);
        scanf("Dia %d", &dd);
        scanf("%d : %d : %d", &hd, &md, &sd);

        int t1 = 0;
        t1 += su;
        t1 += mu*60;
        t1 += hu*60*60;
        t1 += du*60*60*24;

        int t2 = 0;
        t2 += sd;
        t2 += md*60;
        t2 += hd*60*60;
        t2 += dd*60*60*24;

        int dif = t2 - t1;

        int dr = dif/(60*60*24);
        dif -= dr*60*60*24;

        int hr = dif/(60*60);
        dif -= hr*60*60;

        int mr = dif/60;
        dif -= mr*60;

        int sr = dif;

        printf("%d dia(s)\n%d hora(s)\n%d minuto(s)\n%d segundo(s)\n", dr, hr, mr, sr);

        return 0;
}
