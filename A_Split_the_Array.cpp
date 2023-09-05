#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define pip pair<int,pii>
#define ppi pair<pii,int>
#define ppp pair<p,p> 
#define vpi vector<pii>
#define vi vector<int>
#define vvi vector<vi>
#define trav(x) for(auto& i:x)
#define sz(a) ((int)(a).size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define tr(c, it) for (auto it = (c).begin(); (it) != (c).end(); it++)
#define pres(c, val) ((c).find(val) != (c).end())      // for sets, multisets, maps etc.
#define cpres(c, val) (find((c).begin(), (c).end(), val) != (c).end()) // for others
 
#define pb push_back
#define F first
#define S second
 
#define ff(i, a, b) for(int i = (a);i < (b); i++)
#define fb(i, a, b) for(int i = (b); i >= (a); i--)
#define fo(i, n) forf(i, 0, n)
#define fob(i, n) forb(i, 0, n - 1)
 
template <class T> void show(vector<vector<T>> &a) {for (auto &i : a) { for (T &j : i) cout << j << ' ' ; cout << endl; } }
template <class T> void show(vector<T> &a) {for (T i : a) cout << i << ' ' ; cout << endl; }
template <class T> void show(vector<pair<T, T>>&a) {trav(a) {cout << i.ff << ' ' << i.ss << endl;}}
template <class T> void show(pair<T, T>p) {cout << p.ff << ' ' << p.ss << endl;}
void show(vector<string>&a) {trav(a) cout << i << endl;}
template<class T> void take(vector<T>&a) {trav(a) cin >> i;}

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
    vi arr(n);
    take(arr);
    vi seive(1e6+1,0);
    ff(i,2,1e6+1){
        if(seive[i]==0){
            for(int j=i;j<=1e6;j+=i){
                seive[j]=i;
            }
        }
    }
    // show(seive);
    map<int,int> mp;
    vi dp(n,0);
    dp[0]=1;
    int x=arr[0];
    while(x>1){
        int y=seive[x];
        mp[y]=0;
        while(x%y==0){
            x/=y;
        }
    }
    ff(i,1,n){
        int x=arr[i];
        vi prime;
        while(x>1){
            int y=seive[x];
            prime.pb(y);
            while(x%y==0){
                x/=y;
            }
        }
        dp[i]=dp[i-1]+1;
        for(auto &a:prime){
            if(mp.find(a)!=mp.end()){
                dp[i]=min(dp[i],mp[a]+1);
                mp[a]=min(mp[a],dp[i-1]);
            }
            else{
                mp[a]=dp[i-1];
            }
        }

    }
    // show(dp);
    cout<<dp[n-1]<<endl;
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
 
 