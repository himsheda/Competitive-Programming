#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
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

// const int INF = 9e18;
// const int mod = 7+1e9;
 
void init_code(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

void tra(ll nd , vector<vector<pair<ll,ll>>> &gr,ll par, vector<ll>& nd_bl, vector<ll> &an){
    ll o =0;
    for(int i=0; i<gr[nd].size(); i++){
        if(gr[nd][i].first != par){
            tra(gr[nd][i].first, gr, nd, nd_bl,an );
            // ed[make_pair(nd, gr[nd][i])] = nd_bl[gr[nd][i]];
            // ed[make_pair(gr[nd][i], nd)] = nd_bl[gr[nd][i]];  
            an.push_back(nd_bl[gr[nd][i].first]*gr[nd][i].second);
            o = o +  nd_bl[gr[nd][i].first];
        }

    }
    nd_bl[nd] = o +1;
}
void solve(){
    ll n,c,u;
    cin>>n>>c>>u;

    vector<vector<pair<ll,ll>>>gr(n+1);
    // vector<pair<ll,ll>>ab;
    for(int i=0; i<n-1; i++){
        ll a,b,w;
        cin>>a>>b>>w;
        gr[a].push_back({b,w});
        gr[b].push_back({a,w});
        // m[make_pair(a,b)] = w;
        // m[make_pair(b,a)] =w;
        // ab.push_back(make_pair(a,b));
    }
    // vector<ll>vis(n+1);
    vector<ll>nd_bl(n+1);
    vector<ll>an;
    tra(u, gr, -1, nd_bl, an);
    sort(an.begin(), an.end(), greater<ll>());
    // reverse(an.begin(), an.end());
    ll ans=0;
    for(int i=c; i<an.size(); i++){
        ans =ans + an[i];
    }

    cout<<ans<<endl;

}
// int dfs(int i,int par,vector<vpi> &adj,priority_queue<int> &pq){
//     int count=1;
//     for(auto &a:adj[i]){
//         if(a.F!=par){
//             int x=dfs(a.F,i,adj,pq);
//             pq.push(a.S*x);
//             count+=x;
//         }
//     }
//     return count;
// }
// void solve(){
//     int n,c,u;
//     cin>>n>>c>>u;
//     vector<vpi> adj(n+1);
//     ff(i,0,n-1){
//         int a,b,w;
//         cin>>a>>b>>w;
//         adj[a].pb({b,w});
//         adj[b].pb({a,w});
//     }
//     priority_queue<int> pq;
//     for(auto &a:adj[u]){
//         int  x=dfs(a.F,u,adj,pq);
//         pq.push(a.S*x);
//     }
//     while(!pq.empty()&&c>0){
//         pq.pop();
//         c--;
//     }
//     int ans=0;
//     while(!pq.empty()){
//         ans+=pq.top();
//         pq.pop();
//     }
//     cout<<ans<<endl;
    
    
    
// }
int32_t main(){
    init_code();
    //cout << fixed << setprecision(1);
    int t=1;
    cin>>t;
    while(t--){
       solve(); 
    }
 
    //cout<<"bh"<<endl;
    //solve();
    
    
        
    // TIME();
    return 0;
 
 
}
 
 