// https://www.acmicpc.net/problem/2407
// NUMBER 2407, 조합

// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// Scanner sc = new Scanner(System.in);
// Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
// StringBuilder sb = new StringBuilder();

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static int v;
    static int e;
    static int[][] dist;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] input = parseIntArr(br.readLine());
        v = input[0];
        e = input[1];

        dist = new int[v + 1][v + 1];
        for (int[] arr : dist)
            Arrays.fill(arr, Integer.MAX_VALUE);

        for (int i = 0; i < e; i++) {
            input = parseIntArr(br.readLine());
            dist[input[0]][input[1]] = input[2];
        }

        floyd();

        System.out.println(returnMinCycle());
    }

    static void floyd() {
        for (int k = 1; k <= v; k++) {
            for (int i = 1; i <= v; i++) {
                // if: i == k || i -/-> k
                if (dist[i][k] == Integer.MAX_VALUE)
                    continue;

                for (int j = 1; j <= v; j++) {
                    // if: i == j || k == j || k -/-> j
                    if (i == j || dist[k][j] == Integer.MAX_VALUE)
                        continue;

                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }

            }
        }
    }

    static int returnMinCycle() {
        int cycle = Integer.MAX_VALUE;
        for (int i = 1; i <= v; i++) {
            // j will start from (i + 1) to avoid overlap loop
            for (int j = i + 1; j <= v; j++) {
                // if: i == j || i -/-> j || j -/-> i
                if (dist[i][j] == Integer.MAX_VALUE || dist[j][i] == Integer.MAX_VALUE)
                    continue;

                cycle = Math.min(cycle, dist[i][j] + dist[j][i]);
            }
        }

        return cycle == Integer.MAX_VALUE ? -1 : cycle;
    }

    static int[] parseIntArr(String input) {
        return Arrays.stream(input.split(" ")).mapToInt(Integer::parseInt).toArray();
    }
}
