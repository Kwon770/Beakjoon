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

        int even, odd;
        if (n % 2 == 1) {
            odd = n / 2 + 1;
            even = n / 2;
        } else {
            even = n / 2;
            odd = n / 2;
        }

        for (int i = 1; i <= (n == 1 ? 1 : n * 2); i++) {
            if (i % 2 == 1) {
                for (int j = 0; j < odd; j++) {
                    sb.append("* ");
                }
            } else {
                for (int j = 0; j < even; j++) {
                    sb.append(" *");
                }
            }
            sb.append("\n");
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
