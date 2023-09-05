#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define MAXN 100005
using namespace std;

int g_nodes, g_edges, max_edges;
int g_from[MAXN], g_to[MAXN], g_weight[MAXN];
int dist[MAXN];
bool used[MAXN];
vector<pair<int, int> > adj[MAXN];

void dijkstra(int s) {
    fill(dist, dist + g_nodes, INF);
    fill(used, used + g_nodes, false);
    dist[s] = 0;

    priority_queue<pair<int, int> > q;
    q.push(make_pair(0, s));

    while (!q.empty()) {
        int v = q.top().second;
        q.pop();
        if (used[v]) continue;
        used[v] = true;

        for (int i = 0; i < adj[v].size(); i++) {
            int to = adj[v][i].first, weight = adj[v][i].second;
            if (dist[to] > max(dist[v], weight)) {
                dist[to] = max(dist[v], weight);
                q.push(make_pair(-dist[to], to));
            }
        }
    }
}

int getMinCost(int max_edges, int g_nodes, int g_edges, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    // ::g_nodes = g_nodes;
    // ::g_edges = g_edges;
    // ::max_edges = max_edges;
    for (int i = 0; i < g_edges; i++) {
        ::g_from[i] = g_from[i];
        ::g_to[i] = g_to[i];
        ::g_weight[i] = g_weight[i];
        adj[g_from[i]].push_back(make_pair(g_to[i], g_weight[i]));
    }
    dijkstra(0);
    if (dist[g_nodes - 1] == INF) return -1;
    return dist[g_nodes - 1];
}
int main(){
    int g_nodes, g_edges, max_edges;
    cin>>max_edges;
    cin>>g_nodes>>g_edges;
    vector<int> g_from(g_edges+1), g_to(g_edges+1), g_weight(g_edges+1);
    for(int i=0;i<g_edges;i++){
        cin>>g_from[i]>>g_to[i]>>g_weight[i];
    }
    for(int i=0;i<g_edges;i++)
        cerr<<g_from[i]<<" "<<g_to[i]<<" "<<g_weight[i]<<endl;
    cout<<getMinCost(max_edges, g_nodes, g_edges, g_from, g_to, g_weight);
}
