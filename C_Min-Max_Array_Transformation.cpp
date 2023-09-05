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
    int n;
    cin >> n;
    vector<ll> a(n),b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    vector<ll> dmin(n),dmax(n);
    int j=0;
    for(int i=0;i<n;i++){
        while((j<n)&&b[j]<a[i]){
            j++;
        }
        cout<<b[j]-a[i]<<" ";
    }
    cout<<endl;
    j=n-1;

    for(int i=n-1;i>=0;i--){
        // cout<<i<<" "<<j<<endl;
        dmax[i]=b[j]-a[i];
        while((j>0)&&(a[i]<b[j])){
            j--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<dmax[i]<<" ";
    }
    cout<<endl;
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
 