
#include<iostream>
#include<vector>
using namespace std;

int m; //edge count
int n; // node count

//<neighbor node, weight> pairs for a node u will be saved at adj[u]
vector<pair<int,int>>adj[1000]; // max 1000 nodes
int dist[1000]; // distance from source


/// relax every edge once in this function
void relaxation_cycle()
{
    for(int u=1;u<=n;u++) // for every node
    {
        for(auto it:adj[u]) // every edge for a node
        {
            // auto it means pair
            int v=it.first;
            int weight= it.second;
            //relaxation
            if(dist[u]+weight<dist[v])
            {
                dist[v]=dist[u]+weight;
            }
        }

    }
}
bool Negative_cycle(){
     for(int u=1;u<=n;u++) // for every node
    {
        for(auto it:adj[u]) // every edge for a node
        {
            // auto it means pair
            int v=it.first;
            int weight= it.second;
            //relaxation
            if(dist[u]+weight<dist[v])
            {
                return true;
            }
        }

    }
    return false;
}

void bellman_ford(int source)
{
    dist[source]=0;
    for(int i=0;i<n-1;i++)
        relaxation_cycle();

}


int main()
{int s;
    cin>>n>>m>>s;

    for(int i=0;i<m;i++)
    {
        int u,v,weight;
        cin>>u>>v>>weight;
        adj[u].push_back({v,weight});
    }
    // initialization
    for(int i=1;i<=n;i++)
        dist[i]=100000000; // infinite distance

   
    bellman_ford(s);
  if(Negative_cycle())
    {
        cout<<"Negative cycle detected."<<endl;
    }
    else
    {
        cout<<"No negative cycle detected."<<endl;
    }
      for(int i=1;i<=n;i++)
        {
            if(i==s) continue;

            if(dist[i]==100000000)
                cout<<i<<" unreachable"<<endl;
            else
                cout<<i<<" "<<dist[i]<<endl;
        }
    




}



 