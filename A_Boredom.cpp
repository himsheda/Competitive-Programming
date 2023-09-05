#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ll long long
#define endl '\n'
 
#define sz(a) ((ll)(a).size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define tr(c, it) for (auto it = (c).begin(); (it) != (c).end(); it++)
#define pres(c, val) ((c).find(val) != (c).end())      // for sets, multisets, maps etc.
#define cpres(c, val) (find((c).begin(), (c).end(), val) != (c).end()) // for others
 
#define pb push_back
#define fi first
#define se second
 
#define forf(i, a, b) for(ll i = (a);i < (b); i++)
#define forb(i, a, b) for(ll i = (b); i >= (a); i--)
#define fo(i, n) forf(i, 0, n)
#define fob(i, n) forb(i, 0, n - 1)
 
const ll INF = 9e18;
const ll mod = 7+1e9;
 
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
ll min(ll a,ll b){
    if(a < b) return a;
    return b;
}
ll max(ll a,ll b){
    if(a < b) return b;
    return a;
}
void solve(){
    int m,s;
    int n;
    cin>>n;
    vector<int>a(n);
    int i,j;
    for(i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    vector<pair<int,int>>v;
    i=0;
    while(i<n){
        j=i;
        i++;
        while(j<n&&a[i]==a[j]) i++;
        v.push_back({a[j],i-j});
    }
    n=v.size();
    vector<int>dp(n+2);
    dp[2]=v[0].fi*v[0].se;
    for(i=1;i<n;i++){
      int u;
      if(v[i].fi!=v[i-1].fi+1){
        u=v[i].fi*v[i].se+dp[i+1];
      }
      else u=v[i].fi*v[i].se+dp[i];
      int v=dp[i+1];
      dp[i+2]=max(u,v);
    }
    cout<<dp[n+1]<<'\n';
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
 