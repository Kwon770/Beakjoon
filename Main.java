// https://www.acmicpc.net/problem/2407
// NUMBER 2407, 조합

// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// Scanner sc = new Scanner(System.in);
// Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        int[][] dist = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = i == j ? 0 : Integer.MAX_VALUE;
            }
        }

        for (int i = 1; i <= m; i++) {
            int[] input = parseIntArr(br.readLine().split(" "));
            dist[input[0]][input[1]] = Math.min(dist[input[0]][input[1]], input[2]);
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                // Skip unnecessary stage and prevent overflow by adding with MAXVAL
                if (dist[i][k] == Integer.MAX_VALUE)
                    continue;
                for (int j = 1; j <= n; j++) {
                    // Skip unnecessary stage and prevent overflow by adding with MAXVAL
                    if (dist[k][j] == Integer.MAX_VALUE || i == j)
                        continue;

                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] == Integer.MAX_VALUE) {
                    sb.append("0 ");
                } else {
                    sb.append(dist[i][j] + " ");
                }
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }

    static int[] parseIntArr(String[] strArr) {
        return Arrays.stream(strArr).mapToInt(Integer::parseInt).toArray();
    }
}
