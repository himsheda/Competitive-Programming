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
#define trav(x) for(auto& i:x)
#define sz(a) ((int)(a).size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define tr(c, it) for (auto it = (c).begin(); (it) != (c).end(); it++)
#define pres(c, val) ((c).find(val) != (c).end())      // for sets, multisets, maps etc.
#define cpres(c, val) (find((c).begin(), (c).end(), val) != (c).end()) // for others
 
#define pb push_back
#define F first
#define S second
 
#define ff(i, a, b) for(int i = (a);i < (b); i++)
#define fb(i, a, b) for(int i = (b); i >= (a); i--)
#define fo(i, n) forf(i, 0, n)
#define fob(i, n) forb(i, 0, n - 1)
 
template <class T> void show(vector<vector<T>> &a) {for (auto &i : a) { for (T &j : i) cout << j << ' ' ; cout << endl; } }
template <class T> void show(vector<T> &a) {for (T i : a) cout << i << ' ' ; cout << endl; }
template <class T> void show(vector<pair<T, T>>&a) {trav(a) {cout << i.F << ' ' << i.S << endl;}}
template <class T> void show(pair<T, T>p) {cout << p.F << ' ' << p.S << endl;}
void show(vector<string>&a) {trav(a) cout << i << endl;}
template<class T> void take(vector<T>&a) {trav(a) cin >> i;}

const int INF = 9e18;
const int mod = 7+1e9;
 
void init_code(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
 
const auto start_time = std::chrono::high_resolution_clock::now();
 
void TIME() {
  #ifndef ONLINE_JUDGE
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end_time - start_time;
    cerr << "Time Taken: " << diff.count() << "s\n";
  #endif
}
int dis(pii &a,pii &b){
    return abs(a.F-b.F)+abs(a.S-b.S);
}
void solve(){
    int k;
    cin>>k;
    int sx,sy,fx,fy;
    cin>>sx>>sy>>fx>>fy;
    int n;
    cin>>n;
    pii src=make_pair(sx,sy);
    pii fns=make_pair(fx,fy);
    map<pii,int> mp1;
    vpi start(n),finish(n);
    int j=0;
    
    set<pii> st;

    ff(i,0,n){
        cin>>start[i].F>>start[i].S>>finish[i].F>>finish[i].S;
        st.insert(start[i]);
        st.insert(finish[i]);
    }

    st.insert(src);
    st.insert(fns);
    vector<pii> nodes(all(st));
    ff(i,0,sz(nodes)){
        mp1[nodes[i]]=i;
    }

    // cout<<k<<endl;
    int nd=sz(mp1);
    vvi adj(nd,vi(nd,INF));
    ff(i,0,n){
        adj[mp1[start[i]]][mp1[finish[i]]]=min(dis(start[i],finish[i]),k);
        adj[mp1[finish[i]]][mp1[start[i]]]=min(dis(start[i],finish[i]),k);
    }
    ff(i,0,sz(nodes)){
        ff(j,0,sz(nodes)){
            adj[i][j]=min(adj[i][j],dis(nodes[i],nodes[j]));
        }
    }
    // show(nodes);
    // show(adj);
    vi dist(nd,INF);
    dist[mp1[src]]=0;
    priority_queue<pii,vpi,greater<pii>> pq;
    pq.push({0,mp1[src]});
    while(!pq.empty()){
        pii p=pq.top();
        pq.pop();
        int u=p.S;
        int d=p.F;
        if(d>dist[u]) continue;
        for(int i=0;i<nd;i++){
            if(adj[u][i]==INF) continue;
            if(dist[i]>dist[u]+adj[u][i]){
                dist[i]=dist[u]+adj[u][i];
                pq.push({dist[i],i});
            }
        }
    }
    // show(dist);
    cout<<dist[mp1[fns]]<<endl;

    




}
int32_t main(){
    init_code();
    //cout << fixed << setprecision(1);
    int t=1;
    // cin>>t;
    while(t--){
       solve(); 
    }
 
    //cout<<"bh"<<endl;
    //solve();
    
    
        
    // TIME();
    return 0;
 
 
}
 
 