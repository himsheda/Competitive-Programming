#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define pip pair<int,pii>
#define ppi pair<pii,int>
#define ppp pair<p,p> 
#define vpi vector<pii>
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
 
#define trav(i,x) for(auto& i:x)
#define sz(a) ((int)(a).size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define tr(c, it) for (auto it = (c).begin(); (it) != (c).end(); it++)
#define check(c, val) ((c).find(val) != (c).end())      // for sets, multisets, maps etc.
#define ccheck(c, val) (find((c).begin(), (c).end(), val) != (c).end()) // for others
 
#define pb push_back
#define F first
#define S second
 
#define ff(i, a, b) for(int i = (a);i < (b); i++)
#define fF(i, a, b, c) for(int i = (a);i < (b); i+=(c))
#define fb(i, a, b) for(int i = (b); i >= (a); i--)
#define fB(i, a, b, c) for(int i = (b); i >= (a); i-=(c))
#define fo(i, n) forf(i, 0, n)
#define fob(i, n) forb(i, 0, n - 1)
 
template <class T> void show(vector<vector<T>> &a) {for (auto &i : a) { for (T &j : i) cout << j << ' ' ; cout << endl; } }
template <class T> void show(vector<vector<vector<T>>> &a) {for (auto &i : a) {show(i); } }
template <class T> void show(vector<T> &a) {for (T i : a) cout << i << ' ' ; cout << endl; }
template <class T> void show(vector<pair<T, T>>&a) {trav(i,a) {cout << i.F << ' ' << i.S << endl;}}
template <class T> void show(pair<T, T>p) {cout << p.F << ' ' << p.S << endl;}
void show(vector<string>&a) {trav(i,a) cout << i << endl;}
template<class T> void take(vector<T>&a) {trav(i,a) cin >> i;}
 
const int INF = 9e18;
const int mod = 7+1e9;
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};
void init_code(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
class binary_lifting{
public:
    int n, l;
    vector<vector<int>>up;
    vector<int>depth;
    binary_lifting(int n,vector<vector<int>>&adj,int root){
        this->n = n;
        this->l = ceil(log2(n))+1;
        up.resize(n, vector<int>(l));
        depth.resize(n);
        dfs(root,root, adj);
        for(int i = 1; i < l; i++){
            for(int j = 0; j < n; j++){
                up[j][i] = up[up[j][i - 1]][i - 1];
            }
        }
    }
    void dfs(int u, int p, vector<vector<int>>&adj){
        up[u][0] = p;
        for(int i = 1; i < l; i++){
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
        for(int v : adj[u]){
            if(v != p){
                depth[v] = depth[u] + 1;
                dfs(v, u, adj);
            }
        }
    }
    int lca(int u, int v){
        if(depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for(int i = 0; i < l; i++){
            if((diff >> i) & 1) u = up[u][i];
        }
        if(u == v) return u;
        for(int i = l - 1; i >= 0; i--){
            if(up[u][i] != up[v][i]){
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }
    int dist(int u, int v){
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
    int kth_ancestor(int u, int k){
        if(k > depth[u]) return -1;
        for(int i = 0; i < l; i++){
            if((k >> i) & 1) u = up[u][i];
        }
        return u;
    }
};
void solve(){
    
}
int32_t main(){
    init_code();
    //cout << fixed << setprecision(1);
    int t=1;
    // cin>>t;
    while(t--){
       solve(); 
    }
    // TIME();
    return 0;
} 