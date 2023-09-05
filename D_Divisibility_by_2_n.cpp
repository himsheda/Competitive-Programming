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
int vecsum(vector<int> &A,int a,int b){
    int sum=0;
    for(int i=a; i<=b; i++){
        sum+=A[i];
    }
    return sum;
}
void solve(){
    int n;
    cin>>n;
    int x;
    int count=0;
    for(int i=0; i<n; i++){
        cin>>x;
        while(x>0&&(x%2==0)){
            count++;
            x/=2;
        }

    }
    if(count>=n){
        cout<<0<<endl;
        return;
    }
    count=n-count;
    int ans=0;
    int len=log2(n)+1;
    vector<int> v(n+1,0);
    for(int i=1;i<=n;i++){
        int j=i;
        while(j>0&&(j%2==0)){
            v[i]++;
            j/=2;
        }
    }
    sort(v.begin(), v.end(),greater<int>());
    // cout<<count<<endl;
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }
    for(int i=0;i<=n;i++){
        count-=v[i];
        if(v[i]>0)
        ans++;
        if(count<=0){
            cout<<ans<<endl;
            return;
        }
    }
    

    cout<<-1<<endl;
    
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
 
 