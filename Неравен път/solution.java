import java.util.*;

public class Main {
    static final int MAXN = 1005;
    static int[][] a = new int[MAXN][MAXN];
    static boolean[][] used = new boolean[MAXN][MAXN];
    static int n, m;
    static int[] x1 = {-1, 0, -1, 1, -1, 0};
    static int[] y1 = {-1, -1, 0, 0, 1, 1};
    static int[] x2 = {0, 1, -1, 1, 0, 1};
    static int[] y2 = {-1, -1, 0, 0, 1, 1};

    static class Node 
    {
        int x, y;
        long d;

        Node(int _x, int _y, long _d) 
        {
            x = _x;
            y = _y;
            d = _d;
        }
    }

    static class Cmp implements Comparator<Node> 
    {
        public int compare(Node lhs, Node rhs) 
        {
            return Long.compare(lhs.d, rhs.d);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();

        for (int j = 0; j < m; j++) 
        {
            for (int i = 0; i < n; i++) 
            {
                a[i][j] = sc.nextInt();
            }
            if (j % 2 == 1) 
            {
                a[n][j] = sc.nextInt();
            } else 
            {
                a[n][j] = 0;
            }
        }
        n++;

        PriorityQueue<Node> pq = new PriorityQueue<Node>(new Cmp());

        for (int j = 0; j < m; j++) 
        {
            pq.offer(new Node(0, j, Math.abs(a[0][j])));
        }

        while (!pq.isEmpty()) 
        {
            Node curr = pq.poll();
            if (curr.x == -1 && curr.y == -1) 
            {
                System.out.println(curr.d);
                return;
            }
            if (used[curr.x][curr.y])
                continue;
            used[curr.x][curr.y] = true;

            for (int i = 0; i < 6; i++) 
            {
                int xx, yy;
                if (curr.y % 2 == 1) 
                {
                    xx = curr.x + x1[i];
                    yy = curr.y + y1[i];
                } else 
                {
                    xx = curr.x + x2[i];
                    yy = curr.y + y2[i];
                }
                if (xx >= 0 && yy >= 0 && xx < n && yy < m) 
                {
                    if (!used[xx][yy])
                        pq.offer(new Node(xx, yy, curr.d + Math.abs(a[curr.x][curr.y] - a[xx][yy])));
                } else if (xx == n) 
                {
                    pq.offer(new Node(-1, -1, curr.d + Math.abs(a[curr.x][curr.y])));
                }
            }
        }
    }
}