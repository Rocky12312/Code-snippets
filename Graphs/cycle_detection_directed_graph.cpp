//Detecting cycles in a directed graph
#include<bits/stdc++.h>

using namespace std;
const int N = 10000;
vector<int> graph[N];

void add_edges(int a,int b){
    graph[a].push_back(b);
}


bool isCyclic_util(vector<int> adj[], vector<int> visited, int curr)
{
    if(visited[curr]==true){
        return true;
    }
    visited[curr] = true;
    for(int i=0;i<adj[curr].size();++i)
    {
        if(isCyclic_util(adj,visited,adj[curr][i])){
            return true;
        }
    }
    return false;
}

bool isCyclic(vector<int> adj[], int V){
    vector<int> visited(V,false);
    for(int i=0;i<V;++i){
        if(visited[i] == false){
            if(isCyclic_util(adj,visited,i)){
                return true;
            }
        }
   }
   return false;
}


int main(){
    add_edges(0,1);
    add_edges(1,2);
    add_edges(2,3);
    add_edges(3,4);
    add_edges(4,5);
    add_edges(5,6);
    add_edges(6,2);
    //add_edges(7,1);
    //add_edges(4,1);
    cout << isCyclic(graph, 8)<<endl;
}