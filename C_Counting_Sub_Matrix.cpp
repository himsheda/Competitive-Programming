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
    vi seive(1e6+1,1);
    seive[0]=0;
    seive[1]=0;
    ff(i,2,1e6+1){
        if(seive[i]){
            for(int j=i*i;j<=1e6;j+=i){
                seive[j]=0;
            }
        }
    }
    int n;
    cin>>n;
    vector<vector<int> > dp(n,vector<int>(n,0));
    ff(i,0,n){
        ff(j,0,n){
            int x;
            cin>>x;
            dp[i][j]=seive[x];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            // If a[i][j] is equal to 0
            if (dp[i][j] == 0)
                continue;
            dp[i][j] = min(min(dp[i - 1][j],
                              dp[i][j - 1]),
                          dp[i - 1][j - 1])
                      + 1;
        }
    }
 
 int count=0;
    // Calculate the sum of the array
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            count += dp[i][j];
 
    cout<<count<<endl;;
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
 
 