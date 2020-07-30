// https://www.acmicpc.net/problem/2523
// 실습 (4), 별찍기 - 13
// NUMBER 2523

// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// Scanner scanner = new Scanner(System.in);

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Scanner;

public class Main {
    static int n;
    static StringBuilder sb;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            getStars(i, false);
        }
        for (int i = n - 2; i >= 0; i--) {
            if (i == 0)
                getStars(i, true);
            else
                getStars(i, false);
        }
        System.out.println(sb);
        scanner.close();
    }

    static void getStars(int i, boolean isLast) {
        for (int j = 0; j < i; j++)
            sb.append(" ");
        for (int k = 0; k < 2 * n - 1 - (i * 2); k++)
            sb.append("*");

        if (!isLast)
            sb.append("\n");
    }
}
