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
    vector<string> arr(8);
    for(int i=0;i<8;i++){
        cin>>arr[i];
    }
    for(int i=0;i<8;i++){
        // char c=arr[i][0];
        bool flag=0;
        if(arr[i][0]=='R'){
            for(int j=1;j<8;j++){
                if(arr[i][j]!='R'){
                    flag=1;
                    break;
                }
            }
            if(!flag){
                cout<<"R"<<endl;
                return;
            }
        }
        
    }
    cout<<"B"<<endl;
    // for(int i=0;i<8;i++){
    //     // char c=arr[0][i];

    //     bool flag=0;
    //     if(arr[0][i]!='B'){
    //         for(int j=1;j<8;j++){
    //             if(arr[j][i]!='B'){
    //                 flag=1;
    //                 break;
    //             }
    //         }
    //         cout<<"Blue"<<flag <<endl;
    //         if(!flag){
    //             cout<<"B"<<endl;
    //             return;
    //         }
    //     }
            
    // }
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
 
 