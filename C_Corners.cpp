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
    
    ll n,m;
    cin>>n>>m;
    vector<vector<int> > arr(n+1,vector<int>(m+1,1));
    ll count=0;
    bool zero=0;
    for(ll i=0;i<n;i++){
       string s;
       cin>>s;
       for(ll j=0;j<m;j++){
            arr[i][j]=s[j]-'0';
            count+=arr[i][j];
       }
    }
    bool flag=1;
    if(count!=n*m)
    zero=1;
    for(int i=0;(i<n)&&flag;i++){
        for(int j=0;(j<m)&& flag;j++){
            int sum=arr[i][j]+arr[i][j+1]+arr[i+1][j]+arr[i+1][j+1];
            if(sum<=2)
            flag=0;
        }       
    }

    if(count==n*m){
        cout<<count-2<<endl;
    }
    else if(flag==0){
        cout<<count<<endl;
    }
    else{
        cout<<count-1<<endl;
    }
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
 