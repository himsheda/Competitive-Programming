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
    vector<ll> arr(n);
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }
    bool zero=0,nonzero=0;
    for(int i=0;i<n;i++){
        if(arr[i]%10==0||arr[i]%10==5)
        zero=1;
        else
        nonzero=1;
        if(zero&&nonzero){
            cout<<"No"<<endl;
            return;
        }
    }
    if(zero){
        if(arr[0]%10==5)
        arr[0]+=5;
        for(ll i=1;i<n;i++){
            if(arr[i]%10==5)
        }
    }

}

int main(){
    init_code();
    //cout << fixed << setprecision(1);
    ll t=1;
    // cin>>t;
    while(t--){
       solve(); 
    }
 
    //cout<<"bh"<<endl;
    //solve();
    
    
        
    // TIME();
    return 0;
 
 
}
 