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
    // static StringBuilder sb = new StringBuilder();
    static int[] cities = new int[1001];
    static int[][] routesMap = new int[1001][1001];
    static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Arrays.fill(cities, Integer.MAX_VALUE);
        for (int[] routes : routesMap)
            Arrays.fill(routes, -1);

        n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        for (int i = 0; i < m; i++) {
            int[] route = parseIntArr(br.readLine().split(" "));
            routesMap[route[0]][route[1]] = route[2];
        }

        int[] course = parseIntArr(br.readLine().split(" "));

        dijkstra(course[0]);
        System.out.println(cities[course[1]]);
    }

    static void dijkstra(int start) {
        Queue<Integer> queue = new LinkedList<>();
        cities[start] = 0;
        queue.offer(start);

        while (!queue.isEmpty()) {
            int from = queue.poll();
            for (int to = 1; to <= n; to++) {
                if (routesMap[from][to] == -1)
                    continue;

                if (cities[to] > cities[from] + routesMap[from][to])
                    cities[to] = cities[from] + routesMap[from][to];

                queue.offer(to);
            }
        }
    }

    static int[] parseIntArr(String[] strArr) {
        return Arrays.stream(strArr).mapToInt(Integer::parseInt).toArray();
    }
}