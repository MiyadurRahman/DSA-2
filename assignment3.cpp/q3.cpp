#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/// adj: an array of vector
/// adj[i]: there is a vector at adj[i], which stores the neighbors for node i
vector<pair<int, int>> adj[1000]; // for 1000 nodes
int n;   // node count
int k;     //capacity                   
bool locked[1000];                // to track the locked nodes, initially all false

/// a distance map for dijkstra===================== UPDATE - 1 FROM PRIMS
int distance_map[1000];

void dijkstra(int start)
{
    // pair because pair<key,label> for each node
    // to convert max heap to min heap heap, add: vector<type>, greater<type>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
    // for start node, key is 0
    min_heap.push({0, start});
    while (!min_heap.empty())
    {
        pair<int, int> min_node = min_heap.top();
        /// pop
        min_heap.pop();
        int min_weight = min_node.first;
        int min_label = min_node.second;
        /// lock
        if (locked[min_label] == true) // already locked, this node was processed prior
        {
            continue;
        }
        locked[min_label] = true; // first, lock it
        /// UPDATE-3: update the distance map instead of cost
        if (distance_map[min_label] > min_weight)
            distance_map[min_label] = min_weight;

        // e represents all the <neighbor,weight> pairs for min label
        // push the neighbors inside heap
        for (auto e : adj[min_label])
        {
            int neighbor = e.first;
            int weight = e.second;
            if (locked[neighbor] == true) // neighbor locked, so don't change
                continue;
            min_heap.push({min_weight + weight, neighbor}); /// update and push : for dijkstra, push min_key+weight =========== UPDATE-2
        }
    }
}

int main()
{
    int m;
    cin >> n >> m>>k; // n is node count, m is edge count

    for (int i = 0; i < m; i++)
    {
        int u, v, d,c; // u: start node, v:end node, weight: edge weight
        cin >> u >> v >>d>>c;
        // undirected graph
        if(c>=k){
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
        }
    }
    /// initialize the distance map for dijkstra
    for (int i = 0; i <= n; i++)
    {
        distance_map[i] = 1000000;
        
    }

    dijkstra(1); // source node: 1        =================
    cout << "distances:" << endl;

dijkstra(1);

    if (distance_map[n] == 1000000)
        cout << -1 << endl;
    else
        cout << distance_map[n] << endl;
}
