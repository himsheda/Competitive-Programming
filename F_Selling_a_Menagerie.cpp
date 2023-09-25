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
void solve(){
    int n;
    cin>>n;
    vi a(n);
    take(a);
    vi c(n);
    take(c);
    vector<vector<pii>> graph(n+1);
    vi indeg(n+1,0);
    ff(i,0,n){
        graph[i+1].pb({2*c[i],a[i]});
        indeg[a[i]]++;
    }
    vector<int> ans;
    queue<int> q;
    vi vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            q.push(i);
            ans.pb(i);
            vis[i]=1;
        }
    }
    
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:graph[u]){
            indeg[v.S]--;
            if(indeg[v.S]==0){
                q.push(v.S);
                ans.pb(v.S);
                vis[v.S]=1;
            }
        }
    }
    ff(i,1,n+1){
        if(!vis[i]){
            vi cycle;
            int j=i;
            while(!vis[j]){
                cycle.pb(j);
                vis[j]=1;
                j=a[j-1];
            }
            int mn=INT_MAX;
            int ind=-1;
            ff(k,0,cycle.size()){
                if(c[cycle[k]-1]<mn){
                    mn=c[cycle[k]-1];
                    ind=k;
                }
            }
            ind++;
            // cout<<ind+1<<endl;
            ff(k,0,cycle.size()){
                ans.pb(cycle[(ind+k)%cycle.size()]);
            }

        }
    }
    show(ans);
}
int32_t main(){
    init_code();
    //cout << fixed << setprecision(1);
    int t=1;
    cin>>t;
    while(t--){
       solve(); 
    }
    // TIME();
    return 0;
}
 
 