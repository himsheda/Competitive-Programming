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
    int mx=-1e5;
    int mn=1e5;
    vector<int> arr(n);
    int mxind=-1,mnind=-1;
    int count1=0,count2=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        count1+=(arr[i]<0);
        count2+=(arr[i]>0);
        mx=max(mx,arr[i]);
        mn=min(mn,arr[i]);
        if(arr[i]==mx) mxind=i;
        if(arr[i]==mn) mnind=i;
    }
    vector<pair<int,int>> ans;
    int k=arr[mxind];
    if(mx>=abs(mn)){
        while(mx>0 && k<32){
            k*=2;
            count1++;
        }
    }
    else{
        k=arr[mnind];
        while(mn<0 && k>-32){
            k*=2;
            count2++;
        }
    }
    if(mn>=0){
        for(int i=1;i<n;i++){
            if(arr[i]<arr[i-1])
            {arr[i]+=arr[i-1];
            ans.push_back({i+1,i});}
        }
    }
    if(mx<=0){
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
            arr[i]+=arr[i+1];
            ans.push_back({i+1,i+2});}
        }
    }
    else {    
        // cout<<count1<<" "<<count2<<endl;
        if(count1<count2){
                while(mx>0 && arr[mxind]<32){
                    arr[mxind]*=2;
                    ans.push_back({mxind+1,mxind+1});
                }
                mx=arr[mxind];
                for(int i=0;i<n;i++){
                    if(arr[i]<0){
                    arr[i]+=mx;
                    ans.push_back({i+1,mxind+1});}
                }
            for(int i=1;i<n;i++){
                if(arr[i]<arr[i-1])
                {arr[i]+=arr[i-1];
                ans.push_back({i+1,i});}
            }
        }
        else{
            while(mn<0&&arr[mnind]>-32){
                arr[mnind]*=2;
                ans.push_back({mnind+1,mnind+1});
            }
            mn=arr[mnind];
            for(int i=0;i<n;i++){
                if(arr[i]>0){
                arr[i]+=mn;
                ans.push_back({i+1,mnind+1});}
            }
            
            for(int i=n-2;i>=0;i--){
                if(arr[i]>arr[i+1]){
                arr[i]+=arr[i+1];
                ans.push_back({i+1,i+2});}
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto x:ans){
        cout<<x.first<<" "<<x.second<<endl;
    }
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

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
 
 