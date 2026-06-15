
#include <iostream>
using namespace std;
#include <vector>
#include<algorithm>

// for DSU(Disjoint Set Union), we need parent and rank array
vector<int> parent(1000); // to track the parent of a node
vector<int> _rank(1000);  // to decide who will become parent during union

// to find the root of a node and make the root its parent
int find(int a)
{
    if (parent[a] == a) // found the root, return
    {
        return a;
    }
    // parent[a] is not the root, recursively call find and update the parent
    parent[a] = find(parent[a]);
    return parent[a];
}

// if union is possible, return true, otherwise return false
bool _union(int a, int b)
{
    // root_a and root_b are the roots of a and b
    int root_a = find(a);
    int root_b = find(b);

    if (root_a != root_b)
    {
        if (_rank[root_a] >= _rank[root_b])
        {
            parent[root_b] = root_a;
        }
        else
        {
            parent[root_a] = root_b;
        }
        return true;
    }
    return false;
}

struct edge
{
    char u;     // start node
    char v;     // end node
    int weight; // weight
};

// n is number of nodes, m is number of edges
int n, m;
// edge list to sort
vector<edge> edges;

// custom sort

bool customSort(struct edge &a, struct edge &b)
{
    // do not want swap
    if (a.weight < b.weight)
        return true;

    return false;
}

int main()
{
    cin >> n; // input the node amount
    cin >> m; // input the edge amount

    // input the edges
    for (int i = 0; i < m; i++)
    {
        struct edge e;
        cin >> e.u >> e.v >> e.weight;
        edges.push_back(e);
    }
    // initialize the DSU
    for (int i = 0; i < 1000; i++)
    {
        // initially everyone has rank 0 and parent as itself
        parent[i] = i;
        _rank[i] = 0;
    }
    // step_1: sort the edges
    sort(edges.begin(),edges.end(),customSort);

    int cost=0;
    for(int i=0;i<m;i++)
    {
        if(_union(edges[i].u,edges[i].v))
        {
            // ther merge was possible, roots weren't the same
            cost+=edges[i].weight;

        }
    }

    cout<<cost<<endl;



}