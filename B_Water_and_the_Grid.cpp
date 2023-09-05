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
    int n,m;
    cin>>n>>m;
    vector<vector<char>> a(n,vector<char>(m));
    vector<vector<int>> dp(n,vector<int>(m,0));
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        if(a[i][0]=='.'){
            q.push({i,0});
            dp[i][0]=1;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i][m-1]=='.'){
            q.push({i,m-1});
            dp[i][m-1]=1;
        }
    }
    for(int i=0;i<m;i++){
        if(a[0][i]=='.'){
            q.push({0,i});
            dp[0][i]=1;
        }
    }
    for(int i=0;i<m;i++){
        if(a[n-1][i]=='.'){
            q.push({n-1,i});
            dp[n-1][i]=1;
        }
    }
    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int i=p.first+dx[k];
            int j=p.second+dy[k];
            if(i>=0 && i<n && j>=0 && j<m && a[i][j]=='.' && dp[i][j]==0){
                dp[i][j]=1;
                q.push({i,j});
            }
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dp[i][j]==0 && a[i][j]=='.'){
                count++;
            }
        }
    }
    cout<<count<<endl;
    

    
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
 
 