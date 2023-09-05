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
    
    int n,m;
    cin>>n>>m;
    if(m<=n)
    cout<<n-m<<endl;
    else{
        queue<pair<int,int>> q;
        vector<int> mp(20000);
        q.push({n,0});
        // cout<<q.size()<<endl;
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            // cout<<t.first<<endl;
            if(t.first==m){
                cout<<t.second<<endl;
                return;
            }
            mp[t.first]=1;
            if(t.first*2<=2*m){
                if(2*t.first==m){
                    cout<<t.second+1<<endl;
                    return;
                }
                if(!mp[2*t.first]){
                    mp[2*t.first]=1;
                    q.push({2*t.first,t.second+1});
                }
            }
            if(t.first>1){
                if(t.first-1==m){
                    cout<<t.second+1<<endl;
                    return;
                }
                if(!mp[t.first-1]){
                    q.push({t.first-1,t.second+1});
                    mp[t.first- 1]=1;
                }
            }
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
 
 