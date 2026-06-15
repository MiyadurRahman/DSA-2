#include <iostream>
using namespace std;
#include <vector>
#include<algorithm>

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
            _rank[root_a]++;        // ========== CHANGE : Proper Union by Rank ==========
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
    return a.weight < b.weight;
}

int main()
{
    cin >> n >> m;

    // input the edges
    for (int i = 0; i < m; i++)
    {
        struct edge e;
        cin >> e.u >> e.v >> e.weight;
        edges.push_back(e);
    }

    // ========== CHANGE : Read Pre-existing Satellite Connections ==========
    int sat;
    cin >> sat;
    for(int i = 0; i < sat; i++)
    {
        char x, y;
        cin >> x >> y;
        _union(x, y);        // already connected, cost = 0
    }

    // ========== CHANGE : Read Forced Political Route ==========
    char fu, fv;
    int fw;
    cin >> fu >> fv >> fw;

    // Initialize DSU
    for (int i = 0; i < 1000; i++)
    {
        parent[i] = i;
        _rank[i] = 0;
    }

    // ========== CHANGE : Union the forced edge and add its cost ==========
    _union(fu, fv);
    int cost = fw;

    // sort the edges
    sort(edges.begin(), edges.end(), customSort);

    for(int i = 0; i < m; i++)
    {
        if(_union(edges[i].u, edges[i].v))
        {
            cost += edges[i].weight;
        }
    }

    cout << cost << endl;

    return 0;
}