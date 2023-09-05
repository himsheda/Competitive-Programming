#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define pip pair<int,pii>
#define ppi pair<pii,int>
#define ppp pair<p,p> 
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
template <class T> void show(vector<pair<T, T>>&a) {trav(a) {cout << i.ff << ' ' << i.ss << endl;}}
template <class T> void show(pair<T, T>p) {cout << p.ff << ' ' << p.ss << endl;}
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
void dfs(int i,int &ans,vector<vector<int> > &adj,vector<int> &node,vector<int> &count,vector<int> &vis,vector<vector<int> > &left){
    // cout<<i<<endl;
    vis[i]=1;
    // if(sz(adj[i])==1)
    // left[i][node[i]]++;
    // else{
        
    // }
    for(int j:adj[i]){
        // cout<<j<<endl;
        if(!vis[j]){
            dfs(j,ans,adj,node,count,vis,left);
            ff(k,0,26){
                left[i][k]+=left[j][k];
            }
        }
    }
    left[i][node[i]]++;
    ff(k,0,26){
        ans+=left[i][k]*(count[k]-left[i][k]);
    }

}
void solve(){
    int n;
    cin>>n;
    vector<vector<int> > adj(n),left(n,vector<int> (26,0));
    vector<int> node(n),count(26,0),vis(n,0);
    ff(i,0,n){
        char c;
        cin>>c;
        node[i]=c-'a';
        count[node[i]]++;
    }
    
    ff(i,0,n-1){
        int x,y;
        cin>>x>>y;
        adj[x-1].pb(y-1);
        adj[y-1].pb(x-1);
    }
    // show(adj);
    int ans=0;
    dfs(0,ans,adj,node,count,vis,left);
    // show(left);
    cout<<2*ans<<endl;

    
}
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
 
 