#include <iostream>
#include <vector>

typedef struct
{
    int source;
    int target;
    int weight;
}PAIR;

void shortestPath(std::vector<PAIR>& pairs, int source, int target, int no_of_nodes)
{
    std::vector<int> distances(no_of_nodes, INT_MAX); distances[source] = 0;
    for(int i = 0; i < no_of_nodes - 1; i++)
    {
        for(int j = 0; j < pairs.size(); j++)
        {
            if(distances[pairs[j].source] != INT_MAX && distances[pairs[j].source] + pairs[j].weight < distances[pairs[j].target])
            distances[pairs[j].target] = distances[pairs[j].source] + pairs[j].weight;
        }
    }
    for(int j = 0; j < pairs.size(); j++)
    {
        if(distances[pairs[j].source] + pairs[j].weight < distances[pairs[j].target])
        {
            std::cout << "negative cycle found in the graph!" << std::endl;
        }
    }
    std::cout << "shortest distance from source = " << source << " to target = " << target << " is = " << distances[target] << std::endl;
}

int main()
{
    std::vector<PAIR> pairs;
    pairs.push_back({0 , 1 , 1});
    pairs.push_back({0 , 2 , 4});
    pairs.push_back({1 , 2 , 2});
    pairs.push_back({2 , 3 , 4});
    pairs.push_back({3 , 4 , 10});
    shortestPath(pairs, 0, 4, 5);
    return 0;
}
