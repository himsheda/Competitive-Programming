#include<bits/stdc++.h>
using namespace std;

// implement a graph class with all functionality
//  implement bfs and dfs in the graph
//  implement a function to find the shortest path between two nodes
class Graph{
    int V;
    list<int> *adj;
    public:
    Graph(int V);
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void BFS(int s){
        bool *visited = new bool[V];
        for(int i=0;i<V;i++){
            visited[i] = false;
        }
        list<int> queue;
        visited[s] = true;
        queue.push_back(s);
        list<int>::iterator i;
        while(!queue.empty()){
            s = queue.front();
            cout<<s<<" ";
            queue.pop_front();
            for(i=adj[s].begin();i!=adj[s].end();i++){
                if(!visited[*i]){
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
    }
    void DFSUtil(int s, bool visited[]){
        visited[s] = true;
        cout<<s<<" ";
        list<int>::iterator i;
        for(i=adj[s].begin();i!=adj[s].end();i++){
            if(!visited[*i]){
                DFSUtil(*i, visited);
            }
        }
    }
    //  implement a function to find the shortest path between two nodes

};

int main(){
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }


    
    int p=arr[0];
    int l=1;
    for(int i=1;i<n;i++){
        if(arr[i]!=p){
            arr[l]=arr[i];
            l++;
            p=arr[i];
        }

    }
    cout<<l<<endl;
    for(int i=0;i<l;i++){
        cout<<arr[i]<<" ";
    }
}