import java.util.*;

public class Main {

    static class Pair
    {
        int first, second;

        public Pair(int first, int second)
        {
            this.first = first;
            this.second = second;
        }
    }

    static final int infinity = 1000000000;

    static class Node
    {
        int vertexNumber;

        // Adjacency list that shows the
        // vertexNumber of child vertex
        // and the weight of the edge
        List<Pair> children;

        Node(int vertexNumber)
        {
            this.vertexNumber = vertexNumber;
            children = new ArrayList<>();
        }

        // Function to add the child for
        // the given node
        void add_child(int vNumber, int length)
        {
            Pair p = new Pair(vNumber, length);
            children.add(p);
        }
    }

    // Function to find the distance of
// the node from the given source
// vertex to the destination vertex
    static int[] dijkstraDist(List<Node> g, int s, int[] path)
    {

        // Stores distance of each
        // vertex from source vertex
        int[] dist = new int[g.size()];

        // Boolean array that shows
        // whether the vertex 'i'
        // is visited or not
        boolean[] visited = new boolean[g.size()];
        for(int i = 0; i < g.size(); i++)
        {
            visited[i] = false;
            path[i] = -1;
            dist[i] = infinity;
        }
        dist[s] = 0;
        path[s] = -1;
        int current = s;

        // Set of vertices that has
        // a parent (one or more)
        // marked as visited
        Set<Integer> sett = new HashSet<>();
        while (true)
        {

            // Mark current as visited
            visited[current] = true;
            for(int i = 0; i < g.get(current).children.size(); i++)
            {
                int v = g.get(current).children.get(i).first;

                if (visited[v])
                    continue;

                // Inserting into the
                // visited vertex
                sett.add(v);
                int alt = dist[current] + g.get(current).children.get(i).second;

                // Condition to check the distance
                // is correct and update it
                // if it is minimum from the previous
                // computed distance
                if (alt < dist[v])
                {
                    dist[v] = alt;
                    path[v] = current;
                }
            }
            sett.remove(current);

            if (sett.isEmpty())
                break;

            // The new current
            int minDist = infinity;
            int index = 0;

            // Loop to update the distance
            // of the vertices of the graph
            for(int a : sett)
            {
                if (dist[a] < minDist)
                {
                    minDist = dist[a];
                    index = a;
                }
            }
            current = index;
        }
        return dist;
    }

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();//broj testove

        int N;//broj gradove
        int M;//broj putishta

        int startCity;//na4alen grad
        int endCity;//kraen grad
        int km;//razstoqnie(km) mejdu 2 grada(teglo)

        while(T-->0)
        {
            N = scanner.nextInt();
            M = scanner.nextInt();

            List<Node> cities = new ArrayList<>();
            //int n = 6, s = 0, e = 8;
            int s=0;
            // suzdavame vuzlite na grafa(gradovete)
            for(int i = 0; i < N; i++)
            {
                Node a = new Node(i);
                cities.add(a);
            }

            // suzdavame putq mejdu vuzlite(gradovete)
            while (M-->0)
            {
                startCity = scanner.nextInt();
                endCity = scanner.nextInt();
                km = scanner.nextInt();
                cities.get(startCity-1).add_child(endCity-1,km);
            }
            int[] path = new int[cities.size()];
            int[] dist = dijkstraDist(cities, s, path);

            System.out.print(dist[dist.length-1]);
        }
    }
}