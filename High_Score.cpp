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

const int INF = 9e17;
const int mod = 7+1e9;
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};
void init_code(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

void solve(){
    int n,m;
    cin>>n>>m;
    vi dis(n+1,-INF);
    vvi edges;
    vi vis(n+1,0);
    ff(i,0,m){
        int a,b,c;
        cin>>a>>b>>c;
        edges.pb({a,b,c});
        // indeg[b]++;
    }
    
    dis[1]=0;
    for(int i=0;i<n-1;i++){
        for(auto &a:edges){
            if(dis[a[0]]==-INF) continue;
            dis[a[1]]=max(dis[a[1]],a[2]+dis[a[0]]);
        }
    }
    for(auto &a:edges){
        if(dis[a[0]]==-INF) continue;
        if(a[2]+dis[a[0]]>dis[a[1]]){
            dis[a[1]]=max(dis[a[1]],a[2]+dis[a[0]]);
            vis[a[1]]=1;
        }    
    }
    ff(i,0,n+1){
        for(auto &a:edges){
            if(dis[a[0]]==-INF) continue;
            if(vis[a[0]]==1){
                vis[a[1]]=1;
            }
            if(a[2]+dis[a[0]]>dis[a[1]]){
                dis[a[1]]=max(dis[a[1]],a[2]+dis[a[0]]);
                
            }    
        }
    }
    // show(dis);
    // show(vis);
    if(vis[n]){
        cout<<-1<<endl;
        return;
    }
    if(dis[n]==-INF){
        cout<<-1<<endl;
    }
    else{
        cout<<dis[n]<<endl;
    }
    

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
 
 