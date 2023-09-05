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
    int n,k;
    cin>>n>>k;
    vector<vector<int> > arr(n+1);
    vector<int> visit(n+1);
    int x;
    for(int i=0;i<n-1;i++){
        cin>>x;
        arr[x].push_back(i+2);
    }
    // for(auto a:arr){
    //     for(auto b:a){
    //         cout<<b<<" ";
    //     }
    //     cout<<endl;
    // }
    stack<vector<int> > s;
    priority_queue<int> pq;
    s.push({1,0});
    while(!s.empty()){
        auto t=s.top();
        s.pop();
        if(arr[t[0]].size()==0){
            pq.push(t[1]);
        }
        for(auto a:arr[t[0]]){
            s.push({a,t[1]+1});
        }
        // cout<<t[0]<<" "<<t[1]<<endl;
    }
    while(k--){
        int top=pq.top();
        pq.pop();
        pq.push(top/2);
        pq.push(top-(top/2));
    }
    cout<<pq.top()<<endl;
    

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
 
 