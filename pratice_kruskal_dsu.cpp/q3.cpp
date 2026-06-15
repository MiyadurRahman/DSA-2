#include <iostream>
using namespace std;
#include <vector>
#include<algorithm>
#include <climits>      // ========== CHANGE : For INT_MAX ==========

// for DSU
vector<int> parent(1000);
vector<int> _rank(1000);

int find(int a)
{
    if (parent[a] == a)
    {
        return a;
    }
    parent[a] = find(parent[a]);
    return parent[a];
}

bool _union(int a, int b)
{
    int root_a = find(a);
    int root_b = find(b);

    if (root_a != root_b)
    {
        if (_rank[root_a] > _rank[root_b])
        {
            parent[root_b] = root_a;
        }
        else if (_rank[root_a] < _rank[root_b])
        {
            parent[root_a] = root_b;
        }
        else
        {
            parent[root_b] = root_a;
            _rank[root_a]++;
        }
        return true;
    }
    return false;
}

struct edge
{
    char u;
    char v;
    int weight;
};

int n, m;
vector<edge> edges;

bool customSort(struct edge &a, struct edge &b)
{
    return a.weight > b.weight;     // ========== CHANGE : Descending order ==========
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        struct edge e;
        cin >> e.u >> e.v >> e.weight;
        edges.push_back(e);
    }

    for (int i = 0; i < 1000; i++)
    {
        parent[i] = i;
        _rank[i] = 0;
    }

    sort(edges.begin(), edges.end(), customSort);

    // ========== CHANGE : For Maximum Spanning Tree Bottleneck ==========
    int min_capacity = INT_MAX;

    for(int i = 0; i < m; i++)
    {
        if(_union(edges[i].u, edges[i].v))
        {
            if(edges[i].weight < min_capacity)
                min_capacity = edges[i].weight;
        }
    }

    cout << min_capacity << endl;

    return 0;
}