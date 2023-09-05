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
// const int N = 1e3+1;
// int a[N][N];
// int dp[N][N][10][10];

// void initRMQ(vector<vector<vvi>> &dp,vvi &a, int n, int m)
// {
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) dp[i][j][0][0] = a[i][j];
//     }
//     for (int p = 0; (1 << p) <= n; p++) {
//         for (int q = 0; (1 << q) <= m ; q++) {
//             if (p + q == 0) continue;
//             for (int i = 0; i + (1<<p)-1 < n; i++) {
//                 for (int j = 0; j + (1 << q) - 1 < m; j++) {
//                     if (p) dp[i][j][p][q] = max(dp[i][j][p - 1][q], dp[i + (1 << (p-1))][j][p - 1][q]);
//                     else dp[i][j][p][q] = max(dp[i][j][p][q-1], dp[i][j+(1<<(q-1))][p][q-1]);
//                 }
//             }
//         }
//     }
// }
 
 
// int askRMQ(vector<vector<vvi>> &dp,int x1, int y1, int x2, int y2) {
//     int x = 0, y = 0;
//     while ((1<<(x+1)) <= x2 - x1 + 1) x++;
//     while ((1<<(y+1)) <= y2 - y1 + 1) y++;
//     x2 = x2 - (1<<x) + 1;
//     y2 = y2 - (1<<y) + 1;
 
//       //printf("%d %d %d %d %d %d\n",x1,y1,x2,y2,x,y);
//     return max( max(dp[x1][y1][x][y], dp[x2][y1][x][y]), max(dp[x1][y2][x][y], dp[x2][y2][x][y]));
// }
int  sl(int l, int r, vector<vector<int>> &dp, vector<vector<int>> &p){
    if(l >= r){
        dp[l][r] =0;
        return 0;
    }
    if(r-l == 1){
        dp[l][r] = p[l][r];
        return p[l][r];
    }
    if(dp[l][r] != -1){
        return dp[l][r];
    }
    int ans =max(sl(l+1,r,dp,p), max(sl(l, r-1, dp,p), p[l][r]));
    dp[l][r] =ans;
    return ans;
}
    
void solve(){
    int n,q;
    cin>>n>>q;
    vector<vector<int>>fo(n+1,vector<int>(n+1));
    vector<vector<int>>ma(n+1, vector<int>(n+1));
    for(int i=0; i< ((n)*(n-1))/2 ; i++){
        int x,y,f;
        cin>>x>>y>>f;
        fo[x][y] = f;
        ma[x][y] = f*((x-y)*(x-y));
        // cout<<ma[x][y]<<endl;
    }
    vector<vector<int>>dpf(n+1, vector<int>(n+1,-1));
    vector<vector<int>>dpm(n+1, vector<int>(n+1, -1));
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<sl(l, r,  dpf, fo)<<" "<<sl(l, r, dpm, ma)<<endl;
    }
}
// void solve(){
//     int n, q;
//     cin>>n>>q;
//     int k=1+log2(n);
//     vvi a(n+1,vi(n+1));
//     // vector<vector<vvi>> dp(n,vector<vvi>(n,vvi(k,vi(k))));
//     vvi a2(n+1,vi(n+1));
//     // vector<vector<vvi>> dp2(n,vector<vvi>(n,vvi(k,vi(k))));
//     ff(i,0,n*(n-1)/2){
//         int x,y,v;
//         cin>>x>>y>>v;
//         a[x][y]=v;
//         a2[x][y]=v*(x-y)*(x-y);
//     }
//     // show(a);
//     // show(a2);
//     for(int i=n-1;i>0;i--){
//         for(int j=i+1;j<=n;j++){
//             a[i][j]=max({a[i][j-1],a[i+1][j],a[i][j]});
//             a2[i][j]=max({a2[i][j-1],a2[i+1][j],a2[i][j]});
//         }
//     }
//     // show(a);
//     // show(a2);
//     // initRMQ(dp,a,n,n);
//     // initRMQ(dp2,a2,n,n);
//     while(q--){
//         int x,y;
//         cin>>x>>y;
//         cout<<a[x][y]<<" "<<a2[x][y] <<endl;
//     }

// }

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
 
 