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
void solve(){
    int n;
    cin>>n;
    vector<int> mp(1001,0);
    // map<int,int> mp2;
    vector<int> arr(n);
    // vector<pair<int,int> > unique;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]=i+1;
        // mp2[i+1]=arr[i];
    }
    // vector<int> unqid;
    // for(int i=1;i<1001;i++){
    //     if(mp[i]>0){
    //         unqid.push_back(mp[i]);
    //     }
    // }
    // sort(unqid.begin(),unqid.end());
    // vector<int> uq(unqid.size());
    // for(int i=0;i<unqid.size();i++){
    //     uq[i]=mp2[unqid[i]];
    // }
    int ans=-1;
    for(int i=1;i<1001;i++){
        for(int j=1;j<1001;j++){
            if(mp[i]>0&&mp[j]>0&&__gcd(i,j)==1)
            ans=max(ans,mp[i]+mp[j]);
        }
    }
    // for(int i=0;i<uq.size();i++){
    //     for(int j=0;j<uq.size();j++){
    //         if(__gcd(uq[i],uq[j])==1){
    //             ans=max(unqid[i]+unqid[j],ans);
    //         }
    //     }
    // }
    cout<<ans<<endl;

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
 
 