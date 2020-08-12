// https://www.acmicpc.net/problem/2407
// NUMBER 2407, 조합

// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// Scanner sc = new Scanner(System.in);
// Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static StringBuilder sb = new StringBuilder();
    static int size;
    static int[] iMove = { 1, 2, 2, 1, -1, -2, -2, -1 };
    static int[] jMove = { -2, -1, 1, 2, 2, 1, -1, -2 };
    static boolean[][] visited;
    static Queue<int[]> queue;
    static int[] target;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());
        for (int k = 0; k < t; k++) {
            size = Integer.parseInt(br.readLine());
            int[] temp = parseIntArr(br.readLine().split(" "));
            int[] start = { temp[0], temp[1], 0, -1 };
            target = parseIntArr(br.readLine().split(" "));

            if (start[0] == target[0] && start[1] == target[1]) {
                sb.append(0 + "\n");
            }

            visited = new boolean[300][300];
            visited[start[0]][start[1]] = true;
            queue = new LinkedList<>();
            queue.offer(start);
            bfs();
        }

        System.out.println(sb);
    }

    static void bfs() {
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            for (int p = 0; p < 8; p++) {
                if (p == cur[3])
                    continue;

                int iNext = cur[0] + iMove[p];
                int jNext = cur[1] + jMove[p];

                if (iNext == target[0] && jNext == target[1]) {
                    sb.append(cur[2] + 1 + "\n");
                    return;
                }

                if (iNext >= 0 && iNext < size && jNext >= 0 && jNext < size && !visited[iNext][jNext]) {
                    queue.offer(new int[] { iNext, jNext, cur[2] + 1, p > 3 ? p - 4 : p + 4 });
                    visited[iNext][jNext] = true;
                }
            }
        }
    }

    static int[] parseIntArr(String[] strArr) {
        return Arrays.stream(strArr).mapToInt(Integer::parseInt).toArray();
    }
}