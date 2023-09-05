#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n'
 
#define sz(a) ((int)(a).size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define tr(c, it) for (auto it = (c).begin(); (it) != (c).end(); it++)
#define pres(c, val) ((c).find(val) != (c).end())      // for sets, multisets, maps etc.
#define cpres(c, val) (find((c).begin(), (c).end(), val) != (c).end()) // for others
 
#define pb push_back
#define fi first
#define se second
 
#define forf(i, a, b) for(int i = (a);i < (b); i++)
#define forb(i, a, b) for(int i = (b); i >= (a); i--)
#define fo(i, n) forf(i, 0, n)
#define fob(i, n) forb(i, 0, n - 1)
 
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
int DP(int i,int v, vector<int> &arr,vector<vector<int>> &dp){
    if(dp[i][v]!=-1) return dp[i][v];
    int n=arr.size();
    if(i==n) return 0;
    if(i>v) return 0;
    if(v==n) return dp[i][v]=arr[i]+DP(i+1,v,arr,dp);
    int ans=0;
    int take=arr[i]+DP(i+1,v,arr,dp);
    int not_take=DP(i+1,min(v+arr[i],n),arr,dp);
    return dp[i][v]= max(take,not_take);
}
void solve(){
    int  n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    // for(int i=n;i>=0;i--){
    //     for(int v=n;v>=0;v--){
    //         if(i==n) dp[i][v]= 0;
    //         else if(i>v) dp[i][v]= 0;
    //         else if(v==n) dp[i][v]= arr[i]+dp[i+1][v];
    //         else {    int ans=0;
    //             int take=arr[i]+dp[i+1][v];
    //             int not_take=dp[i+1][min(v+arr[i],n)];
    //             dp[i][v]= max(take,not_take);
    //         }
    //     }
    // }
    cout<<DP(0,0,arr,dp)<<endl;

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
 
 