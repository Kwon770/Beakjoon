// https://www.acmicpc.net/problem/2407
// NUMBER 2407, 조합

// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// Scanner sc = new Scanner(System.in);
// Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Main {
    static ArrayList<Route> routes[] = new ArrayList[1001];
    static int[] dist = new int[1001];
    static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        Arrays.fill(dist, Integer.MAX_VALUE);
        for (int i = 1; i <= n; i++)
            routes[i] = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            int[] input = parseIntArr(br.readLine().split(" "));
            routes[input[0]].add(new Route(input[1], input[2]));
        }

        int[] course = parseIntArr(br.readLine().split(" "));

        dijkstra(course[0]);
        System.out.println(dist[course[1]]);
    }

    static void dijkstra(int start) {
        PriorityQueue<Route> queue = new PriorityQueue<>();
        queue.add(new Route(start, 0));
        dist[start] = 0;

        while (!queue.isEmpty()) {
            // polled route is the route from itself to itself
            Route route = queue.poll();

            for (int i = 0; i < routes[route.target].size(); i++) {
                Route nextRoute = routes[route.target].get(i);

                // nextRoute.target: next destination, route.target: current position,
                // routes[route.target].get(i): the route from current position to destination
                if (dist[nextRoute.target] > dist[route.target] + routes[route.target].get(i).value) {
                    dist[nextRoute.target] = dist[route.target] + routes[route.target].get(i).value;
                    queue.add(new Route(nextRoute.target, dist[nextRoute.target]));
                }
            }
        }
    }

    static int[] parseIntArr(String[] strArr) {
        return Arrays.stream(strArr).mapToInt(Integer::parseInt).toArray();
    }

    public static class Route implements Comparable<Route> {
        int target;
        int value;

        public Route(int tar, int val) {
            this.target = tar;
            this.value = val;
        }

        // ascending order
        @Override
        public int compareTo(Route c) {
            if (this.value < c.value)
                return 1;
            return 0;
        }
    }
}
