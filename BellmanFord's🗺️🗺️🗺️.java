import java.io.*;
import java.util.*;

class BellmanFords
{
    public static void main(String args[])throws IOException
    {
        ArrayList<PAIR> pairs = new ArrayList<>();
        pairs.add(new PAIR(0, 1, 1));
        pairs.add(new PAIR(1, 2, 1));
        pairs.add(new PAIR(2, 3, 3));
        pairs.add(new PAIR(3, 4, 1));
        pairs.add(new PAIR(0, 4, 7));
        calc(pairs, 0, 4, 5);
    }
    
    public static void calc(ArrayList<PAIR> pairs, int source, int target, int no_of_nodes)
    {
        int distances[] = new int[no_of_nodes];
        Arrays.fill(distances, Integer.MAX_VALUE);
        distances[source] = 0;
        for(int i = 0; i < no_of_nodes - 1; i++)
        {
            for(int j = 0; j < pairs.size(); j++)
            {   
                if(distances[pairs.get(j).source] != Integer.MAX_VALUE && distances[pairs.get(j).source] + pairs.get(j).weight < distances[pairs.get(j).target])
                distances[pairs.get(j).target] = distances[pairs.get(j).source] + pairs.get(j).weight;
            }
        }
        for(int j = 0; j < pairs.size(); j++)
        {   
            if(distances[pairs.get(j).source] != Integer.MAX_VALUE && distances[pairs.get(j).source] + pairs.get(j).weight < distances[pairs.get(j).target])
            {
                System.out.println("negative cycle detected!");
                return;
            }
        }
        System.out.println("shortest path from source = " + source + " to target = " + target + " is = " + distances[target]);
    }
}

class PAIR
{
    int source;
    int target;
    int weight;
    PAIR(int source, int target, int weight)
    {
        this.source = source;
        this.target = target;
        this.weight = weight;
    }
}
