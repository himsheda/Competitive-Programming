#include <bits/stdc++.h>
using namespace std;
 
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
    
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<int>> arr(2*n+1);
    // cout<<arr.size()<<endl;
    stack<int> stk;
    for(int i=0;i<2*n;i++){
        if(s[i]=='('){
            if(stk.empty()){
                arr[0].push_back(i+1);
            }
            else{
                arr[stk.top()].push_back(i+1);
            }
            stk.push(i+1);
        }
        else{
            stk.pop();
        }
    }
    int ans=0;
    // cout<<"check"<<endl;
    // for(auto a: arr){
    //     for(auto b:a){
    //         cout<<b<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=0;i<2*n;i++){
        if(arr[i].size()!=0)
        ans++;
    }
    cout<<ans<<endl;;
    
}

int main(){
    init_code();
    //cout << fixed << setprecision(1);
    ll t=1;
    cin>>t;
    while(t--){
       solve(); 
    }
 
    //cout<<"bh"<<endl;
    //solve();
    
    
        
    // TIME();
    return 0;
 
 
}
 
 