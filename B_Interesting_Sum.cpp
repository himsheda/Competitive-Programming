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

void solve(){
    
    ll n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    ll mx1=INT_MIN;
    ll mn1=INT_MAX;
    ll mxi=0,mni=0;
    for(int i=0;i<n;i++){
        if(arr[i]>mx1){
            mx1=arr[i];
            mxi=i;
        }
        if(arr[i]<mn1){
            mn1=arr[i];
            mni=i;
        }
    }
    ll mx2=INT_MIN;
    ll mn2=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]>mx2&&i!=mxi){
            mx2=arr[i];
        }
        if(arr[i]<mn2&&i!=mni){
            mn2=arr[i];
        }
    }
    cout<<mx1+mx2-mn1-mn2<<endl;;
}

int main(){
    init_code();
    //cout << fixed << setprecision(1);
    ll t;
    cin>>t;
    while(t--){
       solve(); 
    }
 
    //cout<<"bh"<<endl;
    //solve();
    
    
        
    // TIME();
    return 0;
 
 
}
 