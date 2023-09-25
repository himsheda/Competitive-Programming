#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define pii pair<int,int>
#define pip pair<int,pii>
#define ppi pair<pii,int>
#define ppp pair<p,p> 
#define vpi vector<pii>
#define vppi vector<ppi>
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

const int INF = 9e15;
const int mod = 7+1e9;
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};
void init_code(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
void dfs(int i,vvi &adj,vi &vis){
    vis[i]=1;
    for(auto &a:adj[i]){
        if(!vis[a]){
            dfs(a,adj,vis);
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<pip> arr(m);
    vvi adj(n+1);
    ff(i,0,m){
        cin>>arr[i].F>>arr[i].S.F>>arr[i].S.S;
        adj[arr[i].F].pb(arr[i].S.F);
    }
    vi dis(n+1,0);
    vi par(n+1);
    ff(i,0,n-1){
        for(auto &a:arr){
            if(dis[a.S.F]>dis[a.F]+a.S.S){
                dis[a.S.F]=dis[a.F]+a.S.S;
                par[a.S.F]=a.F;
            }
        }
        // show(dis);
    }
    for(auto &a:arr){
        if(dis[a.S.F]>dis[a.F]+a.S.S){
            par[a.S.F]=a.F;
            int slow=par[a.S.F];
            int fast=par[par[a.S.F]];
            while(slow!=fast){
                slow=par[slow];
                fast=par[par[fast]];
            }
            vi ans;
            ans.pb(slow);
            fast=slow;
            slow=par[slow];
            
            while(slow!=fast){
                ans.pb(slow);
                slow=par[slow];
            }
            ans.pb(slow);
            cout<<"YES"<<endl;
            reverse(all(ans));
            show(ans);
            return;
        }
    }
    
    cout<<"NO"<<endl;

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
 
 