#include <iostream>
#include<vector>
#include<queue>
using namespace std;
///adj:an array of vector
///adi[i]:there is a vector at adj[i],which stores the neghbours for node i
vector<pair<int,int>>adj[1000];//for 1000 nodes
int n;//node count
bool locked[1000];//to track the locked nodes,initially all false
int prims(int start){
    //pair because pair<weight,label> for each node
    //to convert max heap to min heap heap, we neeed to add vector<type,greater<type>
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>min_heap;
//for the start  node ,key is 0
min_heap.push({0,start});
int cost=0;
int locked_count=0;//for connectivity check
while(!min_heap.empty()){
    pair<int,int>min_node=min_heap.top();
    //pop
    min_heap.pop();
    int min_weight=min_node.first;
    int min_label=min_node.second;
    //lock
    if(locked[min_label]==true)//already locked ,this node was processed prior
    {
        continue;
    }
    locked[min_label]=true;//first,lockit
    locked_count++;
    cost+=min_weight;//add the cose;
    //e reresents all the <neighbour,weight>pairs for min lable
    //push the neighbours inside heap
    for(auto e:adj[min_label]){
        int neighbour=e.first;
        int weight=e.second;
        if(locked[neighbour])
        if(locked[neighbour]==true)//neighbour locked,so donot change
        {
            continue;
        }
        min_heap.push({weight,neighbour});//update and push
    }
   


}
 if (locked_count==n){
        cout<<"mst exsits"<<cost<<endl;
    }
    else{
        cout<<"graph is disconnected"<<endl;
        
    }
return cost;
}
int main(){
    int m;
    cin>>n>>m;//n is node count,m is edge count
    for (int i=0;i<m;i++){
        int u,v,weight;//u-->star node,v-->endnode,weight-->edge
    cin>>u>>v>>weight;
    //undirected graph
    adj[u].push_back({v,weight});
    adj[v].push_back({u,weight});


    
    }
    cout<<prims(1)<<endl;

}
