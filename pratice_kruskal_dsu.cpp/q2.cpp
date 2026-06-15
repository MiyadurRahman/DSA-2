#include <iostream>
using namespace std;
#include <vector>
#include <string>        // ========== CHANGE : Added for string input ==========

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

int main()
{
    int n, q;
    cin >> n >> q;           // ========== CHANGE : n = companies, q = events ==========

    // Initialize DSU
    for (int i = 0; i < 1000; i++)
    {
        parent[i] = i;
        _rank[i] = 0;
    }

    for(int i = 0; i < q; i++)
    {
        string type;
        char a, b;
        cin >> type >> a >> b;

        if(type == "MERGE")
        {
            _union(a, b);               // ========== CHANGE ==========
        }
        else if(type == "QUERY")
        {
            if(find(a) == find(b))      // ========== CHANGE ==========
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}