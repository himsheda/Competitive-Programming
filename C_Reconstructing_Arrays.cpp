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
// int DP(int n,int m,int cost){
//     if(n==1){
//         if(cost==0){
//             return 1;
//         }
//         else{
//             return 0;
//         }
//     }
//     if(m==0) return 0;
//     int ans=0;
//     ff(i,1,m+1){
//         if(i<m){
//             if(cost>0)
//             ans=(ans+DP(n-1,i,cost-1))%mod;
//         }
//         else{
//             ans=(ans+DP(n-1,m,cost))%mod;
//         }
//     }
//     return ans;

// }
void solve(){
    int n;
    cin>>n;
    vi arr(n);
    take(arr);
    cin>>n;
    vi M(n);
    take(M);
    cin>>n;
    vi cost(n);
    take(cost);
    vector<vvi> dp(101,vvi(101,vi(51,0)));
    vector<vvi> dp2(101,vvi(101,vi(51,0)));
    ff(i,0,101){
        ff(j,0,101){
            ff(k,1,51){
                // cout<<i<<" "<<j<<" "<<k<<endl;
                if(i==0&&j==0){
                    dp[i][j][k]=1;
                    if(k==1)
                    dp2[i][j][k-1]=0;
                    else
                        dp2[i][j][k]=(dp2[i][j][k-1]+dp[i][j][k-1])%mod;
                }
                else if(i==0) continue;
                else{
                    if(j>0)
                    dp[i][j][k]=(dp2[i-1][j][k-1]+dp[i][j][k])%mod;
                    dp[i][j][k]=(dp[i][j][j] +(dp[i-1][j][k]*j)%mod)%mod;
                    dp2[i][j][k]=(dp2[i][j][k-1]+dp[i][j][k])%mod;
                }
            }
        }
    }
    // ff(i,0,101){
    //     show(dp[i] );
    // }
    ff(i,0,n){
        int ans=0;
        ff(j,1,M[i]+1){
            ans=(ans+dp[arr[i]-1][cost[i]][j])%mod;
            // cout<<dp[arr[i]][j][cost[i]]<<" ";
        }
        cout<<ans<<endl;
    }
    

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
 
 