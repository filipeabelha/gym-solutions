import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

    public static void main (String[] args) throws IOException {

        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        final int N = 21;
        long[] f = new long[N];

        f[0] = f[1] = 1;
        for (int i = 2; i < N; i++) {
            f[i] = i*f[i-1];
        }

        while (true) {
            try {
                int a = Integer.parseInt(sc.next());
                int b = Integer.parseInt(sc.next());
                out.printf("%d\n", f[a]+f[b]);
            } catch (Exception e) {
                break;
            }
        }

        out.close();
    }

    public static PrintWriter out;

    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }
}
