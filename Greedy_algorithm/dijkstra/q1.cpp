#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> adj[1005];   // adjacency list: {neighbor, drive_time}
int wait_times[1005];
int distance_map[1005];
bool locked[1005];
int n, m;

void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
    
    // Starting node: no waiting time added yet
    distance_map[start] = 0;          // or wait_times[start] if you want to include it
    min_heap.push({0, start});

    while (!min_heap.empty())
    {
        pair<int, int> top = min_heap.top();
        int min_weight = top.first;
        int u = top.second;
        min_heap.pop();

        if (locked[u]) continue;
        locked[u] = true;

        // Update distance (in case of duplicate entries)
        if (min_weight < distance_map[u])
            distance_map[u] = min_weight;

        for (auto& edge : adj[u])
        {
            int v = edge.first;
            int drive_time = edge.second;
            if (locked[v]) continue;

            // === MODIFIED LINE FOR PIZZA PROBLEM ===
            int new_cost = min_weight + drive_time + wait_times[v];

            if (new_cost < distance_map[v])
            {
                distance_map[v] = new_cost;
                min_heap.push({new_cost, v});
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    // Read wait times (1-indexed)
    for(int i = 1; i <= n; i++)
        cin >> wait_times[i];

    // Read edges
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});   // undirected
    }

    // Initialize distances
    for(int i = 1; i <= n; i++)
    {
        distance_map[i] = 1e9;
        locked[i] = false;
    }

    dijkstra(1);   // start from pizza shop

    cout << "Minimum time to deliver pizza: " << distance_map[n] << endl;

    return 0;
}